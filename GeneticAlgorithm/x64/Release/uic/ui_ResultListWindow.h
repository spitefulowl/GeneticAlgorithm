/********************************************************************************
** Form generated from reading UI file 'ResultListWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTLISTWINDOW_H
#define UI_RESULTLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultList
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *ResultList)
    {
        if (ResultList->objectName().isEmpty())
            ResultList->setObjectName(QString::fromUtf8("ResultList"));
        ResultList->resize(689, 678);
        listWidget = new QListWidget(ResultList);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(70, 50, 571, 571));

        retranslateUi(ResultList);

        QMetaObject::connectSlotsByName(ResultList);
    } // setupUi

    void retranslateUi(QWidget *ResultList)
    {
        ResultList->setWindowTitle(QApplication::translate("ResultList", "ResultList", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultList: public Ui_ResultList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTLISTWINDOW_H
