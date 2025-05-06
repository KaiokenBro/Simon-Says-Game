/**
 * @file main.cpp
 * @authors Victor Valdez Landa, Harrison Doppelt
 * @date 03/13/2025
 */

#include "mainwindow.h"
#include "model.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Model m;
    MainWindow w(&m);
    QApplication::setStyle("Fusion");
    w.show();
    return a.exec();
}
