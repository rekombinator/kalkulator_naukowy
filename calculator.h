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
    void wyswietlaj_wynik();
    void wyswietlaj_aktualny();

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

    void memoryAdd();
    void memoryMinus();
    void memoryClear();
    void memoryRecall();


private:
    int m_lastResult;
    int m_currentNumebr;
    int m_operation;
    int m_system;
    int m_memoryResult;

};

#endif // CALCULATOR_H
