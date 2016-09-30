#ifndef WORDDEF_H
#define WORDDEF_H

#include <QString>
#include <QJsonObject>
#include <QVector>

namespace WordDefConst {
    extern QString c_sDefs;
    extern QString c_sPos;
    extern QString c_sDef;
}

class WordDef
{
public:
    WordDef();

public:
    void read(const QJsonObject &obj);

public:
    QString Pos;
    QString Def;
};

class WordDefs
{
public:
    WordDefs(){}
    WordDefs(const QString &word);

    void read(const QString &jsonObjFile);

public:
    QString Word;
    QVector<WordDef> Defs;
};

#endif // WORDDEF_H
