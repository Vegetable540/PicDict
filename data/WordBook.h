#ifndef WORDBOOK_H
#define WORDBOOK_H

#include <QVector>
#include <QFile>

#include "Word.h"

namespace WordBookConst {
    extern QString c_sWordBook;
    extern QString c_sRemenberWords;
    extern QString c_sNewWords;
    extern QString c_sWordObj;
}

class WordBook
{
public:
    WordBook();
    ~WordBook();

    void loadFromPath(const QString &dictPath);

    void loadFromFile(const QString &wordBookFile);
    void saveToFile(const QString &wordBookFile);

    QVector<Word*> RemenberWords;
    QVector<Word*> NewWords;
    QString WordBookFile;

private:
    void read(const QJsonObject &obj);
    void write(QJsonObject &obj);

    void loadObjFromJsonArray(const QJsonArray &array, QVector<Word*> *wordsC);
    void saveObjToJsonArray(QVector<Word*> *wordsC, QJsonArray &array);

};

#endif // WORDBOOK_H
