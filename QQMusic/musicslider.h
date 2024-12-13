#ifndef MUSICSLIDER_H
#define MUSICSLIDER_H

#include <QWidget>

namespace Ui {
class MusicSlider;
}

class MusicSlider : public QWidget
{
    Q_OBJECT

public:
    explicit MusicSlider(QWidget *parent = nullptr);
    ~MusicSlider();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void moveSilder();
    void setStep(float bf);
signals:
    void setMusicSliderPosition(float ratio);
private:
    Ui::MusicSlider *ui;
    int currentPos;
    int maxWidth;
};

#endif // MUSICSLIDER_H
