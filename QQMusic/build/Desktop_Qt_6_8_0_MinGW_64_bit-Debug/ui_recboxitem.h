/********************************************************************************
** Form generated from reading UI file 'recboxitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECBOXITEM_H
#define UI_RECBOXITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecBoxItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *musicImageBox;
    QLabel *recMusicImage;
    QPushButton *recMusicBtn;
    QLabel *recBoxItemText;

    void setupUi(QWidget *RecBoxItem)
    {
        if (RecBoxItem->objectName().isEmpty())
            RecBoxItem->setObjectName("RecBoxItem");
        RecBoxItem->resize(150, 200);
        verticalLayout = new QVBoxLayout(RecBoxItem);
        verticalLayout->setObjectName("verticalLayout");
        musicImageBox = new QWidget(RecBoxItem);
        musicImageBox->setObjectName("musicImageBox");
        musicImageBox->setMinimumSize(QSize(0, 150));
        musicImageBox->setMaximumSize(QSize(16777215, 150));
        recMusicImage = new QLabel(musicImageBox);
        recMusicImage->setObjectName("recMusicImage");
        recMusicImage->setGeometry(QRect(0, 0, 150, 150));
        recMusicBtn = new QPushButton(musicImageBox);
        recMusicBtn->setObjectName("recMusicBtn");
        recMusicBtn->setGeometry(QRect(30, 50, 71, 61));
        recMusicBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        recMusicBtn->setStyleSheet(QString::fromUtf8("#recMusicBtn\n"
"{\n"
"border:none;\n"
"}"));

        verticalLayout->addWidget(musicImageBox);

        recBoxItemText = new QLabel(RecBoxItem);
        recBoxItemText->setObjectName("recBoxItemText");
        recBoxItemText->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(recBoxItemText);


        retranslateUi(RecBoxItem);

        QMetaObject::connectSlotsByName(RecBoxItem);
    } // setupUi

    void retranslateUi(QWidget *RecBoxItem)
    {
        RecBoxItem->setWindowTitle(QCoreApplication::translate("RecBoxItem", "Form", nullptr));
        recMusicImage->setText(QString());
        recMusicBtn->setText(QString());
        recBoxItemText->setText(QCoreApplication::translate("RecBoxItem", "\346\216\250\350\215\220-001", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecBoxItem: public Ui_RecBoxItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECBOXITEM_H
