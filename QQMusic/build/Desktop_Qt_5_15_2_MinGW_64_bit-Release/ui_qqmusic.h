/********************************************************************************
** Form generated from reading UI file 'qqmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQMUSIC_H
#define UI_QQMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <musicslider.h>
#include "btform.h"
#include "commonpage.h"
#include "recbox.h"

QT_BEGIN_NAMESPACE

class Ui_QQMusic
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *background;
    QVBoxLayout *verticalLayout_2;
    QWidget *head;
    QHBoxLayout *horizontalLayout;
    QWidget *headLeft;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logo;
    QWidget *headRight;
    QHBoxLayout *horizontalLayout_3;
    QWidget *SearchBox;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit;
    QWidget *SettingBox;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *skin;
    QPushButton *max;
    QPushButton *min;
    QPushButton *quit;
    QWidget *body;
    QHBoxLayout *horizontalLayout_6;
    QWidget *bodyLeft;
    QVBoxLayout *verticalLayout_3;
    QWidget *leftBox;
    QVBoxLayout *verticalLayout_4;
    QWidget *onlineMusic;
    QVBoxLayout *verticalLayout_6;
    QLabel *onlineMusicText;
    BtForm *rec;
    BtForm *audio;
    BtForm *music;
    QWidget *myMusic;
    QVBoxLayout *verticalLayout_5;
    QLabel *myMusicText;
    BtForm *like;
    BtForm *local;
    BtForm *recent;
    QSpacerItem *verticalSpacer;
    QWidget *bodyRight;
    QVBoxLayout *verticalLayout_7;
    QStackedWidget *stackedWidget;
    QWidget *recPage;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QLabel *recText;
    QLabel *recMusictext;
    RecBox *recMusicBox;
    QLabel *supplyMusicText;
    RecBox *supplyMusicBox;
    QWidget *musicPage;
    QWidget *radioPage;
    QPushButton *connectDB;
    QPushButton *connectDB_2;
    CommonPage *likePage;
    CommonPage *localPage;
    CommonPage *recentPage;
    MusicSlider *processBar;
    QWidget *controlBox;
    QHBoxLayout *horizontalLayout_7;
    QWidget *play_1;
    QGridLayout *gridLayout;
    QLabel *musicName;
    QLabel *musicSinger;
    QLabel *musicCover;
    QWidget *play_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *playMode;
    QPushButton *playPrev;
    QPushButton *play;
    QPushButton *playNext;
    QPushButton *volume;
    QPushButton *addLocal;
    QWidget *play_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelNull;
    QLabel *currentTime;
    QLabel *line;
    QLabel *totalTime;
    QPushButton *lrcWord;

    void setupUi(QWidget *QQMusic)
    {
        if (QQMusic->objectName().isEmpty())
            QQMusic->setObjectName(QString::fromUtf8("QQMusic"));
        QQMusic->resize(1040, 700);
        verticalLayout = new QVBoxLayout(QQMusic);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        background = new QWidget(QQMusic);
        background->setObjectName(QString::fromUtf8("background"));
        background->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(background);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        head = new QWidget(background);
        head->setObjectName(QString::fromUtf8("head"));
        head->setMinimumSize(QSize(0, 80));
        head->setMaximumSize(QSize(16777215, 80));
        head->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(head);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        headLeft = new QWidget(head);
        headLeft->setObjectName(QString::fromUtf8("headLeft"));
        headLeft->setMinimumSize(QSize(200, 0));
        headLeft->setMaximumSize(QSize(200, 16777215));
        headLeft->setStyleSheet(QString::fromUtf8("#headLeft\n"
"{\n"
"background-color:#F0F0F0;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(headLeft);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        logo = new QLabel(headLeft);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setStyleSheet(QString::fromUtf8("#logo\n"
"{\n"
" border-radius:0px;\n"
" background-image: url(:/images/Logo.png);\n"
" background-repeat:no-repeat;\n"
"border:none;\n"
" background-position:center center;\n"
"}"));

        horizontalLayout_2->addWidget(logo);


        horizontalLayout->addWidget(headLeft);

        headRight = new QWidget(head);
        headRight->setObjectName(QString::fromUtf8("headRight"));
        headRight->setStyleSheet(QString::fromUtf8("#headRight\n"
"{\n"
" background-color:#F5F5F5; /*\350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\342\276\212\344\270\272\344\272\256\347\201\260\342\276\212*/\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(headRight);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        SearchBox = new QWidget(headRight);
        SearchBox->setObjectName(QString::fromUtf8("SearchBox"));
        SearchBox->setMinimumSize(QSize(300, 0));
        SearchBox->setMaximumSize(QSize(300, 16777215));
        SearchBox->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(SearchBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit = new QLineEdit(SearchBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 35));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit\n"
"{\n"
"	background-color: #E3E3E3;\n"
"	border-radius: 17px; \n"
"	padding-left: 17px;\n"
"}"));

        horizontalLayout_4->addWidget(lineEdit);


        horizontalLayout_3->addWidget(SearchBox);

        SettingBox = new QWidget(headRight);
        SettingBox->setObjectName(QString::fromUtf8("SettingBox"));
        SettingBox->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" border-radius:0px; /*\350\256\276\347\275\256\346\214\211\351\222\256\347\232\204\350\276\271\346\241\206\345\234\206\342\273\206\344\270\272 0 \345\203\217\347\264\240\357\274\214\n"
"\345\256\236\347\216\260\347\233\264\342\273\206\350\276\271\347\274\230*/\n"
" background-repeat:no-repeat; /* \350\203\214\346\231\257\345\233\276\342\275\232\344\270\215\351\207\215\345\244\215\345\271\263\351\223\272\n"
"*/\n"
" border: none; /*\342\275\206\350\276\271\346\241\206*/\n"
" background-position:center center; /*\350\203\214\346\231\257\345\233\276\342\275\232\346\224\276\347\275\256\345\234\250\n"
"\346\214\211\351\222\256\347\232\204\344\270\255\342\274\274\344\275\215\347\275\256*/\n"
"}\n"
"QPushButton:hover\n"
"{\n"
" background-color: rgba(230,0,0,0.5); /*\350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\n"
"\342\276\212\344\270\272\345\215\212\351\200\217\346\230\216\347\232\204\347\272\242\342\276\212*/\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(SettingBox);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(399, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        skin = new QPushButton(SettingBox);
        skin->setObjectName(QString::fromUtf8("skin"));
        skin->setMinimumSize(QSize(30, 30));
        skin->setMaximumSize(QSize(30, 30));
        skin->setStyleSheet(QString::fromUtf8("background-image: url(:/images/skin.png);"));

        horizontalLayout_5->addWidget(skin);

        max = new QPushButton(SettingBox);
        max->setObjectName(QString::fromUtf8("max"));
        max->setMinimumSize(QSize(30, 30));
        max->setMaximumSize(QSize(30, 30));
        max->setStyleSheet(QString::fromUtf8("background-image: url(:/images/max.png);"));

        horizontalLayout_5->addWidget(max);

        min = new QPushButton(SettingBox);
        min->setObjectName(QString::fromUtf8("min"));
        min->setMinimumSize(QSize(30, 30));
        min->setMaximumSize(QSize(30, 30));
        min->setStyleSheet(QString::fromUtf8("background-image: url(:/images/min.png);"));

        horizontalLayout_5->addWidget(min);

        quit = new QPushButton(SettingBox);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setMinimumSize(QSize(30, 30));
        quit->setMaximumSize(QSize(30, 30));
        quit->setStyleSheet(QString::fromUtf8("background-image: url(:/images/quit.png);"));

        horizontalLayout_5->addWidget(quit);


        horizontalLayout_3->addWidget(SettingBox);


        horizontalLayout->addWidget(headRight);


        verticalLayout_2->addWidget(head);

        body = new QWidget(background);
        body->setObjectName(QString::fromUtf8("body"));
        body->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_6 = new QHBoxLayout(body);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        bodyLeft = new QWidget(body);
        bodyLeft->setObjectName(QString::fromUtf8("bodyLeft"));
        bodyLeft->setMinimumSize(QSize(200, 0));
        bodyLeft->setMaximumSize(QSize(200, 16777215));
        bodyLeft->setStyleSheet(QString::fromUtf8("#bodyLeft\n"
"{\n"
" background-color:#F0F0F0;/*\350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\342\276\212\344\270\272\346\265\205\347\201\260\342\276\212*/\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(bodyLeft);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        leftBox = new QWidget(bodyLeft);
        leftBox->setObjectName(QString::fromUtf8("leftBox"));
        leftBox->setMinimumSize(QSize(0, 400));
        leftBox->setMaximumSize(QSize(16777215, 400));
        leftBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(leftBox);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        onlineMusic = new QWidget(leftBox);
        onlineMusic->setObjectName(QString::fromUtf8("onlineMusic"));
        onlineMusic->setStyleSheet(QString::fromUtf8("background-color:#f0f0f0"));
        verticalLayout_6 = new QVBoxLayout(onlineMusic);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        onlineMusicText = new QLabel(onlineMusic);
        onlineMusicText->setObjectName(QString::fromUtf8("onlineMusicText"));

        verticalLayout_6->addWidget(onlineMusicText);

        rec = new BtForm(onlineMusic);
        rec->setObjectName(QString::fromUtf8("rec"));

        verticalLayout_6->addWidget(rec);

        audio = new BtForm(onlineMusic);
        audio->setObjectName(QString::fromUtf8("audio"));

        verticalLayout_6->addWidget(audio);

        music = new BtForm(onlineMusic);
        music->setObjectName(QString::fromUtf8("music"));

        verticalLayout_6->addWidget(music);


        verticalLayout_4->addWidget(onlineMusic);

        myMusic = new QWidget(leftBox);
        myMusic->setObjectName(QString::fromUtf8("myMusic"));
        myMusic->setStyleSheet(QString::fromUtf8("background-color:#f0f0f0"));
        verticalLayout_5 = new QVBoxLayout(myMusic);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        myMusicText = new QLabel(myMusic);
        myMusicText->setObjectName(QString::fromUtf8("myMusicText"));

        verticalLayout_5->addWidget(myMusicText);

        like = new BtForm(myMusic);
        like->setObjectName(QString::fromUtf8("like"));

        verticalLayout_5->addWidget(like);

        local = new BtForm(myMusic);
        local->setObjectName(QString::fromUtf8("local"));

        verticalLayout_5->addWidget(local);

        recent = new BtForm(myMusic);
        recent->setObjectName(QString::fromUtf8("recent"));

        verticalLayout_5->addWidget(recent);


        verticalLayout_4->addWidget(myMusic);


        verticalLayout_3->addWidget(leftBox);

        verticalSpacer = new QSpacerItem(20, 199, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_6->addWidget(bodyLeft);

        bodyRight = new QWidget(body);
        bodyRight->setObjectName(QString::fromUtf8("bodyRight"));
        bodyRight->setStyleSheet(QString::fromUtf8("#bodyRight\n"
"{\n"
" background-color:#F5F5F5; /*\350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\342\276\212\344\270\272\344\272\256\347\201\260\342\276\212*/\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(bodyRight);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(bodyRight);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        recPage = new QWidget();
        recPage->setObjectName(QString::fromUtf8("recPage"));
        scrollArea = new QScrollArea(recPage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 10, 820, 500));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 818, 498));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        recText = new QLabel(scrollAreaWidgetContents);
        recText->setObjectName(QString::fromUtf8("recText"));
        recText->setMinimumSize(QSize(0, 50));
        recText->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(24);
        recText->setFont(font);

        verticalLayout_8->addWidget(recText);

        recMusictext = new QLabel(scrollAreaWidgetContents);
        recMusictext->setObjectName(QString::fromUtf8("recMusictext"));
        recMusictext->setMinimumSize(QSize(0, 30));
        recMusictext->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(18);
        recMusictext->setFont(font1);

        verticalLayout_8->addWidget(recMusictext);

        recMusicBox = new RecBox(scrollAreaWidgetContents);
        recMusicBox->setObjectName(QString::fromUtf8("recMusicBox"));

        verticalLayout_8->addWidget(recMusicBox);

        supplyMusicText = new QLabel(scrollAreaWidgetContents);
        supplyMusicText->setObjectName(QString::fromUtf8("supplyMusicText"));
        supplyMusicText->setMinimumSize(QSize(0, 30));
        supplyMusicText->setMaximumSize(QSize(16777215, 30));
        supplyMusicText->setFont(font1);

        verticalLayout_8->addWidget(supplyMusicText);

        supplyMusicBox = new RecBox(scrollAreaWidgetContents);
        supplyMusicBox->setObjectName(QString::fromUtf8("supplyMusicBox"));

        verticalLayout_8->addWidget(supplyMusicBox);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(recPage);
        musicPage = new QWidget();
        musicPage->setObjectName(QString::fromUtf8("musicPage"));
        stackedWidget->addWidget(musicPage);
        radioPage = new QWidget();
        radioPage->setObjectName(QString::fromUtf8("radioPage"));
        connectDB = new QPushButton(radioPage);
        connectDB->setObjectName(QString::fromUtf8("connectDB"));
        connectDB->setGeometry(QRect(70, 80, 171, 111));
        connectDB_2 = new QPushButton(radioPage);
        connectDB_2->setObjectName(QString::fromUtf8("connectDB_2"));
        connectDB_2->setGeometry(QRect(280, 80, 171, 111));
        stackedWidget->addWidget(radioPage);
        likePage = new CommonPage();
        likePage->setObjectName(QString::fromUtf8("likePage"));
        stackedWidget->addWidget(likePage);
        localPage = new CommonPage();
        localPage->setObjectName(QString::fromUtf8("localPage"));
        stackedWidget->addWidget(localPage);
        recentPage = new CommonPage();
        recentPage->setObjectName(QString::fromUtf8("recentPage"));
        stackedWidget->addWidget(recentPage);

        verticalLayout_7->addWidget(stackedWidget);

        processBar = new MusicSlider(bodyRight);
        processBar->setObjectName(QString::fromUtf8("processBar"));
        processBar->setMinimumSize(QSize(0, 30));
        processBar->setMaximumSize(QSize(16777215, 30));
        processBar->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(processBar);

        controlBox = new QWidget(bodyRight);
        controlBox->setObjectName(QString::fromUtf8("controlBox"));
        controlBox->setMinimumSize(QSize(0, 60));
        horizontalLayout_7 = new QHBoxLayout(controlBox);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        play_1 = new QWidget(controlBox);
        play_1->setObjectName(QString::fromUtf8("play_1"));
        play_1->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(play_1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        musicName = new QLabel(play_1);
        musicName->setObjectName(QString::fromUtf8("musicName"));

        gridLayout->addWidget(musicName, 0, 1, 1, 1);

        musicSinger = new QLabel(play_1);
        musicSinger->setObjectName(QString::fromUtf8("musicSinger"));

        gridLayout->addWidget(musicSinger, 1, 1, 1, 1);

        musicCover = new QLabel(play_1);
        musicCover->setObjectName(QString::fromUtf8("musicCover"));
        musicCover->setMinimumSize(QSize(60, 55));
        musicCover->setMaximumSize(QSize(60, 55));

        gridLayout->addWidget(musicCover, 0, 0, 2, 1);


        horizontalLayout_7->addWidget(play_1);

        play_2 = new QWidget(controlBox);
        play_2->setObjectName(QString::fromUtf8("play_2"));
        play_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"}\n"
"/*\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
" /*\350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\342\276\212\344\270\272\345\215\212\351\200\217\346\230\216\347\232\204\347\272\242\342\276\212*/\n"
" background-color: rgba(220,220,220,0.5); \n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(play_2);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        playMode = new QPushButton(play_2);
        playMode->setObjectName(QString::fromUtf8("playMode"));
        playMode->setMinimumSize(QSize(30, 30));
        playMode->setMaximumSize(QSize(30, 30));
        playMode->setStyleSheet(QString::fromUtf8("#playMode\n"
"{\n"
"border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
" background-repeat:no-repeat;\n"
" background-position:center center;\n"
"}"));

        horizontalLayout_8->addWidget(playMode);

        playPrev = new QPushButton(play_2);
        playPrev->setObjectName(QString::fromUtf8("playPrev"));
        playPrev->setMinimumSize(QSize(30, 30));
        playPrev->setMaximumSize(QSize(30, 30));
        playPrev->setStyleSheet(QString::fromUtf8("#playPrev\n"
"{\n"
" background-image: url(:/images/up.png);\n"
"border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
" background-repeat:no-repeat;\n"
" background-position:center center;\n"
"}"));

        horizontalLayout_8->addWidget(playPrev);

        play = new QPushButton(play_2);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMinimumSize(QSize(30, 30));
        play->setMaximumSize(QSize(30, 30));
        play->setStyleSheet(QString::fromUtf8("#play\n"
"{\n"
"border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
" background-repeat:no-repeat;\n"
" background-position:center center;\n"
"}"));

        horizontalLayout_8->addWidget(play);

        playNext = new QPushButton(play_2);
        playNext->setObjectName(QString::fromUtf8("playNext"));
        playNext->setMinimumSize(QSize(30, 30));
        playNext->setMaximumSize(QSize(30, 30));
        playNext->setStyleSheet(QString::fromUtf8("#playNext\n"
"{\n"
" background-image: url(:/images/down.png);\n"
"border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
" background-repeat:no-repeat;\n"
" background-position:center center;\n"
"}"));

        horizontalLayout_8->addWidget(playNext);

        volume = new QPushButton(play_2);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setMinimumSize(QSize(30, 30));
        volume->setMaximumSize(QSize(30, 30));
        volume->setStyleSheet(QString::fromUtf8("#volume\n"
"{\n"
" background-image: url(:/images/volumn.png);\n"
"border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
" background-repeat:no-repeat;\n"
" background-position:center center;\n"
"}"));

        horizontalLayout_8->addWidget(volume);

        addLocal = new QPushButton(play_2);
        addLocal->setObjectName(QString::fromUtf8("addLocal"));
        addLocal->setMinimumSize(QSize(30, 30));
        addLocal->setMaximumSize(QSize(30, 30));
        addLocal->setStyleSheet(QString::fromUtf8("#addLocal\n"
"{\n"
"	border:none;\n"
"	background-image:url(:/images/add.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}"));

        horizontalLayout_8->addWidget(addLocal);


        horizontalLayout_7->addWidget(play_2);

        play_3 = new QWidget(controlBox);
        play_3->setObjectName(QString::fromUtf8("play_3"));
        play_3->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_9 = new QHBoxLayout(play_3);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        labelNull = new QLabel(play_3);
        labelNull->setObjectName(QString::fromUtf8("labelNull"));
        labelNull->setMinimumSize(QSize(130, 0));
        labelNull->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_9->addWidget(labelNull);

        currentTime = new QLabel(play_3);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));

        horizontalLayout_9->addWidget(currentTime);

        line = new QLabel(play_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(20, 0));
        line->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_9->addWidget(line);

        totalTime = new QLabel(play_3);
        totalTime->setObjectName(QString::fromUtf8("totalTime"));

        horizontalLayout_9->addWidget(totalTime);

        lrcWord = new QPushButton(play_3);
        lrcWord->setObjectName(QString::fromUtf8("lrcWord"));
        lrcWord->setMaximumSize(QSize(30, 30));
        lrcWord->setStyleSheet(QString::fromUtf8("#lrcWord\n"
"{\n"
" border:none;\n"
" background-image:url(:/images/ci.png);\n"
" background-repeat:no-repeat;\n"
" background-position: center center;\n"
"}\n"
"#lrcWord:hover\n"
"{\n"
" background-color:rgba(220, 220, 220, 0.5);\n"
"}"));

        horizontalLayout_9->addWidget(lrcWord);


        horizontalLayout_7->addWidget(play_3);


        verticalLayout_7->addWidget(controlBox);


        horizontalLayout_6->addWidget(bodyRight);


        verticalLayout_2->addWidget(body);


        verticalLayout->addWidget(background);


        retranslateUi(QQMusic);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(QQMusic);
    } // setupUi

    void retranslateUi(QWidget *QQMusic)
    {
        QQMusic->setWindowTitle(QCoreApplication::translate("QQMusic", "QQMusic", nullptr));
        logo->setText(QString());
        skin->setText(QString());
        max->setText(QString());
        min->setText(QString());
        quit->setText(QString());
        onlineMusicText->setText(QCoreApplication::translate("QQMusic", "\345\234\250\347\272\277\351\237\263\344\271\220", nullptr));
        myMusicText->setText(QCoreApplication::translate("QQMusic", "\346\210\221\347\232\204\351\237\263\344\271\220", nullptr));
        recText->setText(QCoreApplication::translate("QQMusic", "\346\216\250\350\215\220", nullptr));
        recMusictext->setText(QCoreApplication::translate("QQMusic", "\344\273\212\346\227\245\344\270\272\344\275\240\346\216\250\350\215\220", nullptr));
        supplyMusicText->setText(QCoreApplication::translate("QQMusic", "\344\275\240\347\232\204\351\237\263\344\271\220\350\241\245\347\273\231\347\253\231", nullptr));
        connectDB->setText(QCoreApplication::translate("QQMusic", "connectDB", nullptr));
        connectDB_2->setText(QCoreApplication::translate("QQMusic", "createTable", nullptr));
        musicName->setText(QString());
        musicSinger->setText(QString());
        musicCover->setText(QString());
        playMode->setText(QString());
        playPrev->setText(QString());
        play->setText(QString());
        playNext->setText(QString());
        volume->setText(QString());
        addLocal->setText(QString());
        labelNull->setText(QString());
        currentTime->setText(QCoreApplication::translate("QQMusic", "00:00", nullptr));
        line->setText(QCoreApplication::translate("QQMusic", "/", nullptr));
        totalTime->setText(QCoreApplication::translate("QQMusic", "00:00", nullptr));
        lrcWord->setText(QCoreApplication::translate("QQMusic", "\350\257\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QQMusic: public Ui_QQMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQMUSIC_H
