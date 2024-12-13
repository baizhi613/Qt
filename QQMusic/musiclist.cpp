#include "musiclist.h"
#include <QMimeDatabase>
#include <QMimeType>
#include <QSqlQuery>
#include <QSqlError>
MusicList::MusicList() {}

void MusicList::addMusicByUrl(const QList<QUrl> &urls)
{
    for(auto musicUrl:urls)
    {
        QString musicPath=musicUrl.toLocalFile();
        if(musicPaths.contains(musicPath))
            continue;
        musicPaths.insert(musicPath);
        QMimeDatabase db;
        QMimeType mimeType=db.mimeTypeForFile(musicUrl.toLocalFile());
        QString mime=mimeType.name();
        if(mime=="audio/mpeg"||mime=="audio/flac"||mime=="audio/wav")
        {
            Music music(musicUrl);
            musicList.push_back(music);
        }
    }
}

iterator MusicList::findMusicByMusicId(const QString &musicId)
{
    for(auto it=begin();it!=end();++it)
    {
        if(it->getMusicId()==musicId)
        {
            return it;
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

void MusicList::writeToDB()
{
    for(auto music:musicList)
    {
        music.insertMusicToDB();
    }
}

void MusicList::readFromDB()
{
    QString sql("SELECT musicId, musicName, musicSinger, albumName,\
    duration, musicUrl, isLike, isHistory \
    FROM musicInfo");
    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug()<<"数据库查询失败";
        return;
    }
    while(query.next())
    {
        Music music;
        music.setMusicId(query.value(0).toString());
        music.setMusicName(query.value(1).toString());
        music.setSingerName(query.value(2).toString());
        music.setAlbumName(query.value(3).toString());
        music.setDuration(query.value(4).toLongLong());
        music.setMusicUrl("file:///"+query.value(4).toString());
        music.setIsLike(query.value(6).toBool());
        music.setIsHistory(query.value(7).toBool());
        musicList.push_back(music);
        musicPaths.insert(music.getMusicUrl().toLocalFile());
    }
}
