#include "btform.h"
#include "ui_btform.h"
#include <QPropertyAnimation>

BtForm::BtForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BtForm)
{
    ui->setupUi(this);

    ui->lineBox->hide();

    line1Animal=new QPropertyAnimation(ui->line1,"geometry",this);
    line1Animal->setDuration(1500);
    line1Animal->setKeyValueAt(0,QRect(0,15,2,0));
    line1Animal->setKeyValueAt(0.5,QRect(0,0,2,15));
    line1Animal->setKeyValueAt(1,QRect(0,15,2,0));
    line1Animal->setLoopCount(-1);
    line1Animal->start();

    line2Animal=new QPropertyAnimation(ui->line2,"geometry",this);
    line2Animal->setDuration(1600);
    line2Animal->setKeyValueAt(0,QRect(7,15,2,0));
    line2Animal->setKeyValueAt(0.5,QRect(7,0,2,15));
    line2Animal->setKeyValueAt(1,QRect(7,15,2,0));
    line2Animal->setLoopCount(-1);
    line2Animal->start();

    line3Animal=new QPropertyAnimation(ui->line3,"geometry",this);
    line3Animal->setDuration(1700);
    line3Animal->setKeyValueAt(0,QRect(14,15,2,0));
    line3Animal->setKeyValueAt(0.5,QRect(14,0,2,15));
    line3Animal->setKeyValueAt(1,QRect(14,15,2,0));
    line3Animal->setLoopCount(-1);
    line3Animal->start();

    line4Animal=new QPropertyAnimation(ui->line4,"geometry",this);
    line4Animal->setDuration(1800);
    line4Animal->setKeyValueAt(0,QRect(21,15,2,0));
    line4Animal->setKeyValueAt(0.5,QRect(21,0,2,15));
    line4Animal->setKeyValueAt(1,QRect(21,15,2,0));
    line4Animal->setLoopCount(-1);
    line4Animal->start();
}

BtForm::~BtForm()
{
    delete ui;
}

void BtForm::seticon(const QString &btIcon, const QString &content, int pageId)
{
    ui->btIcon->setPixmap(QPixmap(btIcon));
    ui->btText->setText(content);
    this->pageId=pageId;
}

int BtForm::getPageId() const
{
    return pageId;
}

void BtForm::clearBackground()
{
    ui->btStyle->setStyleSheet("#btStyle:hover{ background:#D8D8D8;} QLabel{background-color : transparent;}");
}

void BtForm::showAnimal(bool isShow)
{
    if(isShow)
    {
        ui->lineBox->show();
    }
    else
    {
        ui->lineBox->hide();
    }
}

void BtForm::mousePressEvent(QMouseEvent *event)
{
    ui->btStyle->setStyleSheet("#btStyle{background-color:rgb(30,206,154);}  QLabel{background-color : transparent;}");
    emit btClick(pageId);
}


