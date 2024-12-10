#include "qqmusic.h"
#include "ui_qqmusic.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QFileDialog>

QQMusic::QQMusic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QQMusic)
{
    ui->setupUi(this);
    initUI();
    connectSignalAndSlots();
}

QQMusic::~QQMusic()
{
    delete ui;
}

void QQMusic::initUI()
{
    setWindowFlag(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor("#000000");
    shadowEffect->setBlurRadius(10);
    this->setGraphicsEffect(shadowEffect);

    ui->rec->seticon(":/images/rec.png", "推荐", 0);
    ui->audio->seticon(":/images/radio.png", "电台", 1);
    ui->music->seticon(":/images/music.png", "音乐馆", 2);
    ui->like->seticon(":/images/like.png", "我喜欢", 3);
    ui->local->seticon(":/images/local.png", "本地下载", 4);
    ui->recent->seticon(":/images/recent.png", "最近播放", 5);

    ui->local->showAnimal();
    ui->stackedWidget->setCurrentIndex(4);

    srand(time(NULL));
    randomPiction();
    ui->recMusicBox->initRecBoxUi(randomPiction(),1);
    ui->supplyMusicBox->initRecBoxUi(randomPiction(),2);

    ui->likePage->setMusicListType(PageType::LIKE_PAGE);
    ui->likePage->setCommonPageUI("我喜欢",":/images/ilikebg.png");
    ui->localPage->setMusicListType(PageType::LOCAL_PAGE);
    ui->localPage->setCommonPageUI("本地音乐",":/images/localbg.png");
    ui->recentPage->setMusicListType(PageType::HISTORY_PAGE);
    ui->recentPage->setCommonPageUI("最近播放",":/images/recentbg.png");

    volumeTool=new VolumeTool(this);
}

QJsonArray QQMusic::randomPiction()
{
    QVector<QString> vecImageName;
    vecImageName<<"001.png"<<"003.png"<<"004.png"<<"005.png"<<"006.png"
                <<"007.png"<<"008.png"<<"009.png"<<"010.png"<<"011.png"
                <<"012.png"<<"013.png"<<"014.png"<<"015.png"<<"016.png"
                <<"017.png"<<"018.png"<<"019.png"<<"020.png"<<"021.png"
                <<"022.png"<<"023.png"<<"024.png"<<"025.png"<<"026.png"
                <<"027.png"<<"028.png"<<"029.png"<<"030.png"<<"031.png"
                <<"032.png"<<"033.png"<<"034.png"<<"035.png"<<"036.png"
                <<"037.png"<<"038.png"<<"039.png"<<"040.png";
    QJsonArray objArray;
    std::random_shuffle(vecImageName.begin(),vecImageName.end());
    for(int i=0;i<vecImageName.size();i++)
    {
        QJsonObject obj;
        obj.insert("path",":/images/rec/"+vecImageName[i]);
        QString strText=QString("推荐-%1").arg(i,3,10,QChar('0'));
        obj.insert("text",strText);

        objArray.append(obj);
    }
    return objArray;
}

void QQMusic::connectSignalAndSlots()
{
    connect(ui->rec, &BtForm::btClick,this,&QQMusic::onBtFormClick);
    connect(ui->music, &BtForm::btClick, this, &QQMusic::onBtFormClick);
    connect(ui->audio, &BtForm::btClick, this, &QQMusic::onBtFormClick);
    connect(ui->like, &BtForm::btClick, this, &QQMusic::onBtFormClick);
    connect(ui->local, &BtForm::btClick, this, &QQMusic::onBtFormClick);
    connect(ui->recent, &BtForm::btClick, this, &QQMusic::onBtFormClick);
}

void QQMusic::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        return;
    }
    QWidget::mousePressEvent(event);
}

void QQMusic::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition);
        return;
    }
    QWidget::mouseMoveEvent(event);
}

void QQMusic::on_quit_clicked()
{
    close();
}

void QQMusic::onBtFormClick(int pageId)
{
    QList<BtForm*> btFormList=this->findChildren<BtForm*>();
    for(auto btForm:btFormList)
    {
        if(btForm->getPageId()!=pageId)
        {
            btForm->clearBackground();
        }
    }
    ui->stackedWidget->setCurrentIndex(pageId);
}


void QQMusic::on_volume_clicked()
{
    QPoint point=ui->volume->mapToGlobal(QPoint(0,0));
    QPoint volumeLeftTop=point-QPoint(volumeTool->width()/2,volumeTool->height());
    volumeLeftTop.setY(volumeLeftTop.y()+30);
    volumeLeftTop.setX(volumeLeftTop.x()+15);
    volumeTool->move(volumeLeftTop);
    volumeTool->show();
}


void QQMusic::on_addLocal_clicked()
{
    QFileDialog fileDialog(this);
    fileDialog.setWindowTitle("添加本地音乐");
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    QStringList mimeList;
    mimeList<<"application/octet-stream";
    fileDialog.setMimeTypeFilters(mimeList);
    QDir dir(QDir::currentPath());
    dir.cdUp();
    QString musicPath = dir.path()+"/QQMusic/musics/";
    fileDialog.setDirectory(musicPath);
    if(fileDialog.exec()==QFileDialog::Accepted)
    {
        ui->stackedWidget->setCurrentIndex(4);
        QList<QUrl> urls=fileDialog.selectedUrls();
        musicList.addMusicByUrl(urls);
        ui->localPage->reFresh(musicList);
    }
}

