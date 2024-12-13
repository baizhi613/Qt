/********************************************************************************
** Form generated from reading UI file 'volumetool.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMETOOL_H
#define UI_VOLUMETOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VolumeTool
{
public:
    QWidget *volumeWidget;
    QWidget *sliderBox;
    QFrame *inSlider;
    QFrame *outSlider;
    QPushButton *sliderBtn;
    QPushButton *silenceBtn;
    QLabel *volumeRatio;

    void setupUi(QWidget *VolumeTool)
    {
        if (VolumeTool->objectName().isEmpty())
            VolumeTool->setObjectName(QString::fromUtf8("VolumeTool"));
        VolumeTool->resize(100, 350);
        volumeWidget = new QWidget(VolumeTool);
        volumeWidget->setObjectName(QString::fromUtf8("volumeWidget"));
        volumeWidget->setGeometry(QRect(10, 10, 80, 300));
        volumeWidget->setStyleSheet(QString::fromUtf8("#volumeWidget{\n"
" background-color:#ffffff;\n"
" border-radius:5px;\n"
"}"));
        sliderBox = new QWidget(volumeWidget);
        sliderBox->setObjectName(QString::fromUtf8("sliderBox"));
        sliderBox->setGeometry(QRect(0, 0, 80, 225));
        inSlider = new QFrame(sliderBox);
        inSlider->setObjectName(QString::fromUtf8("inSlider"));
        inSlider->setGeometry(QRect(38, 25, 4, 180));
        inSlider->setStyleSheet(QString::fromUtf8("#inSlider\n"
"{\n"
" background-color:#ECECEC;\n"
"}"));
        inSlider->setFrameShape(QFrame::StyledPanel);
        inSlider->setFrameShadow(QFrame::Raised);
        outSlider = new QFrame(sliderBox);
        outSlider->setObjectName(QString::fromUtf8("outSlider"));
        outSlider->setGeometry(QRect(38, 25, 4, 180));
        outSlider->setStyleSheet(QString::fromUtf8("#outSlider\n"
"{\n"
" background-color:#1ECC94;\n"
"}"));
        outSlider->setFrameShape(QFrame::StyledPanel);
        outSlider->setFrameShadow(QFrame::Raised);
        sliderBtn = new QPushButton(sliderBox);
        sliderBtn->setObjectName(QString::fromUtf8("sliderBtn"));
        sliderBtn->setGeometry(QRect(33, 20, 14, 14));
        sliderBtn->setMinimumSize(QSize(14, 14));
        sliderBtn->setMaximumSize(QSize(14, 14));
        sliderBtn->setStyleSheet(QString::fromUtf8("#sliderBtn\n"
"{\n"
"	background-color:#1ECC94;\n"
" border-radius:7px;\n"
"}"));
        silenceBtn = new QPushButton(volumeWidget);
        silenceBtn->setObjectName(QString::fromUtf8("silenceBtn"));
        silenceBtn->setGeometry(QRect(0, 260, 80, 45));
        silenceBtn->setMinimumSize(QSize(80, 45));
        silenceBtn->setMaximumSize(QSize(80, 45));
        silenceBtn->setStyleSheet(QString::fromUtf8("#silenceBtn\n"
"{\n"
" border:none;\n"
"}\n"
"#silenceBtn:hover{\n"
" background-color:#F0F0F0;\n"
"}"));
        volumeRatio = new QLabel(volumeWidget);
        volumeRatio->setObjectName(QString::fromUtf8("volumeRatio"));
        volumeRatio->setGeometry(QRect(10, 230, 53, 30));
        volumeRatio->setMinimumSize(QSize(0, 30));
        volumeRatio->setMaximumSize(QSize(16777215, 30));
        volumeRatio->setAlignment(Qt::AlignCenter);

        retranslateUi(VolumeTool);

        QMetaObject::connectSlotsByName(VolumeTool);
    } // setupUi

    void retranslateUi(QWidget *VolumeTool)
    {
        VolumeTool->setWindowTitle(QCoreApplication::translate("VolumeTool", "Form", nullptr));
        sliderBtn->setText(QString());
        silenceBtn->setText(QString());
        volumeRatio->setText(QCoreApplication::translate("VolumeTool", "20%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VolumeTool: public Ui_VolumeTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMETOOL_H
