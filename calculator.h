#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include<QDebug>

class Calculator : public QWidget
{
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = 0);

signals:
    void displayChanged(QString);



public slots:
    void numEntered(int);

    void clear();
    void allClear();

    void additionMode();
    void substractionMode();

    void multiplicationMode();
    void divisionMode();

    void calculate();

private:
    int m_lastResult;
    int m_currentNumebr;
    bool m_isAdding;

};

#endif // CALCULATOR_H
