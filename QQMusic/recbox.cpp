#include "recbox.h"
#include "ui_recbox.h"
#include <recboxitem.h>
#include <QJsonObject>

RecBox::RecBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecBox),
    row(1),
    col(4)
{
    ui->setupUi(this);
}

RecBox::~RecBox()
{
    delete ui;
}

void RecBox::initRecBoxUi(QJsonArray data, int row)
{
    if(2==row)
    {
        this->row=row;
        col=8;
    }
    else
    {
        ui->recListDown->hide();
    }
    imageList=data;
    currentIndex=0;
    count=imageList.size()/col;
    createRecBoxItem();
}

void RecBox::createRecBoxItem()
{
    QList<RecBoxItem*> recUpList=ui->recListUp->findChildren<RecBoxItem*>();
    for(auto e:recUpList)
    {
        ui->recListUpHLayout->removeWidget(e);
        delete e;
    }
    QList<RecBoxItem*> recDownList=ui->recListDown->findChildren<RecBoxItem*>();
    for(auto e:recDownList)
    {
        ui->recListDownHLayout->removeWidget(e);
        delete e;
    }
    int index=0;
    for(int i=currentIndex*col;i<col+col*currentIndex;i++)
    {
        RecBoxItem* item = new RecBoxItem();
        QJsonObject obj=imageList[i].toObject();
        item->setRecText(obj.value("text").toString());
        item->setRecImage(obj.value("path").toString());
        if(index>=col/2&&row==2)
        {
            ui->recListDownHLayout->addWidget(item);
        }
        else
        {
            ui->recListUpHLayout->addWidget(item);
        }
        index++;
    }
}

void RecBox::on_btDown_clicked()
{
    currentIndex++;
    if(currentIndex>=count)
    {
        currentIndex=0;
    }
    createRecBoxItem();
}


void RecBox::on_btUp_clicked()
{
    currentIndex--;
    if(currentIndex<count)
    {
        currentIndex=0;
    }
    createRecBoxItem();
}

