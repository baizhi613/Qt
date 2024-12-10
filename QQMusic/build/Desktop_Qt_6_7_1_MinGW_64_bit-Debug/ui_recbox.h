/********************************************************************************
** Form generated from reading UI file 'recbox.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECBOX_H
#define UI_RECBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecBox
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftPage;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btUp;
    QWidget *musicContent;
    QVBoxLayout *verticalLayout;
    QWidget *recListUp;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *recListUpHLayout;
    QWidget *recListDown;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *recListDownHLayout;
    QWidget *rightPage;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btDown;

    void setupUi(QWidget *RecBox)
    {
        if (RecBox->objectName().isEmpty())
            RecBox->setObjectName("RecBox");
        RecBox->resize(685, 440);
        horizontalLayout = new QHBoxLayout(RecBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftPage = new QWidget(RecBox);
        leftPage->setObjectName("leftPage");
        leftPage->setMinimumSize(QSize(30, 0));
        leftPage->setMaximumSize(QSize(30, 16777215));
        horizontalLayout_2 = new QHBoxLayout(leftPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btUp = new QPushButton(leftPage);
        btUp->setObjectName("btUp");
        btUp->setMinimumSize(QSize(0, 220));
        btUp->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" background-repeat:no-repeat;\n"
" border:none;\n"
" background-image : url(:/images/up_page.png);\n"
" background-position:center center;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background-color: #1ECD97;\n"
"}"));

        horizontalLayout_2->addWidget(btUp);


        horizontalLayout->addWidget(leftPage);

        musicContent = new QWidget(RecBox);
        musicContent->setObjectName("musicContent");
        verticalLayout = new QVBoxLayout(musicContent);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        recListUp = new QWidget(musicContent);
        recListUp->setObjectName("recListUp");
        horizontalLayout_4 = new QHBoxLayout(recListUp);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        recListUpHLayout = new QHBoxLayout();
        recListUpHLayout->setObjectName("recListUpHLayout");

        horizontalLayout_4->addLayout(recListUpHLayout);


        verticalLayout->addWidget(recListUp);

        recListDown = new QWidget(musicContent);
        recListDown->setObjectName("recListDown");
        horizontalLayout_5 = new QHBoxLayout(recListDown);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        recListDownHLayout = new QHBoxLayout();
        recListDownHLayout->setObjectName("recListDownHLayout");

        horizontalLayout_5->addLayout(recListDownHLayout);


        verticalLayout->addWidget(recListDown);


        horizontalLayout->addWidget(musicContent);

        rightPage = new QWidget(RecBox);
        rightPage->setObjectName("rightPage");
        rightPage->setMinimumSize(QSize(30, 0));
        rightPage->setMaximumSize(QSize(30, 16777215));
        horizontalLayout_3 = new QHBoxLayout(rightPage);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btDown = new QPushButton(rightPage);
        btDown->setObjectName("btDown");
        btDown->setMinimumSize(QSize(0, 220));
        btDown->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" background-repeat:no-repeat;\n"
" border:none;\n"
" background-image : url(:/images/down_page.png);\n"
" background-position:center center;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
" background-color: #1ECD97;\n"
"}"));

        horizontalLayout_3->addWidget(btDown);


        horizontalLayout->addWidget(rightPage);


        retranslateUi(RecBox);

        QMetaObject::connectSlotsByName(RecBox);
    } // setupUi

    void retranslateUi(QWidget *RecBox)
    {
        RecBox->setWindowTitle(QCoreApplication::translate("RecBox", "Form", nullptr));
        btUp->setText(QString());
        btDown->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecBox: public Ui_RecBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECBOX_H
