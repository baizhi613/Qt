#ifndef VOLUMETOOL_H
#define VOLUMETOOL_H

#include <QWidget>

namespace Ui {
class VolumeTool;
}

class VolumeTool : public QWidget
{
    Q_OBJECT

public:
    explicit VolumeTool(QWidget *parent = nullptr);
    ~VolumeTool();
    void paintEvent(QPaintEvent *event);
    void onSilenceBtnClicked();
    void calcVolume();
    bool eventFilter(QObject *watched, QEvent *event);
signals:
    void setSilence(bool);
    void setMusicVolume(int volume);
private:
    Ui::VolumeTool *ui;
    bool isMuted;
    int volumeRatio;
};

#endif // VOLUMETOOL_H
