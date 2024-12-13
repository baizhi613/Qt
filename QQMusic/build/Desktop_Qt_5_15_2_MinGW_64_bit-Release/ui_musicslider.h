/********************************************************************************
** Form generated from reading UI file 'musicslider.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICSLIDER_H
#define UI_MUSICSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicSlider
{
public:
    QFrame *outLine;
    QFrame *inLine;

    void setupUi(QWidget *MusicSlider)
    {
        if (MusicSlider->objectName().isEmpty())
            MusicSlider->setObjectName(QString::fromUtf8("MusicSlider"));
        MusicSlider->resize(800, 20);
        outLine = new QFrame(MusicSlider);
        outLine->setObjectName(QString::fromUtf8("outLine"));
        outLine->setGeometry(QRect(0, 8, 800, 4));
        outLine->setMinimumSize(QSize(0, 0));
        outLine->setMaximumSize(QSize(16777215, 16777215));
        outLine->setStyleSheet(QString::fromUtf8("#outLine\n"
"{\n"
" background-color:#1ECC94;\n"
"}"));
        outLine->setFrameShape(QFrame::StyledPanel);
        outLine->setFrameShadow(QFrame::Raised);
        inLine = new QFrame(MusicSlider);
        inLine->setObjectName(QString::fromUtf8("inLine"));
        inLine->setGeometry(QRect(0, 8, 800, 4));
        inLine->setStyleSheet(QString::fromUtf8("#inLine\n"
"{\n"
" background-color:#EBEEF5;\n"
"}\n"
""));
        inLine->setFrameShape(QFrame::StyledPanel);
        inLine->setFrameShadow(QFrame::Raised);
        inLine->raise();
        outLine->raise();

        retranslateUi(MusicSlider);

        QMetaObject::connectSlotsByName(MusicSlider);
    } // setupUi

    void retranslateUi(QWidget *MusicSlider)
    {
        MusicSlider->setWindowTitle(QCoreApplication::translate("MusicSlider", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicSlider: public Ui_MusicSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICSLIDER_H
