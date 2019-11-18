#include "editorhelper.h"
#include <QDebug>

EditorHelper::EditorHelper()
{

}
void EditorHelper::highLightCurrentLine(QTextEdit *editor, QColor lineColor)
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    {
        QTextEdit::ExtraSelection selection;

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = editor->textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    editor->setExtraSelections(extraSelections);
}
void EditorHelper::moveCursorToLine(QTextEdit *editor, int lineNum)
{
    if (lineNum != 0) {
        int currentLineNum = editor->textCursor().blockNumber()+1;
        //qDebug() << "Move cursor from" <<  currentLineNum << " to " << lineNum;
        if (lineNum != currentLineNum){
            QTextCursor textCursor = editor->textCursor();
            if (lineNum > currentLineNum) {
                textCursor.movePosition(QTextCursor::NextBlock, QTextCursor::MoveAnchor, (lineNum - currentLineNum));
            } else {
               textCursor.movePosition(QTextCursor::PreviousBlock, QTextCursor::MoveAnchor, (currentLineNum - lineNum));
            }
            editor->setTextCursor(textCursor);
        }
    }

}
