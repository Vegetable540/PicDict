#ifndef MEMORYCONTROLFORM_H
#define MEMORYCONTROLFORM_H

#include <QWidget>

namespace Ui {
class MemoryControlForm;
}

class MemoryControlForm : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryControlForm(QWidget *parent = 0);
    ~MemoryControlForm();

Q_SIGNALS:
    void next();
    void iKnow();

private slots:
    void on_ptnNext_clicked();

    void on_ptnIKnow_clicked();

private:
    Ui::MemoryControlForm *ui;
};

#endif // MEMORYCONTROLFORM_H
