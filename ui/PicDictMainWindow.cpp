#include "PicDictMainWindow.h"
#include "ui_PicDictMainWindow.h"

#include <QDir>
#include <QFileDialog>

#include <QDebug>

const QString c_sWordBookKey = "WordBook";
const QString c_sWordsDirKey = "WordsDir";

PicDictMainWindow::PicDictMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PicDictMainWindow)
{
    ui->setupUi(this);

    m_sDictDir = m_oConfig.value(c_sWordsDirKey).toString();
    m_sWordBookFileName = m_oConfig.value(c_sWordBookKey).toString();

    m_oService.initService(m_sDictDir, &m_oWordBook);
    m_oMemoryForm.init(&m_oService);

    on_actionOpenWordBookFile_triggered();
}

PicDictMainWindow::~PicDictMainWindow()
{
    delete ui;
}

void PicDictMainWindow::on_actionSelectDir_triggered()
{
    m_sDictDir = QFileDialog::getExistingDirectory(this);
//    m_oWordBook.loadFromPath(m_sDictDir);
}

void PicDictMainWindow::on_actionOpenWordBookFile_triggered()
{
//    m_oWordBook.loadFromFile(QFileDialog::getOpenFileName(this, QString(), m_oWordBook.WordBookFile));
    m_oWordBook.loadFromFile(m_sWordBookFileName);
    ui->lblTotalWordsNumValue->setText(QString::number(m_oWordBook.NewWords.size() + m_oWordBook.RemenberWords.size()));
    ui->lblRemainWordsNumValue->setText(QString::number(m_oWordBook.NewWords.size()));
}

void PicDictMainWindow::on_actionSaveBookFile_triggered()
{
    m_oWordBook.saveToFile(
                QFileDialog::getSaveFileName(this, QString(), m_oWordBook.WordBookFile));
}

void PicDictMainWindow::on_ptnStartLearn_clicked()
{
    m_oMemoryForm.startLearn();
    setCentralWidget(&m_oMemoryForm);
}
