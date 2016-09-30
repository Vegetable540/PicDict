#ifndef MEMORYSERVICE_H
#define MEMORYSERVICE_H

#include <QMediaPlayer>

#include "WordDef.h"
#include "WordBook.h"

const int c_nMaxLearnOneTimes = 7;

class MemoryService : public QObject
{
    Q_OBJECT
public:
    MemoryService();
    ~MemoryService();

public:
    void initService(QString wordsDir, WordBook *wordBook);
    QVector<Word*> getWords();

    WordDefs wordDefs(Word *word);
    QVector<QPixmap> wordPics(Word *word);

    void listenWord(Word *word);

protected:
    void timerEvent(QTimerEvent *e);

private:
    WordBook *m_pWordBook = nullptr;
    QString m_sWordsDir;
    QVector<Word *> m_oCurLearnWords;
    QMediaPlayer m_oWordPlayer;

    int m_nWordPlayerId = 0;
};

#endif // MEMORYSERVICE_H
