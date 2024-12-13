#include "lrcpage.h"
#include "ui_lrcpage.h"
#include <QPushButton>
#include <QFile>
#include <QDebug>
LrcPage::LrcPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LrcPage)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    lrcAnimation=new QPropertyAnimation(this,"geometry",this);
    lrcAnimation->setDuration(250);
    lrcAnimation->setStartValue(QRect(10,10,width(),height()));
    lrcAnimation->setEndValue(QRect(10,10+height(),width(),height()));

    connect(ui->hideBtn,&QPushButton::clicked,this,[=]{
        lrcAnimation->start();
    });
    connect(lrcAnimation,&QPropertyAnimation::finished,this,[=]{
        hide();
    });
    ui->hideBtn->setIcon(QIcon(":/images/xiala.png"));
    showLrcWord(-1);
}

LrcPage::~LrcPage()
{
    delete ui;
}

bool LrcPage::parseLrc(const QString &lrcPath)
{
    lrcLines.clear();
    QFile lrcFile(lrcPath);
    if(!lrcFile.open(QFile::ReadOnly))
    {
        qDebug()<<"打开文件:"<<lrcPath;
        return false;
    }
    while(!lrcFile.atEnd())
    {
        QString lrcWord=lrcFile.readLine(1024);
        int left=lrcWord.indexOf('[');
        int right=lrcWord.indexOf(']');
        qint64 lineTime=0;
        int start=0;
        int end=0;
        QString time=lrcWord.mid(left,right-left+1);
        start=1;
        end=time.indexOf(':');
        lineTime+=lrcWord.mid(start,end-start).toInt()*60*1000;
        start = end + 1;
        end = time.indexOf('.', start);
        lineTime += lrcWord.mid(start, end-start).toInt()*1000;
        start = end+1;
        end = time.indexOf('.', start);
        lineTime += lrcWord.mid(start, end-start).toInt();
        QString word = lrcWord.mid(right+1).trimmed();
        lrcLines.push_back(LyricLine(lineTime, word.trimmed()));
    }
    for(auto word:lrcLines)
    {
        qDebug()<<word.time<<" "<<word.text;
    }
    return true;
}

int LrcPage::getLineLrcWordIndex(qint64 pos)
{
    if(lrcLines.isEmpty())
    {
        return -1;
    }
    if(lrcLines[0].time>pos)
    {
        return 0;
    }
    for(int i=1;i<lrcLines.size();i++)
    {
        if(pos>lrcLines[i-1].time&&pos<=lrcLines[i].time)
        {
            return i-1;
        }
    }
    return lrcLines.size()-1;
}

QString LrcPage::getLineLrcWord(qint64 index)
{
    if(index<0||index>=lrcLines.size())
    {
        return "";
    }
    return lrcLines[index].text;
}

void LrcPage::showLrcWord(int time)
{
    int index=getLineLrcWordIndex(time);
    if(index==-1)
    {
        ui->line1->setText("");
        ui->line2->setText("");
        ui->line3->setText("");
        ui->lineCenter->setText("当前歌曲无歌词");
        ui->line4->setText("");
        ui->line5->setText("");
        ui->line6->setText("");
    }
    else
    {
        ui->line1->setText(getLineLrcWord(index-3));
        ui->line2->setText(getLineLrcWord(index-2));
        ui->line3->setText(getLineLrcWord(index-1));
        ui->lineCenter->setText(getLineLrcWord(index));
        ui->line4->setText(getLineLrcWord(index+1));
        ui->line5->setText(getLineLrcWord(index+2));
        ui->line6->setText(getLineLrcWord(index+3));
    }
}
