#include "Word.h"

namespace WordConst
{
    QString c_sWord = "Word";
    QString c_sIsSimple = "IsSimple";
    QString c_sLearnTimes = "LearnTimes";
    QString c_sRemenberTimes = "RemenberTimes";
}

Word::Word()
{

}

void Word::write(QJsonObject &obj)
{
    using namespace WordConst;
    obj[c_sWord] = sWord;
    obj[c_sIsSimple] = IsSimple;
    obj[c_sLearnTimes] = LearnTimes;
    obj[c_sRemenberTimes] = RemenberTimes;
}

void Word::read(const QJsonObject &obj)
{
    using namespace WordConst;
    sWord = obj[c_sWord].toString();
    IsSimple = obj[c_sIsSimple].toInt();
    LearnTimes = obj[c_sLearnTimes].toInt();
    RemenberTimes = obj[c_sRemenberTimes].toInt();
}
