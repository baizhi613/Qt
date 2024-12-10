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

    ListItemBox* listItemBox=new ListItemBox(this);
    QListWidgetItem* item=new QListWidgetItem(ui->pageMusicList);
    item->setSizeHint(QSize(listItemBox->width(),listItemBox->height()));
    ui->pageMusicList->setItemWidget(item,listItemBox);
}

void CommonPage::addMusicToMusicPage(MusicList &musicList)
{
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
    addMusicToMusicPage(musicList);
    for(auto musicId:musicOfPage)
    {
        auto it=musicList.findMusicByMusicId(musicId);
        if(it==musicList.end())
        {
            continue;
        }
    }
}
