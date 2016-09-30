#include "MemoryService.h"

#include <QDir>
#include <QPixmap>
#include <QTimerEvent>

const QStringList c_oImgSuffix{"*.jpeg"};

MemoryService::MemoryService()
{
}

MemoryService::~MemoryService()
{
}

void MemoryService::initService(QString wordsDir, WordBook *wordBook)
{
    m_sWordsDir = wordsDir;
    m_pWordBook = wordBook;
}

QVector<Word *> MemoryService::getWords()
{
    for (int i = 0; i <= c_nMaxLearnOneTimes; ++i)
    {
        m_oCurLearnWords.push_back(m_pWordBook->NewWords[i]);
    }

    return m_oCurLearnWords;
}

WordDefs MemoryService::wordDefs(Word *word)
{
    WordDefs oWordDefs(word->sWord);
    oWordDefs.read(m_sWordsDir + QString("/%1/%1.json").arg(word->sWord));

    return oWordDefs;
}

QVector<QPixmap> MemoryService::wordPics(Word *word)
{
    QVector<QPixmap> oPics;
    QDir oDir(m_sWordsDir + "/" + word->sWord);

    for(auto img : oDir.entryInfoList(c_oImgSuffix, QDir::Files))
    {
        oPics.push_back(QPixmap(img.absoluteFilePath()));
    }

    return oPics;
}

void MemoryService::listenWord(Word *word)
{
    m_oWordPlayer.setMedia(QUrl::fromLocalFile(m_sWordsDir + QString("/%1/%1.mp3").arg(word->sWord)));
    m_oWordPlayer.setVolume(40);
    m_oWordPlayer.play();

    if (m_nWordPlayerId == 0)
    {
        m_nWordPlayerId = startTimer(500);
    }
}

void MemoryService::timerEvent(QTimerEvent *e)
{
    if (e->timerId() == m_nWordPlayerId)
    {
        m_oWordPlayer.play();
    }
    else
    {
        QObject::timerEvent(e);
    }
}
