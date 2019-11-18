#ifndef EDITORHELPER_H
#define EDITORHELPER_H
#include <QTextEdit>

class EditorHelper
{
public:
    EditorHelper();
    static void highLightCurrentLine(QTextEdit *editor, QColor lineColor);
    static void moveCursorToLine(QTextEdit *editor, int lineNum);
};

#endif // EDITORHELPER_H
