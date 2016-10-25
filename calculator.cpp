#include "calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),m_lastResult(0), m_currentNumebr(0), m_operation(0),m_wynik(0)
{
}

void Calculator::dwojkowy()
{
   QString s = QString::number(m_wynik,2);
   emit displayChanged(s);
}

void Calculator::szesnastkowy()
{
    QString s = QString::number(m_wynik,16);
    emit displayChanged(s);

}

void Calculator::osemkowy()
{
    QString s = QString::number(m_wynik,8);
    emit displayChanged(s);

}

void Calculator::przesuniecieLewo()
{
    m_operation=5;
}

void Calculator::przesunieciePrawo()
{
    m_operation=6;
}

void Calculator::numEntered(int a)
{
    if(m_currentNumebr==0)
{
        m_currentNumebr=a;
 }
 else
 {
    m_lastResult=m_currentNumebr;
    m_currentNumebr=a;
 }


 QString s = QString::number(a);
 emit displayChanged(s);
}

void Calculator::clear()
{
m_currentNumebr=0;
emit displayChanged("0");

}

void Calculator::allClear()
{
    m_currentNumebr=0;
    m_lastResult=0;
    emit displayChanged("0");

}

void Calculator::additionMode()
{
m_operation=1;
}
void Calculator::substractionMode()
{
m_operation=2;
}
void Calculator::multiplicationMode()
{
m_operation=3;
}
void Calculator::divisionMode()
{
m_operation=4;
}
void Calculator::calculate()
{

    if(m_operation==1)
    m_wynik=m_lastResult+m_currentNumebr;
    if(m_operation==2)
    m_wynik=m_lastResult-m_currentNumebr;
    if(m_operation==3)
    m_wynik=m_lastResult*m_currentNumebr;
    if(m_operation==4)
    m_wynik=m_lastResult/m_currentNumebr;
    if(m_operation==5)
    m_wynik=m_lastResult<<m_currentNumebr;
    if(m_operation==6)
    m_wynik=m_lastResult>>m_currentNumebr;

    emit displayChanged((QString::number(m_wynik)));

}
