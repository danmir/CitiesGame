#include "cannonfield.h"

CannonField::CannonField(QWidget *parent) :
    QWidget(parent)
{
    currentAngle = 45;
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
}

void CannonField::setAngle(int angle)
{
    if (angle < 5)
        angle = 5;
    if (angle > 70)
        angle = 70;
    if (currentAngle == angle)
        return;
    currentAngle = angle;
    update();
    // Функция QWidget::update() очистит виджет (обычно его заливают цветом фона) и отправляет событие рисования виджету.
    // Это приводит к вызову функции события рисования виджета.
    emit angleChanged(currentAngle);
    // Испускается сигнал angleChanged() чтобы сообщить всем остальным виджетам о том, что угол возвышения изменился
}

void CannonField::paintEvent(QPaintEvent * /* event */)
{
     QPainter painter(this);
     painter.drawText(200, 200, tr("Angle = ") + QString::number(currentAngle));
}
