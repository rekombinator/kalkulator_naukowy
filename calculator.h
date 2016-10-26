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
    void displayChanged10(QString);


public slots:
    void numEntered(int);


    void clear();
    void allClear();

    void additionMode();
    void substractionMode();

    void multiplicationMode();
    void divisionMode();

    void calculate();

    void dwojkowy();
    void szesnastkowy();
    void osemkowy();
    void dziesietny();

    void przesuniecieLewo();
    void przesunieciePrawo();


private:
    int m_lastResult;
    int m_currentNumebr;
    int m_operation;
    int m_wynik;
    int m_system;

};

#endif // CALCULATOR_H
