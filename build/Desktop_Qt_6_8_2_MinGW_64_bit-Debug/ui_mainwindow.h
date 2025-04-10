/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QPushButton *startButton;
    QPushButton *redButton;
    QPushButton *blueButton;
    QLabel *gameOverLabel;
    QLabel *gameStartLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(160, 20, 481, 51));
        progressBar->setValue(0);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(340, 500, 131, 41));
        redButton = new QPushButton(centralwidget);
        redButton->setObjectName("redButton");
        redButton->setGeometry(QRect(160, 160, 231, 231));
        QFont font;
        font.setPointSize(20);
        redButton->setFont(font);
        blueButton = new QPushButton(centralwidget);
        blueButton->setObjectName("blueButton");
        blueButton->setGeometry(QRect(410, 160, 231, 231));
        blueButton->setFont(font);
        gameOverLabel = new QLabel(centralwidget);
        gameOverLabel->setObjectName("gameOverLabel");
        gameOverLabel->setGeometry(QRect(160, 90, 481, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Stencil")});
        font1.setPointSize(40);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setKerning(false);
        gameOverLabel->setFont(font1);
        gameOverLabel->setAutoFillBackground(false);
        gameOverLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gameStartLabel = new QLabel(centralwidget);
        gameStartLabel->setObjectName("gameStartLabel");
        gameStartLabel->setEnabled(true);
        gameStartLabel->setGeometry(QRect(30, 20, 741, 461));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Impact")});
        font2.setPointSize(20);
        gameStartLabel->setFont(font2);
        gameStartLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        redButton->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        blueButton->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        gameOverLabel->setText(QCoreApplication::translate("MainWindow", "You Lose!", nullptr));
        gameStartLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Welcome to the Simon Game!<br/></p><p>The computer will play a sequence of moves, </p><p>and your job is to copy the moves in the correct order </p><p>to proceed to the next round.</p><p><br/></p><p>Each round will get faster and faster, so good luck!</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
