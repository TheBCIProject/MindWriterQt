#include "mainwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QTextEdit>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
