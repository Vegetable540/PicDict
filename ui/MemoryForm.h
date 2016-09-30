#ifndef MEMORYFORM_H
#define MEMORYFORM_H

#include <QWidget>
#include <QGridLayout>

#include "MemoryService.h"

namespace Ui {
class MemoryForm;
}

class MemoryForm : public QWidget
{
    enum MemoryStep
    {
        Pic,
        Def,
    };

    Q_OBJECT

public:
    explicit MemoryForm(QWidget *parent = 0);
    ~MemoryForm();

public:
    void init(MemoryService *service);
    void startLearn();

public slots:
    void next();

private:
    void nextWord();

private:
    Ui::MemoryForm *ui;
    MemoryService *m_pService;
    QVector<Word *> m_oLearnWords;
    int m_nCurWord = c_nMaxLearnOneTimes;
    QGridLayout m_oLayout;
    int m_enStep = 0;
};

#endif // MEMORYFORM_H
