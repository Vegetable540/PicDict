#ifndef WORDDEFSFORM_H
#define WORDDEFSFORM_H

#include <QWidget>
#include <QLabel>

#include "WordDef.h"

namespace Ui {
class WordDefsForm;
}

class WordDefsForm : public QWidget
{
    Q_OBJECT

public:
    explicit WordDefsForm(QWidget *parent = 0);
    ~WordDefsForm();

public:
    void loadWord(const WordDefs &def);
    void showDef();

private:
    Ui::WordDefsForm *ui;
    WordDefs m_oDefs;
    QVector<QLabel*> m_oDefC;
};

#endif // WORDDEFSFORM_H
