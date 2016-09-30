#ifndef PICDICTMAINWINDOW_H
#define PICDICTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class PicDictMainWindow;
}

class PicDictMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PicDictMainWindow(QWidget *parent = 0);
    ~PicDictMainWindow();

private:
    Ui::PicDictMainWindow *ui;
};

#endif // PICDICTMAINWINDOW_H
