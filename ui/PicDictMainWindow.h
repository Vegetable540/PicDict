#ifndef PICDICTMAINWINDOW_H
#define PICDICTMAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QCoreApplication>

#include "WordBook.h"
#include "MemoryService.h"
#include "MemoryForm.h"

namespace Ui {
class PicDictMainWindow;
}

class PicDictMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PicDictMainWindow(QWidget *parent = 0);
    ~PicDictMainWindow();

private slots:
    void on_actionSelectDir_triggered();

    void on_actionOpenWordBookFile_triggered();

    void on_actionSaveBookFile_triggered();

    void on_ptnStartLearn_clicked();

private:
    Ui::PicDictMainWindow *ui;
    QString m_sDictDir;
    QString m_sWordBookFileName;
    WordBook m_oWordBook;
    MemoryService m_oService;
    MemoryForm m_oMemoryForm;
    QSettings m_oConfig{QCoreApplication::applicationDirPath() + "/config/config.ini", QSettings::IniFormat};
};

#endif // PICDICTMAINWINDOW_H
