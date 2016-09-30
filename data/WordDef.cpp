#include "WordDef.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

namespace WordDefConst {
    QString c_sDefs = "defs";
    QString c_sPos = "pos";
    QString c_sDef = "def";
}

WordDef::WordDef()
{

}

void WordDef::read(const QJsonObject &obj)
{
    using namespace WordDefConst;

    Pos = obj[c_sPos].toString();
    Def = obj[c_sDef].toString();
}

WordDefs::WordDefs(const QString &word)
    : Word(word)
{

}

void WordDefs::read(const QString &jsonObjFile)
{
    QFile oFile(jsonObjFile);
    if (!oFile.open(QFile::ReadOnly))
    {
        qWarning() << "read" << jsonObjFile << "error";
    }

    QJsonDocument oDoc = QJsonDocument::fromJson(oFile.readAll());
    QJsonArray oDefs = oDoc.object()[WordDefConst::c_sDefs].toArray();
    for (auto oIte = oDefs.begin(); oIte != oDefs.end(); ++oIte)
    {
        WordDef oDef;
        oDef.read((*oIte).toObject());
        Defs.push_back(oDef);
    }
}
