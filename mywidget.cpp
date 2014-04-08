#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
// Как и большинство виджетов, он всего лишь вызывает конструктор родительского класса - QWidget'а.
    : QWidget(parent)
{
    // setFixedSize(200, 120); // Устанавливаем фиксированный размер окна

    // Здесь мы создаем и настраиваем дочерний виджет (родителем создаваемого виджета будет this, т.е. объект MyWidget).
    // Вызов функции tr() позволяет перевести текст на кнопке "Quit" на другой язык на основании содержимого файла перевода.
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    // quit является локальной переменной в нашем конструкторе. MyWidget не следит за ней;
    // Qt заботится о ней и удалит её автоматически, когда придёт время уничтожать MyWidget. Поэтому MyWidget не нуждается в деструкторе.

    QGridLayout *grid = new QGridLayout;
    LCDRange *previousRange = 0;

    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            LCDRange *lcdRange = new LCDRange;
            grid->addWidget(lcdRange, row, column);
            if (previousRange)
                connect(lcdRange, SIGNAL(valueChanged(int)),
                        previousRange, SLOT(setValue(int)));
            previousRange = lcdRange;
        }
    }

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addLayout(grid);
    setLayout(layout);
}
