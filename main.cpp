#include "mainwindow.h"
#include "mywidget.h"
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QWidget>

int main(int argc, char *argv[])
{      
    QApplication a(argc, argv);

    MyWidget widget; // Создаем свой виджет

    QWidget window;
    window.resize(200, 100);
    QPushButton quit("Quit", &window); // Сделали родительский виджет
    quit.setGeometry(10, 40, 180, 40); // Разместили его в окне x,y - коорд отн главного окна, далее размер
    //quit.resize(75, 30);
    //quit.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&quit, SIGNAL(clicked()), &a, SLOT(quit()));

    QPushButton hello("Hello world!");

    //hello.show();
    //quit.show();
    //window.show();
    widget.show();
    return a.exec();
}
