#ifndef QQMUSIC_H
#define QQMUSIC_H

#include <QWidget>
#include "volumetool.h"
#include "musiclist.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "commonpage.h"
#include "lrcpage.h"
#include <QPropertyAnimation>
#include <QSqlDatabase>
QT_BEGIN_NAMESPACE
namespace Ui {
class QQMusic;
}
QT_END_NAMESPACE

class QQMusic : public QWidget
{
    Q_OBJECT

public:
    QQMusic(QWidget *parent = nullptr);
    ~QQMusic();
    void initUI();

    QJsonArray randomPiction();

    void connectSignalAndSlots();

    void initPlayer();

    void initSQLite();

    void initMusicList();
protected:
    // 重写QWidget类的鼠标单击和鼠标滚轮事件
    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent* event)override;
private slots:
    void on_quit_clicked();

    void onBtFormClick(int pageId);

    void on_volume_clicked();

    void on_addLocal_clicked();

    void onUpdateLikeMusic(bool isLike,QString musicId);

    void onPlayMusic();

    void onPlayStateChanged();

    void onPlayUpClicked();

    void onPlayDownClicked();

    void onPlaybackModeClicked();

    void onPlaybackModeChanged(QMediaPlaylist::PlaybackMode playbackMode);

    void onPlayAll(PageType pageType);

    void playAllOfCommonPage(CommonPage* page,int index);

    void playMusicByIndex(CommonPage* page, int index);

    void onCurrentIndexChanged(int index);

    void setPlayerMuted(bool isMuted);

    void setPlayerVolume(int volume);

    void onDurationChanged(qint64 duration);

    void onPositionChanged(qint64 duration);

    void onMusicSliderChanged(float ration);

    void onMetaDataAvailableChangedChanged(bool available);

    void onLcrWordClicked();

    void on_skin_clicked();
    void on_max_clicked();
    void on_min_clicked();

    void on_connectDB_clicked();
    void on_createTable_clicked();
    void updataBtformAnimal();

    void quitQQMusic();
private:
    Ui::QQMusic *ui;
    VolumeTool* volumeTool;
    QPoint dragPosition;
    MusicList musicList;
    QMediaPlayer* player;
    QMediaPlaylist* playList;
    CommonPage* curPage;
    int currentIndex;
    qint64 totalDuration;
    LrcPage* lrcPage;
    QPropertyAnimation* lrcAnimation;
    bool isDrag;
    QSqlDatabase sqlite;
};
#endif // QQMUSIC_H
