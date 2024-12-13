#include "music.h"
#include <QUuid>
#include <QCoreApplication>
#include <QMediaPlayer>
#include <QSqlQuery>
#include <QSqlError>
Music::Music()
    : isLike(false)
    , isHistory(false)
{}
Music::Music(const QUrl &url)
    : isLike(false)
    , isHistory(false)
    , musicUrl(url)
{
    musicId = QUuid::createUuid().toString();
    parseMediaMetaData();
}
void Music::setIsLike(bool isLike)
{
    this->isLike = isLike;
}
void Music::setIsHistory(bool isHistory)
{
    this->isHistory = isHistory;
}
void Music::setMusicName(const QString &musicName)
{
    this->musicName = musicName;
}
void Music::setSingerName(const QString &singerName)
{
    this->singerName = singerName;
}
void Music::setAlbumName(const QString &albumName)
{
    this->albumName = albumName;
}
void Music::setDuration(const qint64 duration)
{
    this->duration = duration;
}
void Music::setMusicUrl(const QUrl &url)
{
    this->musicUrl = url;
}
void Music::setMusicId(const QString &musicId)
{
    this->musicId = musicId;
}
bool Music::getIsLike()
{
    return isLike;
}
bool Music::getIsHistory()
{
    return isHistory;
}
QString Music::getMusicName()
{
    return musicName;
}
QString Music::getSingerName()
{
    return singerName;
}
QString Music::getAlbumName()
{
    return albumName;
}
qint64 Music::getDuration()
{
    return duration;
}
QUrl Music::getMusicUrl()
{
    return musicUrl;
}
QString Music::getMusicId()
{
    return musicId;
}

QString Music::getLrcFilePath() const
{
    QString path=musicUrl.toLocalFile();
    path.replace(".mp3",".lrc");
    path.replace(".flac",".lrc");
    path.replace(".mpga",".lrc");
    return path;
}

void Music::insertMusicToDB()
{
    QSqlQuery query;
    query.prepare("SELECT EXISTS (SELECT 1 FROM MusicInfo WHERE musicId = ?)");
    query.addBindValue(musicId);
    if(!query.exec())
    {
        qDebug()<<"查询失败: "<<query.lastError().text();
        return;
    }
    if(query.next())
    {
        bool isExists=query.value(0).toBool();
        if(isExists)
        {
            query.prepare("UPDATE MusicInfo SET isLike = ?, isHistory = ? WHERE musicId = ?");
            query.addBindValue(isLike? 1 : 0);
            query.addBindValue(isHistory? 1 : 0);
            query.addBindValue(musicId);
            if(!query.exec())
            {
                qDebug()<<"更新失败: "<<query.lastError().text();
            }
            qDebug()<<"更新music信息: "<<musicName<<" "<<musicId;
        }
        else
        {
            query.prepare(("INSERT INTO MusicInfo(musicId, musicName,musicSinger, albumName, musicUrl,\
            duration, isLike, isHistory)\
            VALUES(?,?,?,?,?,?,?,?)"));
            query.addBindValue(musicId);
            query.addBindValue(musicName);
            query.addBindValue(singerName);
            query.addBindValue(albumName);
            query.addBindValue(musicUrl.toLocalFile());
            query.addBindValue(duration);
            query.addBindValue(isLike ? 1 : 0);
            query.addBindValue(isHistory? 1 : 0);
            if(!query.exec())
            {
                qDebug()<<"插入失败: "<<query.lastError().text();
                return;
            }
            qDebug()<<"插入music信息: "<<musicName<<" "<<musicId;
        }
    }
}
void Music::parseMediaMetaData()
{
    QMediaPlayer player;
    player.setMedia(musicUrl);
    while(!player.isMetaDataAvailable())
    {
        QCoreApplication::processEvents();
    }
    if(player.isMetaDataAvailable())
    {
        musicName = player.metaData("Title").toString();
        singerName = player.metaData("Author").toString();
        albumName = player.metaData("AlbumTitle").toString();
        duration = player.duration();
        QString fileName=musicUrl.fileName();
        int index=fileName.indexOf('-');
        if(musicName.isEmpty())
        {
            if(index!=-1)
            {
                musicName = fileName.mid(0, index).trimmed();
            }
            else
            {
                musicName = fileName.mid(0, fileName.indexOf('.')).trimmed();
            }
        }
        if(singerName.isEmpty())
        {
            if(index!=-1)
            {
                singerName = fileName.mid(index+1, fileName.indexOf('.')-index-1).trimmed();
            }
            else
            {
                singerName = "歌手未知";
            }
        }
        if(albumName.isEmpty())
        {
            albumName = "专辑名未知";
        }
        qDebug()<<musicName<<" "<<singerName<<" "<<albumName<<" "<<duration;
    }
}
