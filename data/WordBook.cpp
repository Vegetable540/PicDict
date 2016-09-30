#include "WordBook.h"

#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDateTime>
#include <QDebug>

namespace WordBookConst
{
    QString c_sWordBook = "WordBook";
    QString c_sRemenberWords = "RemenberWords";
    QString c_sNewWords = "NewWords";
    QString c_sWordObj = "WordObj";
}

WordBook::WordBook()
{

}

WordBook::~WordBook()
{
    qDeleteAll(RemenberWords);
    qDeleteAll(NewWords);
}

void WordBook::loadFromPath(const QString &dictPath)
{
    QVector<Word*> oNewWords;
    QDir oDictDirs(dictPath);
    for (QString dir : oDictDirs.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        Word *pNewWord = new Word();
        pNewWord->sWord = dir;

        oNewWords.push_back(pNewWord);
    }

    QVector<QPair<int, int> > oNumbers;
    for (int i = 0; i < oNewWords.size(); ++i)
    {
        oNumbers.push_back(QPair<int, int>(i, rand()));
    }

    qSort(oNumbers.begin(), oNumbers.end(),
          [&](const QPair<int, int> &a, const QPair<int, int> &b) -> bool{
        return a.second < b.second;
    });

    for (const QPair<int, int> &num : oNumbers)
    {
        NewWords.push_back(oNewWords[num.first]);
    }
}

void WordBook::loadFromFile(const QString &wordBookFile)
{
    WordBookFile = wordBookFile;

    QFile oWordBookFile(WordBookFile);

    if (!oWordBookFile.open(QIODevice::ReadOnly))
    {
        qWarning() << oWordBookFile.errorString();
        return;
    }

    QByteArray oResult = oWordBookFile.readAll();
    QJsonDocument oDoc = QJsonDocument::fromJson(oResult);

    QJsonObject oObj = oDoc.object();
    read(oObj);

    oWordBookFile.close();
}

void WordBook::saveToFile(const QString &wordBookFile)
{
    QJsonDocument oDoc;
    QJsonObject oObj;
    write(oObj);

    oDoc.setObject(oObj);

    QDir oDir = QFileInfo(wordBookFile).dir();

    QFile oBackupFile(oDir.absolutePath() + "/" + QString("%1.backup").arg(QDateTime::currentMSecsSinceEpoch()));
    if (!oBackupFile.open(QIODevice::WriteOnly))
    {
        qWarning() << oBackupFile.errorString();
        return;
    }

    QByteArray oJson = oDoc.toJson();
    if (-1 == oBackupFile.write(oJson))
    {
        qWarning() << oBackupFile.errorString();
        return;
    }

    QFile oWordBookFile(wordBookFile);

    if (!oWordBookFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qWarning() << oWordBookFile.errorString();
    }

    oWordBookFile.write(oDoc.toJson());
    oWordBookFile.close();
}

void WordBook::read(const QJsonObject &obj)
{
    using namespace WordBookConst;

    QJsonArray oNewWords = obj[c_sNewWords].toArray();
    loadObjFromJsonArray(oNewWords, &NewWords);

    QJsonArray oRemenberWords = obj[c_sRemenberWords].toArray();
    loadObjFromJsonArray(oRemenberWords, &RemenberWords);
}

void WordBook::write(QJsonObject &obj)
{
    using namespace WordBookConst;

    QJsonArray oNewWords;
    saveObjToJsonArray(&NewWords, oNewWords);

    QJsonArray oRemenberWords;
    saveObjToJsonArray(&RemenberWords, oRemenberWords);

    obj[c_sNewWords] = oNewWords;
    obj[c_sRemenberWords] = oRemenberWords;
}

void WordBook::loadObjFromJsonArray(const QJsonArray &array, QVector<Word *> *wordsC)
{
    for (auto oIte = array.begin(); oIte != array.end(); ++oIte)
    {
        Word *pWord = new Word();
        pWord->read((*oIte).toObject());

        wordsC->push_back(pWord);
    }
}

void WordBook::saveObjToJsonArray(QVector<Word *> *wordsC, QJsonArray &array)
{
    for (Word *pWord : *wordsC)
    {
        QJsonObject oObj;
        pWord->write(oObj);
        array.push_back(oObj);
    }
}
