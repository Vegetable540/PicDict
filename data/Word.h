#ifndef WORD_H
#define WORD_H

#include <QJsonObject>

namespace WordConst
{
    extern QString c_sWord;
    extern QString c_sIsSimple;
    extern QString c_sLearnTimes;
    extern QString c_sRemenberTimes;
}

class Word
{
public:
    Word();

    void write(QJsonObject &obj);
    void read(const QJsonObject &obj);

    QString sWord;
    bool IsSimple = false;

    int LearnTimes = 0;
    int RemenberTimes = 0;
};

#endif // WORD_H
