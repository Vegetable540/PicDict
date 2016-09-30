#include "PicDictMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("", 36));
    PicDictMainWindow w;
    w.showMaximized();

    return a.exec();
}
