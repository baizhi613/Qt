#include "qqmusic.h"
#include "ui_qqmusic.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QMenu>

QQMusic::QQMusic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QQMusic)
{
    ui->setupUi(this);
    initUI();
    initSQLite();
    initMusicList();
    initPlayer();
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
    setWindowIcon(QIcon(":/images/tubiao.png"));
    ui->max->setEnabled(false);
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor("#000000");
    shadowEffect->setBlurRadius(10);
    this->setGraphicsEffect(shadowEffect);
    QSystemTrayIcon* trayIcon=new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/tubiao.png"));
    QMenu *trayMenu=new QMenu(this);
    trayMenu->addAction("还原", this, &QWidget::showNormal);
    trayMenu->addSeparator();
    trayMenu->addAction("退出", this, &QQMusic::quitQQMusic);
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();

    ui->rec->seticon(":/images/rec.png", "推荐", 0);
    ui->audio->seticon(":/images/radio.png", "电台", 1);
    ui->music->seticon(":/images/music.png", "音乐馆", 2);
    ui->like->seticon(":/images/like.png", "我喜欢", 3);
    ui->local->seticon(":/images/local.png", "本地下载", 4);
    ui->recent->seticon(":/images/recent.png", "最近播放", 5);

    ui->local->showAnimal(true);
    ui->stackedWidget->setCurrentIndex(4);
    curPage=ui->localPage;
    srand(time(NULL));
    randomPiction();
    ui->recMusicBox->initRecBoxUi(randomPiction(),1);
    ui->supplyMusicBox->initRecBoxUi(randomPiction(),2);

    //ui->likePage->setMusicListType(PageType::LIKE_PAGE);
    ui->likePage->setCommonPageUI("我喜欢",":/images/ilikebg.png");
    //ui->localPage->setMusicListType(PageType::LOCAL_PAGE);
    ui->localPage->setCommonPageUI("本地音乐",":/images/localbg.png");
    //ui->recentPage->setMusicListType(PageType::HISTORY_PAGE);
    ui->recentPage->setCommonPageUI("最近播放",":/images/recentbg.png");

    ui->play->setIcon(QIcon(":/images/play_2.png"));
    ui->playMode->setIcon(QIcon(":/images/shuffle_2.png"));
    volumeTool=new VolumeTool(this);

    lrcPage=new LrcPage(this);
    lrcPage->setGeometry(10,10, lrcPage->width(), lrcPage->height());
    lrcPage->hide();

    lrcAnimation=new QPropertyAnimation(lrcPage,"geometry",this);
    lrcAnimation->setDuration(250);
    lrcAnimation->setStartValue(QRect(10,10+lrcPage->height(),lrcPage->width(),lrcPage->height()));
    lrcAnimation->setEndValue(QRect(10,10,lrcPage->width(),lrcPage->height()));
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
    connect(ui->rec,&BtForm::btClick,this,&QQMusic::onBtFormClick);
    connect(ui->audio,&BtForm::btClick,this,&QQMusic::onBtFormClick);
    connect(ui->music,&BtForm::btClick,this,&QQMusic::onBtFormClick);
    connect(ui->like,&BtForm::btClick,this,&QQMusic::onBtFormClick);
    connect(ui->local,&BtForm::btClick,this,&QQMusic::onBtFormClick);
    connect(ui->recent,&BtForm::btClick,this,&QQMusic::onBtFormClick);
    connect(ui->likePage, &CommonPage::updateLikeMusic, this, &QQMusic::onUpdateLikeMusic);
    connect(ui->localPage, &CommonPage::updateLikeMusic, this, &QQMusic::onUpdateLikeMusic);
    connect(ui->recentPage, &CommonPage::updateLikeMusic, this, &QQMusic::onUpdateLikeMusic);
    connect(ui->play,&QPushButton::clicked,this,&QQMusic::onPlayMusic);
    connect(ui->playPrev, &QPushButton::clicked, this,&QQMusic::onPlayUpClicked);
    connect(ui->playNext, &QPushButton::clicked, this,&QQMusic::onPlayDownClicked);
    connect(ui->playMode, &QPushButton::clicked, this, &QQMusic::onPlaybackModeClicked);
    connect(ui->likePage, &CommonPage::playAll, this, &QQMusic::onPlayAll);
    connect(ui->localPage, &CommonPage::playAll, this, &QQMusic::onPlayAll);
    connect(ui->recentPage, &CommonPage::playAll, this, &QQMusic::onPlayAll);
    connect(ui->likePage, &CommonPage::playMusicByIndex, this, &QQMusic::playMusicByIndex);
    connect(ui->localPage, &CommonPage::playMusicByIndex, this, &QQMusic::playMusicByIndex);
    connect(ui->recentPage, &CommonPage::playMusicByIndex, this, &QQMusic::playMusicByIndex);
    connect(volumeTool, &VolumeTool::setSilence, this,&QQMusic::setPlayerMuted);
    connect(volumeTool, &VolumeTool::setMusicVolume,this,&QQMusic::setPlayerVolume);
    connect(ui->processBar, &MusicSlider::setMusicSliderPosition, this, &QQMusic::onMusicSliderChanged);
    connect(ui->lrcWord,&QPushButton::clicked,this,&QQMusic::onLcrWordClicked);
    connect(ui->connectDB,&QPushButton::clicked,this,&QQMusic::on_connectDB_clicked);
    connect(ui->connectDB_2,&QPushButton::clicked,this,&QQMusic::on_createTable_clicked);
}

void QQMusic::initPlayer()
{
    player=new QMediaPlayer(this);
    playList=new QMediaPlaylist(this);
    playList->setPlaybackMode(QMediaPlaylist::Random);
    player->setPlaylist(playList);
    player->setVolume(20);
    connect(player, &QMediaPlayer::stateChanged,this,&QQMusic::onPlayStateChanged);
    connect(playList, &QMediaPlaylist::playbackModeChanged, this, &QQMusic::onPlaybackModeChanged);
    connect(playList, &QMediaPlaylist::currentIndexChanged, this, &QQMusic::onCurrentIndexChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &QQMusic::onDurationChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &QQMusic::onPositionChanged);
    connect(player,&QMediaPlayer::metaDataAvailableChanged,this,&QQMusic::onMetaDataAvailableChangedChanged);
}

void QQMusic::initSQLite()
{
    sqlite=QSqlDatabase::addDatabase("QSQLITE");
    sqlite.setDatabaseName("QQMusic.db");
    if(!sqlite.open())
    {
        QMessageBox::critical(this,"打开QQMusicDB失败",sqlite.lastError().text());
        return;
    }
    qDebug()<<"SQLite连接成功，并创建 [QQMusic.db] 数据库!!!";
    QString sql=("CREATE TABLE IF NOT EXISTS musicInfo(\
                  id INTEGER PRIMARY KEY AUTOINCREMENT,\
                  musicId varchar(200) UNIQUE,\
                  musicName varchar(50),\
                  musicSinger varchar(50),\
                  albumName varchar(50),\
                  duration BIGINT,\
                  musicUrl varchar(256),\
                  isLike INTEGER,\
                  isHistory INTEGER)"
                );
    QSqlQuery query;
    if(!query.exec(sql))
    {
        QMessageBox::critical(this,"创建数据库表失败",query.lastError().text());
        return;
    }
    qDebug()<<"创建 [musicInfo] 表成功!!!";
}

void QQMusic::initMusicList()
{
    musicList.readFromDB();
    ui->likePage->setMusicListType(PageType::LIKE_PAGE);
    ui->likePage->reFresh(musicList);

    ui->localPage->setMusicListType(PageType::LOCAL_PAGE);
    ui->localPage->reFresh(musicList);

    ui->recentPage->setMusicListType(PageType::HISTORY_PAGE);
    ui->recentPage->reFresh(musicList);
}

void QQMusic::onUpdateLikeMusic(bool isLike, QString musicId)
{
    auto it = musicList.findMusicByMusicId(musicId);
    if(it != musicList.end())
    {
        it->setIsLike(isLike);
    }
    ui->likePage->reFresh(musicList);
    ui->localPage->reFresh(musicList);
    ui->recentPage->reFresh(musicList);
}

void QQMusic::onPlayMusic()
{
    qDebug()<<"播放按钮点击";
    if(player->state()==QMediaPlayer::PlayingState)
    {
        player->pause();
    }
    else if(player->state()==QMediaPlayer::PausedState)
    {
        player->play();
    }
    else if(player->state()==QMediaPlayer::StoppedState)
    {
        player->play();
    }
}

void QQMusic::onPlayStateChanged()
{
    qDebug()<<"播放状态改变";
    if(player->state() == QMediaPlayer::PlayingState)
    {
        ui->play->setIcon(QIcon(":/images/play_on.png"));
    }
    else
    {
        ui->play->setIcon(QIcon(":/images/play3.png"));
    }
}

void QQMusic::onPlayUpClicked()
{
    playList->previous();
}

void QQMusic::onPlayDownClicked()
{
    playList->next();
}

void QQMusic::onPlaybackModeClicked()
{
    if(playList->playbackMode()==QMediaPlaylist::Loop)
    {
        ui->playMode->setToolTip("随机播放");
        playList->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if(playList->playbackMode() == QMediaPlaylist::Random)
    {
        ui->playMode->setToolTip("单曲循环");
        playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
    else if(playList->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
    {
        ui->playMode->setToolTip("列表循环");
        playList->setPlaybackMode(QMediaPlaylist::Loop);
    }
    else
    {
        qDebug()<<"播放模式错误";
    }
}

void QQMusic::onPlaybackModeChanged(QMediaPlaylist::PlaybackMode playbackMode)
{
    if(playbackMode == QMediaPlaylist::Loop)
    {
        ui->playMode->setIcon(QIcon(":/images/list_play.png"));
    }
    else if(playbackMode == QMediaPlaylist::Random)
    {
        ui->playMode->setIcon(QIcon(":/images/shuffle_2.png"));
    }
    else if(playbackMode == QMediaPlaylist::CurrentItemInLoop)
    {
        ui->playMode->setIcon(QIcon(":/images/single_play.png"));
    }
    else
    {
        qDebug()<<"暂不支持该模式";
    }
}

void QQMusic::onPlayAll(PageType pageType)
{
    CommonPage* page=nullptr;
    switch(pageType)
    {
    case PageType::LIKE_PAGE:
        page = ui->likePage;
        break;
    case PageType::LOCAL_PAGE:
        page = ui->localPage;
        break;
    case PageType::HISTORY_PAGE:
        page = ui->recentPage;
        break;
    default:
        qDebug()<<"扩展";
    }
    playAllOfCommonPage(page,0);
}

void QQMusic::playAllOfCommonPage(CommonPage *page, int index)
{
    curPage=page;
    playList->clear();
    page->addMusicToPlayer(musicList,playList);
    playList->setCurrentIndex(index);
    player->play();
}

void QQMusic::playMusicByIndex(CommonPage *page, int index)
{
    playAllOfCommonPage(page, index);
}

void QQMusic::onCurrentIndexChanged(int index)
{
    currentIndex=index;
    const QString& musicId=curPage->getMusicIdByIndex(index);
    auto it=musicList.findMusicByMusicId(musicId);
    if(it!=musicList.end())
    {
        it->setIsHistory(true);
        ui->recentPage->reFresh(musicList);
    }
}

void QQMusic::setPlayerMuted(bool isMuted)
{
    player->setMuted(isMuted);
}

void QQMusic::setPlayerVolume(int volume)
{
    player->setVolume(volume);
}

void QQMusic::onDurationChanged(qint64 duration)
{
    totalDuration=duration;
    ui->totalTime->setText(QString("%1:%2").arg(duration/1000/60, 2, 10, QChar('0')).arg(duration/1000%60,2,10,QChar('0')));
}

void QQMusic::onPositionChanged(qint64 duration)
{
    ui->currentTime->setText(QString("%1:%2").arg(duration/1000/60, 2, 10, QChar('0')).arg(duration/1000%60,2,10,QChar('0')));
    ui->processBar->setStep((float)duration / (float)totalDuration);
    if(playList->currentIndex()>=0)
    {
        lrcPage->showLrcWord(duration);
    }
}

void QQMusic::onMusicSliderChanged(float ration)
{
    qint64 duration = (qint64)(totalDuration * ration);
    ui->currentTime->setText(QString("%1:%2").arg(duration/1000/60, 2, 10, QChar('0')).arg(duration/1000%60, 2, 10,QChar('0')));
    player->setPosition(duration);
}

void QQMusic::onMetaDataAvailableChangedChanged(bool available)
{
    qDebug()<<"歌曲切换";
    QString singer = player->metaData("Author").toStringList().join(",");
    QString musicName = player->metaData("Title").toString();
    if(musicName.isEmpty())
    {
        auto it = musicList.findMusicByMusicId(curPage->getMusicIdByIndex(currentIndex));
        if(it != musicList.end())
        {
            musicName = it->getMusicName();
            singer = it->getSingerName();
        }
    }
    ui->musicName->setText(musicName);
    ui->musicSinger->setText(singer);
    QVariant coverImage = player->metaData("ThumbnailImage");
    if(coverImage.isValid())
    {
        QImage image = coverImage.value<QImage>();
        ui->musicCover->setPixmap(QPixmap::fromImage(image));
        ui->musicCover->setScaledContents(true);
        curPage->setImageLabel(QPixmap::fromImage(image));
    }
    else
    {
        qDebug()<<"歌曲没有封面图片";
    }
    QString musicId=curPage->getMusicIdByIndex(currentIndex);
    auto it=musicList.findMusicByMusicId(musicId);
    if(it!=musicList.end())
    {
        lrcPage->parseLrc(it->getLrcFilePath());
    }
}

void QQMusic::onLcrWordClicked()
{
    lrcPage->show();
    lrcAnimation->start();
}

void QQMusic::on_skin_clicked()
{
    QMessageBox::information(this, "温馨提⽰", "⼩哥哥正在加班紧急⽀持中...");
}

void QQMusic::on_max_clicked()
{
    showMaximized();
}

void QQMusic::on_min_clicked()
{
    showMinimized();
}

void QQMusic::on_connectDB_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QQMusic.db");
    if(!db.open())
    {
        qDebug()<<"QQMusic:"<<db.lastError().text();
    }
    qDebug()<<"数据库QQMusic.db创建成功";
    db.close();
}

void QQMusic::on_createTable_clicked()
{
    QString sql("CREATE TABLE IF NOT EXISTS student(\
                 id INTEGER PRIMARY KEY AUTOINCREMENT,\
                 name TEXT NOT NULL,\
                 age INTEGER,\
                 gpa REAL\
                ");
    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug()<<"学生表创建失败:"<<query.lastError().text();
        return;
    }
    qDebug()<<"创建学生表成功!!!";
}

void QQMusic::updataBtformAnimal()
{
    int index=ui->stackedWidget->indexOf(curPage);
    if(index==-1)
    {
        qDebug()<<"该页面不存在";
        return;
    }
    QList<BtForm*> btForms=this->findChildren<BtForm*>();
    for(auto btForm:btForms)
    {
        if(btForm->getPageId()==index)
        {
            btForm->showAnimal(true);
        }
        else
        {
            btForm->showAnimal(false);
        }
    }
}

void QQMusic::quitQQMusic()
{
    close();
}

void QQMusic::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isDrag=true;
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        return;
    }
    QWidget::mousePressEvent(event);
}

void QQMusic::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton&&isDrag)
    {
        move(event->globalPos() - dragPosition);
        return;
    }
    QWidget::mouseMoveEvent(event);
}

void QQMusic::on_quit_clicked()
{
    musicList.writeToDB();
    sqlite.close();
    hide();
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
    isDrag=false;
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
        ui->localPage->addMusicToPlayer(musicList,playList);
    }
}

