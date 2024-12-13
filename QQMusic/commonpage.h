#ifndef COMMONPAGE_H
#define COMMONPAGE_H

#include <QWidget>
#include <QMediaPlaylist>
#include "musiclist.h"
namespace Ui {
class CommonPage;
}

enum PageType
{
    LIKE_PAGE,
    LOCAL_PAGE,
    HISTORY_PAGE
};

class CommonPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommonPage(QWidget *parent = nullptr);
    ~CommonPage();
    void setMusicListType(PageType pageType);
    void setCommonPageUI(const QString &title,const QString &image);
    void addMusicToMusicPage(MusicList& musicList);
    void reFresh(MusicList& musicList);
    void addMusicToPlayer(MusicList& musicList,QMediaPlaylist *playList);
    QString getMusicIdByIndex(int index);
    void setImageLabel(QPixmap pixMap);
private:
    Ui::CommonPage *ui;
    PageType pageType;
    QVector<QString> musicOfPage;
signals:
    void updateLikeMusic(bool isLike,QString musicId);
    void playAll(PageType pageType);
    void playMusicByIndex(CommonPage*,int);
};

#endif // COMMONPAGE_H
