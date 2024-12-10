#include "musiclist.h"
#include <QMimeDatabase>
#include <QMimeType>
MusicList::MusicList() {}

void MusicList::addMusicByUrl(const QList<QUrl> &urls)
{
    for(auto musicUrl:urls)
    {
        QMimeDatabase db;
        QMimeType mime=db.mimeTypeForFile(musicUrl.toLocalFile());
        if(mime.name()!="audio/mpeg"&&mime.name()!="audio/flac")
        {
            continue;
        }
        musicList.push_back(musicUrl);
    }
}

iterator MusicList::findMusicByMusicId(const QString &musicId)
{
    for(auto music:musicList)
    {
        if(music.getMusicId()==musicId)
        {
            return music;
        }
    }
    return end();
}

iterator MusicList::begin()
{
    return musicList.begin();
}

iterator MusicList::end()
{
    return musicList.end();
}
