#include "compilecontrol.h"
#include "statement.h"
#include "statementcreator.h"
#include "variable.h"
#include "token.h"
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

CompileControl::CompileControl()
{

}

CompileControl::~CompileControl()
{

}

bool CompileControl::compile(QString *inSrcTxt, QString *outCmplTxt, QString *errMsg, StatementList *stmtList, VHash *prgmVars){

    StatementCreator stmtCreator;
    int stmtIndex = 0; //statement index

    //parse;
    QStringList srcList = (*inSrcTxt).split(QRegExp("\n|\r\n|\r")); //split the source text into an array of lines

    *outCmplTxt = "[";
    for(int i = 0; i < srcList.length(); i++){
        QString line = srcList[i];
        if(line.count(":") > 1){
            // throw error
        }
        line.replace(QRegExp("[^\\S\\r\\n]+"), " "); //replace multiple spaces and tabs with a single space
        line.replace(" :",":");

        //ignore empty lines and comments
        if(line.trimmed().isEmpty() || line.startsWith("#"))
            continue;

        Token *tokens = new Token(line.split(" "));
        QString instr = tokens->getInstr();
        QString labelName = tokens->getLabel();

        if(tokens->length() > 4){
            //too many tokens
            qDebug() << "token length " << tokens->length();
            *errMsg = "too many arguments here";
            return false;
        }

        // create statements
        Statement *stmt = stmtCreator.Create(instr);

        if(stmt != nullptr){

            //inject program variable enviroment
            stmt->setEnviroment(prgmVars);

            //create labels if a statement has one
            if(Token::isValidIdentifierName(labelName)){
                if(prgmVars->contains(labelName)){
                    Identifier *id = prgmVars->get(labelName);
                    stmt->setLabel(id);
                    Label *label = dynamic_cast<Label*>(id);
                    label->setStatementIndex(stmtIndex);
                    //*errMsg = "Label "+labelName+" already defined";
                } else {
                    if(tokens->hasLabel()){
                        Identifier *label = new Label(labelName,stmtIndex);
                        prgmVars->insert(labelName, label);
                    }
                }
            } else {
                *errMsg = "invalid characters detected";
            }

            // compile statements
            if(stmt->compile(tokens, errMsg) == false)
                return false;

            generateJson(stmt,outCmplTxt);

            //list of statements
            stmtList->add(stmt);
            stmtIndex++;
        } else {
            *errMsg = "invalid statement detected";
            qDebug() << "error at " << line;
            // some error
            return false;
        }
        delete tokens;
    }

    *outCmplTxt = outCmplTxt->left((*outCmplTxt).lastIndexOf(QChar(','))); //remove trailing comma
    *outCmplTxt += "]";
    return true;
}

//json serialization
void CompileControl::generateJson(Statement* stmt, QString* jsonOut){
    QJsonObject jsonStmtObj;
    stmt->serialize(jsonStmtObj);
    QJsonDocument doc(jsonStmtObj);
    QString jsonString = doc.toJson(QJsonDocument::Indented);
    *jsonOut += jsonString + ",";
}
