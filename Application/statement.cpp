#include "statement.h"
#include "arrayvariable.h"
#include "integerliteral.h"
#include "stringliteral.h"
#include "arrayelementindex.h"

Statement::Statement(){}

Statement::~Statement()
{
    delete op1;
    delete op2;
}

void Statement::setLabel(Identifier *label)
{
    this->label = label;
}

bool Statement::hasLabel(){
    return (label == nullptr) ? false : true;
}

//do some additional validation on arguments & label names
void Statement::validate(int numArgs, Token *tokens){

    if(tokens->length() > numArgs+1){
        error = "too many arguments";
        throw std::logic_error(error.toUtf8());
    }

    if(tokens->length() <= numArgs){
        error = "missing arguments";
        throw std::logic_error(error.toUtf8());
    }

    // Check the identifier for invalid characters
    for(int i = 1; i <= numArgs; i++){
        QString arg = tokens->getArg(i);
        if(Token::isStringLiteral(arg)){
            if(tokens->getInstr() != "prt"){
                error = "strings are not supported with " + tokens->getInstr();
                throw std::logic_error(error.toUtf8());
            }
        }else if(!Token::isValidIdentifierName(arg)){ // Check the label for invalid characters
            error = "invalid characters detected";
            throw std::logic_error(error.toUtf8());
        }
    }

    //validate label
    if(tokens->hasLabel()){
        QString labelName = tokens->getLabel();

        if(!Token::isValidIdentifierName(labelName)){
            error = "invalid characters detected";
            throw std::logic_error(error.toUtf8());
        }

        if(numArgs >= 1 && labelName == tokens->getArg1()){
            error = "label already defined: " +labelName;
            throw std::logic_error(error.toUtf8());
        }

        if(numArgs == 2 && labelName == tokens->getArg2()){
            error = "label already defined: " +labelName;
            throw std::logic_error(error.toUtf8());
        }

        if( !(label = env->get(labelName)) ){
            error = "undefined reference to identifier/label: " +labelName;
            throw std::logic_error(error.toUtf8());
        }

    }

}

//create label if a statement has one or update the reference if label was already created
void Statement::updateLabel(Token *tokens){
    Identifier *id = nullptr;
    if(tokens->hasLabel()){
        QString labelName = tokens->getLabel();
        if( (id = env->get(labelName)) ){
            if(!id->isLabel()){
                error = "not a label";
                throw std::logic_error(error.toUtf8());
            }
            Label *label = dynamic_cast<Label*>(id);
            if(!label->isInitialized()){
                label->setValue(env->getJmpIndex());
            } else {
                error = "label already declared at index " + QString::number(label->getValue());
                throw std::logic_error(error.toUtf8());
            }
        } else {
            Label *label = new Label(labelName,env->getJmpIndex());
            label->initialize();
            env->insert(labelName, label);
        }
    }
}

//update operand references
void Statement::updateOperands(int numArgs, Token *tokens){
    int literalsDetected = 0;
    for(int i = 1; i <= numArgs; i++){
        QString arg = tokens->getArg(i);

        //extra processing for $array accessors
        //int arrayIndex = 0;
        bool arrayDetected = false;
        if(Token::isArrayElement(arg)){
            arrayDetected = true;
            arg = arg.split("+")[0].remove("$"); //strip $ to get array name
            //QString tmp = arg.split("+")[1]; //split + and get array index
            //arrayIndex = tmp.toInt();
            //arg = str;
        }

        if(env->contains(arg)){  // Check if the identifier is real or not
            Identifier *var;
            if(arrayDetected){

                if(!env->get(arg)->isArray()){
                    error = "identifier is not an array: "+ arg;
                    throw std::logic_error(error.toUtf8());
                }

                var = new ArrayElementIndex(tokens->getArg(i));
                if(i==1)
                    op1 = new Operand(var);
                if(i==2)
                    op2 = new Operand(var);

                QString accessor = tokens->getArg(i).split("+")[1]; //split + and get array index

                if(!Token::isIntegerLiteral(accessor)){
                    Identifier *tmp;
                    if( (tmp = env->find(accessor)) ){
                        ArrayElementIndex *ele = dynamic_cast<ArrayElementIndex*>(var); //casting needed to call array member function to set index
                        ele->setVariable(tmp);
                    } else {
                        error = "undefined reference to identifier: " + accessor;
                        throw std::logic_error(error.toUtf8());
                    }
                }

            } else {
                var = env->get(arg);
                if(i==1)
                    op1 = new Operand(var);
                if(i==2)
                    op2 = new Operand(var);
            }
        } else{
            QString literalType;
            if(Token::isLiteral(arg, literalType)){
                Identifier *literal = IdentifierCreator::create(literalType, arg);
                env->insert(arg, literal);
                if(i==1)
                    op1 = new Operand(literal);
                if(i==2)
                    op2 = new Operand(literal);
                literalsDetected++;
            } else if(tokens->getInstr() == "jmp" || tokens->getInstr() == "jmr" || tokens->getInstr() == "jls" || tokens->getInstr() == "jeq") {
                //set create labels for jumps if they dont exist
                Identifier *id = new Label(arg);
                op1 = new Operand(id);
                env->insert(arg,id);
            } else {
                error = "undefined reference to identifier: " + arg;
                throw std::logic_error(error.toUtf8());
            }
        }
    }

    if(literalsDetected > 1){ // only 1 literal allowed
        error = "too many literals detected";
        throw std::logic_error(error.toUtf8());
    }
}

//
Token* Statement::tokenize(const QJsonObject &json){

    QString label = "";
    QString arg1 = "";
    QString arg2 = "";
    QString instr = json["statement"].toString();

    if(json.contains("label")){
        label = json["label"].toString();
    }
    if(json.contains("op1")){
        QJsonObject jsonOp1 = json["op1"].toObject();
        arg1 = jsonOp1["name"].toString();
        QString arg1Type = jsonOp1["identifierType"].toString();
        if( arg1Type == "StringLiteral"){
            arg1 = "\""+arg1+"\"";
            qDebug() << arg1;
        }
    }
    if(json.contains("op2")){
        QJsonObject jsonOp2 = json["op2"].toObject();
        arg2 = jsonOp2["name"].toString();
    }

    if(!label.isEmpty()){
        label = label+":";
    }
    QString line = (label + " " + instr + " " + arg1 + " " + arg2).trimmed();
    line.replace(QRegExp("[^\\S\\r\\n]+"), " ");
    return new Token(line);
}

//injects program enviroment
void Statement::setEnviroment(ProgramEnviroment *env){
    this->env = env;
}

int Statement::getLineNumber(){
    return lineNumber;
}

void Statement::setLineNumber(int n){
    lineNumber = n;
}
