#ifndef LCDRANGE_H
#define LCDRANGE_H

#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

class LCDRange : public QWidget
 {
     Q_OBJECT // Этот макрос должен быть включён во все классы, которые используют сигналы или слоты.

 public:
     LCDRange(QWidget *parent = 0);
     // value() - открытая функция для получения доступа к значению LCDRange
     int value() const;

 public slots:
     void setValue(int value);

 signals:
     void valueChanged(int newValue);

 private:
     QSlider *slider;
 };

#endif // LCDRANGE_H
