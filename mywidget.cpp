#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
// Как и большинство виджетов, он всего лишь вызывает конструктор родительского класса - QWidget'а.
    : QWidget(parent)
{
    setFixedSize(200, 120); // Устанавливаем фиксированный размер окна

    // Здесь мы создаем и настраиваем дочерний виджет (родителем создаваемого виджета будет this, т.е. объект MyWidget).
    // Вызов функции tr() позволяет перевести текст на кнопке "Quit" на другой язык на основании содержимого файла перевода.
    QPushButton *quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(62, 40, 75, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));
    // quit является локальной переменной в нашем конструкторе. MyWidget не следит за ней;
    // Qt заботится о ней и удалит её автоматически, когда придёт время уничтожать MyWidget. Поэтому MyWidget не нуждается в деструкторе.

    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    // std::cout << slider->value();
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    // MyWidget теперь использует QVBoxLayout для управления размещением своих дочерних виджетов.
    QVBoxLayout *layout = new QVBoxLayout;
    // При этом компоновка является потомком MyWidget, потому мы можем не заботится о её удалении;
    //связь родитель-потомок гарантирует, что она будет удалена вместе с MyWidget
    // Также, при вызове QWidget::setLayout() наши виджеты автоматически становятся дочерними виджетами MyWidget.
    layout->addWidget(quit);
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}
