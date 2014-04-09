#ifndef CANNONFIELD_H
#define CANNONFIELD_H

#include <QWIdget>
#include <QPainter>

class CannonField : public QWidget
{
    Q_OBJECT
public:
    CannonField(QWidget *parent = 0);
    int currentAngle;
    int angle() const { return currentAngle; }

signals:
    void angleChanged(int newAngle);

public slots:
    void setAngle(int angle);

protected:
    void paintEvent(QPaintEvent *event); //  Данная виртуальная функция вызывается Qt всякий раз, когда виджету нужно обновиться (т.е., нарисовать поверхность виджета).

};

#endif // CANNONFIELD_H
