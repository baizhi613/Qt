#ifndef MUSICLIST_H
#define MUSICLIST_H
#include <QVector>
#include <QUrl>
#include "music.h"
typedef typename QVector<Music>::iterator iterator;
class MusicList
{
public:
    MusicList();
    void addMusicByUrl(const QList<QUrl>& urls);
    iterator findMusicByMusicId(const QString &musicId);
    iterator begin();
    iterator end();
private:
    QVector<Music> musicList;
};

#endif // MUSICLIST_H
