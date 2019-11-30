/********************************************************************************
** Form generated from reading UI file 'GeneticAlgorithm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENETICALGORITHM_H
#define UI_GENETICALGORITHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneticAlgorithmClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralWidget;
    QTableView *matrixView;
    QGroupBox *groupBox;
    QLineEdit *matrixSizeEdit;
    QLabel *matrixSize;
    QPushButton *rndButton;
    QLabel *maxValue;
    QLineEdit *matrixMaxEdit;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *RandomRadio;
    QRadioButton *GreedyRadio;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *ordinalRadio;
    QRadioButton *partialRadio;
    QGroupBox *groupBox_4;
    QLineEdit *probabilityEdit;
    QLabel *label_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *pointRadio;
    QRadioButton *inversionRadio;
    QGroupBox *groupBox_5;
    QLineEdit *bettaEdit;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *tournamentRadio;
    QRadioButton *proportionalRadio;
    QGroupBox *groupBox_6;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *populationEdit;
    QLineEdit *iterationsEdit;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *startButton;
    QPushButton *testButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GeneticAlgorithmClass)
    {
        if (GeneticAlgorithmClass->objectName().isEmpty())
            GeneticAlgorithmClass->setObjectName(QString::fromUtf8("GeneticAlgorithmClass"));
        GeneticAlgorithmClass->resize(587, 398);
        actionOpen = new QAction(GeneticAlgorithmClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionExit = new QAction(GeneticAlgorithmClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(GeneticAlgorithmClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        matrixView = new QTableView(centralWidget);
        matrixView->setObjectName(QString::fromUtf8("matrixView"));
        matrixView->setEnabled(true);
        matrixView->setGeometry(QRect(30, 280, 151, 151));
        matrixView->setMaximumSize(QSize(5000, 5000));
        matrixView->horizontalHeader()->setMinimumSectionSize(30);
        matrixView->horizontalHeader()->setDefaultSectionSize(30);
        matrixView->verticalHeader()->setMinimumSectionSize(25);
        matrixView->verticalHeader()->setDefaultSectionSize(25);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 161, 111));
        matrixSizeEdit = new QLineEdit(groupBox);
        matrixSizeEdit->setObjectName(QString::fromUtf8("matrixSizeEdit"));
        matrixSizeEdit->setGeometry(QRect(80, 20, 51, 20));
        matrixSize = new QLabel(groupBox);
        matrixSize->setObjectName(QString::fromUtf8("matrixSize"));
        matrixSize->setGeometry(QRect(10, 22, 23, 16));
        rndButton = new QPushButton(groupBox);
        rndButton->setObjectName(QString::fromUtf8("rndButton"));
        rndButton->setGeometry(QRect(10, 80, 75, 23));
        maxValue = new QLabel(groupBox);
        maxValue->setObjectName(QString::fromUtf8("maxValue"));
        maxValue->setGeometry(QRect(10, 50, 60, 16));
        matrixMaxEdit = new QLineEdit(groupBox);
        matrixMaxEdit->setObjectName(QString::fromUtf8("matrixMaxEdit"));
        matrixMaxEdit->setGeometry(QRect(80, 50, 51, 20));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(210, 11, 141, 111));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 84, 42));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        RandomRadio = new QRadioButton(layoutWidget);
        RandomRadio->setObjectName(QString::fromUtf8("RandomRadio"));
        RandomRadio->setChecked(true);

        verticalLayout->addWidget(RandomRadio);

        GreedyRadio = new QRadioButton(layoutWidget);
        GreedyRadio->setObjectName(QString::fromUtf8("GreedyRadio"));

        verticalLayout->addWidget(GreedyRadio);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(370, 11, 151, 111));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 32, 109, 42));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ordinalRadio = new QRadioButton(layoutWidget1);
        ordinalRadio->setObjectName(QString::fromUtf8("ordinalRadio"));
        ordinalRadio->setChecked(true);

        verticalLayout_2->addWidget(ordinalRadio);

        partialRadio = new QRadioButton(layoutWidget1);
        partialRadio->setObjectName(QString::fromUtf8("partialRadio"));

        verticalLayout_2->addWidget(partialRadio);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 130, 161, 101));
        probabilityEdit = new QLineEdit(groupBox_4);
        probabilityEdit->setObjectName(QString::fromUtf8("probabilityEdit"));
        probabilityEdit->setGeometry(QRect(69, 17, 41, 20));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 18, 61, 16));
        layoutWidget2 = new QWidget(groupBox_4);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 40, 94, 42));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pointRadio = new QRadioButton(layoutWidget2);
        pointRadio->setObjectName(QString::fromUtf8("pointRadio"));
        pointRadio->setChecked(true);

        verticalLayout_3->addWidget(pointRadio);

        inversionRadio = new QRadioButton(layoutWidget2);
        inversionRadio->setObjectName(QString::fromUtf8("inversionRadio"));

        verticalLayout_3->addWidget(inversionRadio);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(210, 130, 181, 101));
        bettaEdit = new QLineEdit(groupBox_5);
        bettaEdit->setObjectName(QString::fromUtf8("bettaEdit"));
        bettaEdit->setGeometry(QRect(130, 34, 41, 20));
        layoutWidget3 = new QWidget(groupBox_5);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 32, 111, 42));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tournamentRadio = new QRadioButton(layoutWidget3);
        tournamentRadio->setObjectName(QString::fromUtf8("tournamentRadio"));
        tournamentRadio->setChecked(true);

        verticalLayout_4->addWidget(tournamentRadio);

        proportionalRadio = new QRadioButton(layoutWidget3);
        proportionalRadio->setObjectName(QString::fromUtf8("proportionalRadio"));

        verticalLayout_4->addWidget(proportionalRadio);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(400, 130, 121, 131));
        label = new QLabel(groupBox_6);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 17, 61, 16));
        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 43, 61, 16));
        layoutWidget4 = new QWidget(groupBox_6);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(64, 16, 56, 48));
        verticalLayout_6 = new QVBoxLayout(layoutWidget4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        populationEdit = new QLineEdit(layoutWidget4);
        populationEdit->setObjectName(QString::fromUtf8("populationEdit"));

        verticalLayout_6->addWidget(populationEdit);

        iterationsEdit = new QLineEdit(layoutWidget4);
        iterationsEdit->setObjectName(QString::fromUtf8("iterationsEdit"));

        verticalLayout_6->addWidget(iterationsEdit);

        layoutWidget5 = new QWidget(groupBox_6);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(20, 67, 77, 54));
        verticalLayout_5 = new QVBoxLayout(layoutWidget5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(layoutWidget5);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout_5->addWidget(startButton);

        testButton = new QPushButton(layoutWidget5);
        testButton->setObjectName(QString::fromUtf8("testButton"));

        verticalLayout_5->addWidget(testButton);

        GeneticAlgorithmClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GeneticAlgorithmClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 587, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        GeneticAlgorithmClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GeneticAlgorithmClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GeneticAlgorithmClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GeneticAlgorithmClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GeneticAlgorithmClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);

        retranslateUi(GeneticAlgorithmClass);

        QMetaObject::connectSlotsByName(GeneticAlgorithmClass);
    } // setupUi

    void retranslateUi(QMainWindow *GeneticAlgorithmClass)
    {
        GeneticAlgorithmClass->setWindowTitle(QApplication::translate("GeneticAlgorithmClass", "GeneticAlgorithm", nullptr));
        actionOpen->setText(QApplication::translate("GeneticAlgorithmClass", "Open", nullptr));
        actionExit->setText(QApplication::translate("GeneticAlgorithmClass", "Exit", nullptr));
        groupBox->setTitle(QApplication::translate("GeneticAlgorithmClass", "Matrix randomizer", nullptr));
        matrixSize->setText(QApplication::translate("GeneticAlgorithmClass", "Size:", nullptr));
        rndButton->setText(QApplication::translate("GeneticAlgorithmClass", "Randomize", nullptr));
        maxValue->setText(QApplication::translate("GeneticAlgorithmClass", "Max value:", nullptr));
        groupBox_2->setTitle(QApplication::translate("GeneticAlgorithmClass", "Generation", nullptr));
        RandomRadio->setText(QApplication::translate("GeneticAlgorithmClass", "Random", nullptr));
        GreedyRadio->setText(QApplication::translate("GeneticAlgorithmClass", "Greedy", nullptr));
        groupBox_3->setTitle(QApplication::translate("GeneticAlgorithmClass", "Reproduction", nullptr));
        ordinalRadio->setText(QApplication::translate("GeneticAlgorithmClass", "Ordinal", nullptr));
        partialRadio->setText(QApplication::translate("GeneticAlgorithmClass", "Partial reflection", nullptr));
        groupBox_4->setTitle(QApplication::translate("GeneticAlgorithmClass", "Mutation", nullptr));
        label_3->setText(QApplication::translate("GeneticAlgorithmClass", "Probability:", nullptr));
        pointRadio->setText(QApplication::translate("GeneticAlgorithmClass", "Point mutation", nullptr));
        inversionRadio->setText(QApplication::translate("GeneticAlgorithmClass", "Inversion", nullptr));
        groupBox_5->setTitle(QApplication::translate("GeneticAlgorithmClass", "Selection", nullptr));
        tournamentRadio->setText(QApplication::translate("GeneticAlgorithmClass", "Betta-tournament", nullptr));
        proportionalRadio->setText(QApplication::translate("GeneticAlgorithmClass", "Proportional", nullptr));
        groupBox_6->setTitle(QApplication::translate("GeneticAlgorithmClass", "Start", nullptr));
        label->setText(QApplication::translate("GeneticAlgorithmClass", "Population:", nullptr));
        label_2->setText(QApplication::translate("GeneticAlgorithmClass", "Iterations:", nullptr));
        startButton->setText(QApplication::translate("GeneticAlgorithmClass", "Start", nullptr));
        testButton->setText(QApplication::translate("GeneticAlgorithmClass", "TestAll", nullptr));
        menuFile->setTitle(QApplication::translate("GeneticAlgorithmClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneticAlgorithmClass: public Ui_GeneticAlgorithmClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENETICALGORITHM_H
