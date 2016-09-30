#include "PicDictMainWindow.h"
#include "ui_PicDictMainWindow.h"

PicDictMainWindow::PicDictMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PicDictMainWindow)
{
    ui->setupUi(this);
}

PicDictMainWindow::~PicDictMainWindow()
{
    delete ui;
}
