#ifndef QQMUSIC_H
#define QQMUSIC_H

#include <QWidget>
#include "volumetool.h"
#include "musiclist.h"

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
protected:
    // 重写QWidget类的鼠标单击和鼠标滚轮事件
    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent* event)override;

    QPoint dragPosition;
    MusicList musicList;
private slots:
    void on_quit_clicked();

    void onBtFormClick(int pageId);

    void on_volume_clicked();

    void on_addLocal_clicked();

private:
    Ui::QQMusic *ui;
    VolumeTool* volumeTool;
};
#endif // QQMUSIC_H
