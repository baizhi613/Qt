/********************************************************************************
** Form generated from reading UI file 'listitembox.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTITEMBOX_H
#define UI_LISTITEMBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListItemBox
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *musicNameBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *likeBtn;
    QLabel *musicNameLabel;
    QLabel *VIPLabel;
    QLabel *SQLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *musicSingerBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *musicSingerLabel;
    QWidget *musicAlbumBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *albumNameLabel;

    void setupUi(QWidget *ListItemBox)
    {
        if (ListItemBox->objectName().isEmpty())
            ListItemBox->setObjectName("ListItemBox");
        ListItemBox->resize(800, 45);
        horizontalLayout = new QHBoxLayout(ListItemBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        musicNameBox = new QWidget(ListItemBox);
        musicNameBox->setObjectName("musicNameBox");
        musicNameBox->setMinimumSize(QSize(380, 0));
        musicNameBox->setMaximumSize(QSize(380, 16777215));
        horizontalLayout_2 = new QHBoxLayout(musicNameBox);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        likeBtn = new QPushButton(musicNameBox);
        likeBtn->setObjectName("likeBtn");
        likeBtn->setMinimumSize(QSize(25, 25));
        likeBtn->setMaximumSize(QSize(25, 25));
        likeBtn->setStyleSheet(QString::fromUtf8("#likeBtn\n"
"{\n"
" border:none;\n"
"}"));

        horizontalLayout_2->addWidget(likeBtn);

        musicNameLabel = new QLabel(musicNameBox);
        musicNameLabel->setObjectName("musicNameLabel");
        musicNameLabel->setMinimumSize(QSize(130, 0));
        musicNameLabel->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_2->addWidget(musicNameLabel);

        VIPLabel = new QLabel(musicNameBox);
        VIPLabel->setObjectName("VIPLabel");
        VIPLabel->setMinimumSize(QSize(30, 0));
        VIPLabel->setMaximumSize(QSize(30, 15));
        VIPLabel->setStyleSheet(QString::fromUtf8("#VIPLabel\n"
"{\n"
" border:1px solid #1ECD96;\n"
"color:#1ECD96;\n"
" border-radius:2px;\n"
" }"));

        horizontalLayout_2->addWidget(VIPLabel);

        SQLabel = new QLabel(musicNameBox);
        SQLabel->setObjectName("SQLabel");
        SQLabel->setMinimumSize(QSize(25, 0));
        SQLabel->setMaximumSize(QSize(25, 15));
        SQLabel->setStyleSheet(QString::fromUtf8("#SQLabel\n"
" {\n"
" border:1px solid #FF6600;\n"
" color:#FF6600;\n"
" border-radius:2px;\n"
" }"));

        horizontalLayout_2->addWidget(SQLabel);

        horizontalSpacer = new QSpacerItem(167, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout->addWidget(musicNameBox);

        musicSingerBox = new QWidget(ListItemBox);
        musicSingerBox->setObjectName("musicSingerBox");
        musicSingerBox->setMinimumSize(QSize(200, 0));
        musicSingerBox->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_3 = new QHBoxLayout(musicSingerBox);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        musicSingerLabel = new QLabel(musicSingerBox);
        musicSingerLabel->setObjectName("musicSingerLabel");

        horizontalLayout_3->addWidget(musicSingerLabel);


        horizontalLayout->addWidget(musicSingerBox);

        musicAlbumBox = new QWidget(ListItemBox);
        musicAlbumBox->setObjectName("musicAlbumBox");
        horizontalLayout_4 = new QHBoxLayout(musicAlbumBox);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        albumNameLabel = new QLabel(musicAlbumBox);
        albumNameLabel->setObjectName("albumNameLabel");

        horizontalLayout_4->addWidget(albumNameLabel);


        horizontalLayout->addWidget(musicAlbumBox);


        retranslateUi(ListItemBox);

        QMetaObject::connectSlotsByName(ListItemBox);
    } // setupUi

    void retranslateUi(QWidget *ListItemBox)
    {
        ListItemBox->setWindowTitle(QCoreApplication::translate("ListItemBox", "Form", nullptr));
        likeBtn->setText(QString());
        musicNameLabel->setText(QCoreApplication::translate("ListItemBox", "\345\217\257\345\217\257\346\211\230\346\265\267\347\232\204\347\211\247\347\276\212\344\272\272", nullptr));
        VIPLabel->setText(QCoreApplication::translate("ListItemBox", "VIP", nullptr));
        SQLabel->setText(QCoreApplication::translate("ListItemBox", "SQ", nullptr));
        musicSingerLabel->setText(QCoreApplication::translate("ListItemBox", "\347\216\213\347\220\252", nullptr));
        albumNameLabel->setText(QCoreApplication::translate("ListItemBox", "\345\217\257\345\217\257\346\211\230\346\265\267\347\232\204\347\211\247\347\276\212\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListItemBox: public Ui_ListItemBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTITEMBOX_H
