#ifndef MUSICLIST_H
#define MUSICLIST_H
#include <QVector>
#include <QUrl>
#include "music.h"
#include <QSet>
typedef typename QVector<Music>::iterator iterator;
class MusicList
{
public:
    MusicList();
    void addMusicByUrl(const QList<QUrl>& urls);
    iterator findMusicByMusicId(const QString &musicId);
    iterator begin();
    iterator end();
    void writeToDB();
    void readFromDB();
private:
    QVector<Music> musicList;
    QSet<QString> musicPaths;
};

#endif // MUSICLIST_H
