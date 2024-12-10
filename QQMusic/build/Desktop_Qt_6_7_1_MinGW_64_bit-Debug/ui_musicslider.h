/********************************************************************************
** Form generated from reading UI file 'musicslider.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICSLIDER_H
#define UI_MUSICSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicSlider
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *outLine;
    QFrame *inLine;

    void setupUi(QWidget *MusicSlider)
    {
        if (MusicSlider->objectName().isEmpty())
            MusicSlider->setObjectName("MusicSlider");
        MusicSlider->resize(800, 20);
        horizontalLayout = new QHBoxLayout(MusicSlider);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        outLine = new QFrame(MusicSlider);
        outLine->setObjectName("outLine");
        outLine->setStyleSheet(QString::fromUtf8("#outLine\n"
"{\n"
" background-color:#1ECC94;\n"
"}"));
        outLine->setFrameShape(QFrame::StyledPanel);
        outLine->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(outLine);

        inLine = new QFrame(MusicSlider);
        inLine->setObjectName("inLine");
        inLine->setStyleSheet(QString::fromUtf8("#inLine\n"
"{\n"
" background-color:#EBEEF5;\n"
"}"));
        inLine->setFrameShape(QFrame::StyledPanel);
        inLine->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(inLine);


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
