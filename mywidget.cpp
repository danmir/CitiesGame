#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
// Как и большинство виджетов, он всего лишь вызывает конструктор родительского класса - QWidget'а.
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("Close");
    connect(quit, SIGNAL(clicked()), qApp, SLOT(aboutQt()));

    LCDRange *angle = new LCDRange;
    angle->setRange(5, 70);

    CannonField *cannonField = new CannonField;
    connect(angle, SIGNAL(valueChanged(int)), cannonField, SLOT(setAngle(int)));
    connect(cannonField, SIGNAL(angleChanged(int)), angle, SLOT(setValue(int)));

    QGridLayout *gridLayout = new QGridLayout; // Перешли на более мощное управление
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(angle, 1, 0);
    gridLayout->addWidget(cannonField, 1, 1, 2, 1);
    // Сообщаем QGridLayout о том, что правый столбец (столбец 1) является растягиваемым с коэффициентом растяжения равным 10.
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);

    angle->setValue(60);
    angle->setFocus(); // Фокус для письма
}
