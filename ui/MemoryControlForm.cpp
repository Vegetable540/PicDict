#include "MemoryControlForm.h"
#include "ui_MemoryControlForm.h"

MemoryControlForm::MemoryControlForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryControlForm)
{
    ui->setupUi(this);
}

MemoryControlForm::~MemoryControlForm()
{
    delete ui;
}

void MemoryControlForm::on_ptnNext_clicked()
{
    emit next();
}

void MemoryControlForm::on_ptnIKnow_clicked()
{
    emit iKnow();
}
