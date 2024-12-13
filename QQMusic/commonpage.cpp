#include "commonpage.h"
#include "ui_commonpage.h"
#include "listitembox.h"
#include <QListWidgetItem>
#include "music.h"
CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
    ui->pageMusicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(ui->playAllBtn, &QPushButton::clicked, this, [=](){
        emit playAll(pageType);
    });
    connect(ui->pageMusicList, &QListWidget::doubleClicked, this, [=](const QModelIndex &index){
        emit playMusicByIndex(this, index.row());
    });
}

CommonPage::~CommonPage()
{
    delete ui;
}

void CommonPage::setMusicListType(PageType pageType)
{
    this->pageType=pageType;
}

void CommonPage::setCommonPageUI(const QString &title, const QString &image)
{
    ui->pageTittle->setText(title);
    ui->musicImageLabel->setPixmap(QPixmap(image));
    ui->musicImageLabel->setScaledContents(true);
}

void CommonPage::addMusicToMusicPage(MusicList &musicList)
{
    musicOfPage.clear();
    for(auto music:musicList)
    {
        switch (pageType)
        {
        case LIKE_PAGE:
            if(music.getIsLike())
            {
                musicOfPage.push_back(music.getMusicId());
            }
            break;
        case LOCAL_PAGE:
            musicOfPage.push_back(music.getMusicId());
            break;
        case HISTORY_PAGE:
            if(music.getIsHistory())
            {
                musicOfPage.push_back(music.getMusicId());
                break;
            }
            break;
        default:
            break;
        }
    }
}

void CommonPage::reFresh(MusicList &musicList)
{
    ui->pageMusicList->clear();
    addMusicToMusicPage(musicList);
    for(auto musicId:musicOfPage)
    {
        auto it=musicList.findMusicByMusicId(musicId);
        if(it==musicList.end())
            continue;
        ListItemBox* listItemBox = new ListItemBox(this);
        listItemBox->setMusicName(it->getMusicName());
        listItemBox->setSinger(it->getSingerName());
        listItemBox->setAlbumName(it->getAlbumName());
        listItemBox->setLikeIcon(it->getIsLike());
        QListWidgetItem* listWidgetItem = new QListWidgetItem(ui->pageMusicList);
        listWidgetItem->setSizeHint(QSize(ui->pageMusicList->width(), listItemBox->height()));
        ui->pageMusicList->setItemWidget(listWidgetItem, listItemBox);
        connect(listItemBox,&ListItemBox::setIsLike,this,[=](bool isLike){
            emit updateLikeMusic(isLike,it->getMusicId());
        });
    }
    repaint();
}

void CommonPage::addMusicToPlayer(MusicList &musicList, QMediaPlaylist *playList)
{
    for(auto music:musicList)
    {
        switch (pageType) {
        case LOCAL_PAGE:
        {
            playList->addMedia(music.getMusicUrl());
            break;
        }
        case LIKE_PAGE:
        {
            if(music.getIsLike())
            {
                playList->addMedia(music.getMusicUrl());
            }
            break;
        }
        case HISTORY_PAGE:
        {
            if(music.getIsHistory())
            {
                playList->addMedia(music.getMusicUrl());
            }
            break;
        }
        default:
            break;
        }
    }
}

QString CommonPage::getMusicIdByIndex(int index)
{
    if(index >= musicOfPage.size())
    {
        qDebug()<<"无此歌曲";
        return "";
    }
    return musicOfPage[index];
}

void CommonPage::setImageLabel(QPixmap pixMap)
{
    ui->musicImageLabel->setPixmap(pixMap);
    ui->musicImageLabel->setScaledContents(true);
}
