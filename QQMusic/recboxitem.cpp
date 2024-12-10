#include "recboxitem.h"
#include "ui_recboxitem.h"
#include <QDebug>
#include <QPropertyAnimation>

RecBoxItem::RecBoxItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecBoxItem)
{
    ui->setupUi(this);
    ui->musicImageBox->installEventFilter(this);
}

RecBoxItem::~RecBoxItem()
{
    delete ui;
}

void RecBoxItem::setRecText(const QString &text)
{
    ui->recBoxItemText->setText(text);
}

void RecBoxItem::setRecImage(const QString &imagePath)
{
    QString style="background-image:url("+imagePath+");";
    ui->recMusicImage->setStyleSheet(style);
}

bool RecBoxItem::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->musicImageBox)
    {
        int ImgWidget=ui->musicImageBox->width();
        int ImgHeight=ui->musicImageBox->height();
        if(event->type()==QEvent::Enter)
        {
            QPropertyAnimation* animation=new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(100);
            animation->setStartValue(QRect(9,10,ImgWidget,ImgHeight));
            animation->setEndValue(QRect(9,0,ImgWidget,ImgHeight));
            animation->start();

            connect(animation,&QPropertyAnimation::finished,this,[=](){
                delete animation;
                qDebug()<<"图片上移动画结束";
            });
            return true;
        }
        else if(event->type()==QEvent::Leave)
        {
            QPropertyAnimation* animation=new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(150);
            animation->setStartValue(QRect(9,0,ImgWidget,ImgHeight));
            animation->setEndValue(QRect(9,0,ImgWidget,ImgHeight));
            animation->start();

            connect(animation,&QPropertyAnimation::finished,this,[=](){
                delete animation;
                qDebug()<<"图片上移动画结束";
            });
            return true;
        }
    }
    return QObject::eventFilter(watched,event);
}
