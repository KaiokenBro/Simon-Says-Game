/**
 * @file main.cpp
 *
 * Team Members:
 * - Victor Valdez Landa
 * - Harrison Doppelt
 *
 * GitHub Usernames:
 * - KaiokenBro
 * - hdoppelt
 *
 * Repository:
 * - https://github.com/UofU-CS3505/cs3505-assignment6-KaiokenBro
 *
 * Creative Element:
 * - Added unique sound effects for each button press.
 *
 * @date 03/13/2025
 */

#include "mainwindow.h"
#include "model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    MainWindow w(&m);
    QApplication::setStyle("Fusion");
    w.show();
    return a.exec();
}
