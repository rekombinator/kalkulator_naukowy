#include "calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),m_lastResult(0), m_currentNumebr(0), m_isAdding(true)
{
}

void Calculator::numEntered(int a)
{
    if(m_currentNumebr==0)
{
        m_currentNumebr=a;
  // m_lastResult=m_currentNumebr;
 }
 else
 {
        m_lastResult=m_currentNumebr;
        m_currentNumebr=a;
 }
 QString s = QString::number(a);
 qDebug()<<m_currentNumebr;
 qDebug()<<m_lastResult;

 emit displayChanged(s);
}

void Calculator::clear()
{


}

void Calculator::allClear()
{


}

void Calculator::additionMode()
{
m_isAdding=true;


}

void Calculator::substractionMode()
{
    m_isAdding=false;

}

void Calculator::multiplicationMode()
{

}

void Calculator::divisionMode()
{

}

void Calculator::calculate()
{
    int wynik;
    if(m_isAdding==true)
    wynik=m_lastResult+m_currentNumebr;
    if(m_isAdding==false)
    wynik=m_lastResult-m_currentNumebr;
   // m_lastResult+= m_isAdding?m_currentNumebr:-m_currentNumebr;
   // m_currentNumebr = 0; zeruj flage
    emit displayChanged((QString::number(wynik)));

}
