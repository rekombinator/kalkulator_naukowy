#include "calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),m_lastResult(0), m_currentNumebr(0), m_operation(0),m_wynik(0),m_system(10)
{
}

void Calculator::dwojkowy()
{
   m_system=2;
    QString s = QString::number(m_wynik,2);
   emit displayChanged(s);
}

void Calculator::szesnastkowy()
{
    m_system=16;
    QString s = QString::number(m_wynik,16);
    emit displayChanged(s);

}

void Calculator::osemkowy()
{
    m_system=8;
    QString s = QString::number(m_wynik,8);
    emit displayChanged(s);

}

void Calculator::dziesietny()
{
    m_system=10;
    QString s = QString::number(m_wynik,10);
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
  QString s,s1;
if(m_system==10)
s = QString::number(a,10);
if(m_system==2)
s = QString::number(a,2);
if(m_system==8)
s = QString::number(a,8);
if(m_system==16)
s = QString::number(a,16);

s1=QString::number(a,10);
emit displayChanged(s);
emit displayChanged10(s1);

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

    QString s,s1;
    if(m_system==10)
    s = QString::number(m_wynik,10);
    if(m_system==2)
    s = QString::number(m_wynik,2);
    if(m_system==8)
    s = QString::number(m_wynik,8);
    if(m_system==16)
    s = QString::number(m_wynik,16);

    m_operation=0;

    s1=QString::number(m_wynik,10);
    emit displayChanged(s);
    emit displayChanged10(s1);

}
