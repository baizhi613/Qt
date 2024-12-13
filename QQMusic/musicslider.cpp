#include "musicslider.h"
#include "ui_musicslider.h"
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
MusicSlider::MusicSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicSlider)
{
    ui->setupUi(this);
    maxWidth = this->width();
    currentPos = 0;
    moveSilder();
}

MusicSlider::~MusicSlider()
{
    delete ui;
}

void MusicSlider::mousePressEvent(QMouseEvent *event)
{
    currentPos = event->pos().x();
    moveSilder();
}

void MusicSlider::mouseMoveEvent(QMouseEvent *event)
{
    QRect rect = QRect(0, 0, geometry().width(), geometry().height());
    QPoint pos = event->pos();
    if(!rect.contains(pos))
    {
        return;
    }
    if(event->buttons() == Qt::LeftButton)
    {
        currentPos = event->pos().x();
        if(currentPos < 0)
        {
            currentPos = 0;
        }
        if(currentPos > maxWidth)
        {
            currentPos = maxWidth;
        }

        //qDebug()<<currentPos<<"-"<<maxWidth;
        moveSilder();
    }
}

void MusicSlider::mouseReleaseEvent(QMouseEvent *event)
{
    currentPos = event->pos().x();
    moveSilder();
    emit setMusicSliderPosition((float)currentPos / (float)maxWidth);
}

void MusicSlider::moveSilder()
{
    ui->outLine->setGeometry(ui->outLine->x(),ui->outLine->y(),currentPos,ui->outLine->height());
    qDebug()<<ui->outLine->geometry();
}

void MusicSlider::setStep(float bf)
{
    currentPos = maxWidth*bf;
    moveSilder();
}
