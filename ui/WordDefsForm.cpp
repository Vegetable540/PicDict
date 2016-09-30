#include "WordDefsForm.h"
#include "ui_WordDefsForm.h"

WordDefsForm::WordDefsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordDefsForm)
{
    ui->setupUi(this);
}

WordDefsForm::~WordDefsForm()
{
    delete ui;
}

void WordDefsForm::loadWord(const WordDefs &def)
{
    ui->lblWord->setText(def.Word);
    m_oDefs = def;

    for (QLabel *lbl : m_oDefC)
    {
        ui->verticalLayout->removeWidget(lbl);
        delete lbl;
    }
    m_oDefC.clear();
}

void WordDefsForm::showDef()
{

    for (WordDef def : m_oDefs.Defs)
    {
        QLabel *pLbl = new QLabel(def.Pos + def.Def);
        ui->verticalLayout->addWidget(pLbl);
        m_oDefC.push_back(pLbl);
    }
}
