/********************************************************************************
** Form generated from reading UI file 'btform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTFORM_H
#define UI_BTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BtForm
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *btStyle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *btIcon;
    QLabel *btText;
    QWidget *lineBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *line1;
    QLabel *line4;
    QLabel *line3;
    QLabel *line2;

    void setupUi(QWidget *BtForm)
    {
        if (BtForm->objectName().isEmpty())
            BtForm->setObjectName("BtForm");
        BtForm->resize(200, 35);
        horizontalLayout = new QHBoxLayout(BtForm);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btStyle = new QWidget(BtForm);
        btStyle->setObjectName("btStyle");
        btStyle->setStyleSheet(QString::fromUtf8("#btStyle:hover\n"
"{\n"
" background-color:#D8D8D8;\n"
"}\n"
"\n"
"QLabel{\n"
"background-color : transparent;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(btStyle);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(3, 0, 0, 0);
        btIcon = new QLabel(btStyle);
        btIcon->setObjectName("btIcon");
        btIcon->setMinimumSize(QSize(30, 0));
        btIcon->setMaximumSize(QSize(30, 16777215));
        btIcon->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(btIcon);

        btText = new QLabel(btStyle);
        btText->setObjectName("btText");
        btText->setMinimumSize(QSize(120, 0));
        btText->setMaximumSize(QSize(120, 16777215));
        btText->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(btText);

        lineBox = new QWidget(btStyle);
        lineBox->setObjectName("lineBox");
        lineBox->setMinimumSize(QSize(0, 15));
        lineBox->setMaximumSize(QSize(16777215, 15));
        lineBox->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color:#FFFFFF\n"
"}\n"
"\n"
"#lineBox{\n"
"    background-color : transparent;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(lineBox);
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        line1 = new QLabel(lineBox);
        line1->setObjectName("line1");
        line1->setMinimumSize(QSize(2, 0));
        line1->setMaximumSize(QSize(2, 16777215));

        horizontalLayout_3->addWidget(line1);

        line4 = new QLabel(lineBox);
        line4->setObjectName("line4");
        line4->setMinimumSize(QSize(2, 0));
        line4->setMaximumSize(QSize(2, 16777215));

        horizontalLayout_3->addWidget(line4);

        line3 = new QLabel(lineBox);
        line3->setObjectName("line3");
        line3->setMinimumSize(QSize(2, 0));
        line3->setMaximumSize(QSize(2, 16777215));

        horizontalLayout_3->addWidget(line3);

        line2 = new QLabel(lineBox);
        line2->setObjectName("line2");
        line2->setMinimumSize(QSize(2, 0));
        line2->setMaximumSize(QSize(2, 16777215));

        horizontalLayout_3->addWidget(line2);


        horizontalLayout_2->addWidget(lineBox);


        horizontalLayout->addWidget(btStyle);


        retranslateUi(BtForm);

        QMetaObject::connectSlotsByName(BtForm);
    } // setupUi

    void retranslateUi(QWidget *BtForm)
    {
        BtForm->setWindowTitle(QCoreApplication::translate("BtForm", "Form", nullptr));
        btIcon->setText(QCoreApplication::translate("BtForm", "\345\233\276", nullptr));
        btText->setText(QCoreApplication::translate("BtForm", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        line1->setText(QString());
        line4->setText(QString());
        line3->setText(QString());
        line2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BtForm: public Ui_BtForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTFORM_H