#include "calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),m_lastResult(0), m_currentNumebr(0), m_operation(0),m_system(10)
{
}

void Calculator::dwojkowy()
{
   m_system=2;
   if(m_currentNumebr !=0)
   {
       wyswietlaj_aktualny();
   }
   else wyswietlaj_wynik();
}

void Calculator::szesnastkowy()
{
    m_system=16;
    if(m_currentNumebr !=0)
    {
        wyswietlaj_aktualny();
    }
    else wyswietlaj_wynik();

}

void Calculator::osemkowy()
{
    m_system=8;
    if(m_currentNumebr !=0)
       {wyswietlaj_aktualny();
    }
    else wyswietlaj_wynik();

}

void Calculator::dziesietny()
{
    m_system=10;
    if(m_currentNumebr !=0)
     {
        wyswietlaj_aktualny();
    }
    else wyswietlaj_wynik();
}

void Calculator::przesuniecieLewo()
{
    m_operation=5;
    calculate();

}

void Calculator::przesunieciePrawo()
{
    m_operation=6;
    calculate();

}

void Calculator::memoryAdd()
{
    m_memoryResult+=m_lastResult;
}

void Calculator::memoryMinus()
{
    m_memoryResult-=m_lastResult;
}

void Calculator::memoryClear()
{
    m_memoryResult=0;
}

void Calculator::memoryRecall()
{
    emit displayChanged(QString::number(m_memoryResult,m_system));
    emit displayChanged10(QString::number(m_memoryResult,10));
}

void Calculator::numEntered(int a)
{

if(m_system==10)
{
    m_currentNumebr=m_currentNumebr*10+a;

}
if(m_system==2)
{
    m_currentNumebr=m_currentNumebr*2+a;

}
if(m_system==8)
{
    m_currentNumebr=m_currentNumebr*8+a;

}
if(m_system==16)
{
    m_currentNumebr=m_currentNumebr*16+a;

}

wyswietlaj_aktualny();

}

void Calculator::wyswietlaj_wynik()
{

    emit displayChanged(QString::number(m_lastResult,m_system));
    emit displayChanged10(QString::number(m_lastResult,10));
}

void Calculator::wyswietlaj_aktualny()
{
    emit displayChanged(QString::number(m_currentNumebr,m_system));
    emit displayChanged10(QString::number(m_lastResult,10));
}


void Calculator::clear()
{
m_currentNumebr=0;
wyswietlaj_aktualny();

}

void Calculator::allClear()
{
m_currentNumebr=0;
m_lastResult=0;
wyswietlaj_aktualny();

}

void Calculator::additionMode()
{
m_operation=1;
calculate();
}
void Calculator::substractionMode()
{
m_operation=2;
calculate();
}
void Calculator::multiplicationMode()
{
m_operation=3;
calculate();
}
void Calculator::divisionMode()
{
m_operation=4;
calculate();

}
void Calculator::calculate()
{
    if(m_lastResult==0)
    {m_lastResult=m_currentNumebr;
     }
    else if(m_currentNumebr==0)
    {return ;
    }
    else
    {
    if(m_operation==1)
    m_lastResult=m_lastResult+m_currentNumebr;
    if(m_operation==2)
    m_lastResult=m_lastResult-m_currentNumebr;
    if(m_operation==3)
    m_lastResult=m_lastResult*m_currentNumebr;
    if(m_operation==4)
    m_lastResult=m_lastResult/m_currentNumebr;
    if(m_operation==5)
    m_lastResult=m_lastResult<<m_currentNumebr;
    if(m_operation==6)
    m_lastResult=m_lastResult>>m_currentNumebr;
    }

m_currentNumebr=0;

wyswietlaj_wynik();


}
