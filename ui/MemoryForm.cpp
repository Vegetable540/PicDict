#include "MemoryForm.h"
#include "ui_MemoryForm.h"

#include <QLabel>

MemoryForm::MemoryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryForm)
{
    ui->setupUi(this);
    ui->wgtPics->setLayout(&m_oLayout);

    connect(ui->wgtControl, &MemoryControlForm::next, this, &MemoryForm::next);
}

MemoryForm::~MemoryForm()
{
    delete ui;
}

void MemoryForm::init(MemoryService *service)
{
    m_pService = service;
}

void MemoryForm::startLearn()
{
    next();
}

void MemoryForm::nextWord()
{
    if (m_nCurWord == c_nMaxLearnOneTimes)
    {
        m_oLearnWords = m_pService->getWords();
        m_nCurWord = 0;
    }
    else
    {
        m_nCurWord++;
    }

    Word *pCurWord = m_oLearnWords[m_nCurWord];
    ui->wgtDefsForm->loadWord(m_pService->wordDefs(pCurWord));
    m_oLayout.invalidate();

    int nRow = 0;
    int nCol = 0;

    for (auto &pic : m_pService->wordPics(pCurWord))
    {
        QLabel *pLbl = new QLabel();
        pLbl->setPixmap(pic);
        m_oLayout.addWidget(pLbl, nRow, nCol++, Qt::AlignCenter);

        if (nCol == 8)
        {
            nCol = 0;
            nRow++;
        }
    }

    m_pService->listenWord(pCurWord);
}

void MemoryForm::next()
{
    switch(m_enStep)
    {
    case Pic:
        nextWord();
        break;
    case Def:
        ui->wgtDefsForm->showDef();
        m_enStep = Pic;
        return;
    }

    m_enStep++;
}
