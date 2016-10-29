#include "calculator.h"
/*!
 * \brief Calculator::Calculator -Konstruktor klasy Calculator
 * \param parent - wskaźnik na obiekt nadrzędny
 */
Calculator::Calculator(QWidget *parent) :
    QWidget(parent),m_lastResult(0), m_currentNumebr(0), m_operation(0),m_system(10)
{
}
/*!
 * \brief Calculator::dwojkowy - Funckja zmieniająca systemu na dwójkowy
 */
void Calculator::dwojkowy()
{
   m_system=2;
   if(m_currentNumebr !=0)
   {
       wyswietlaj_aktualny();
   }
   else wyswietlaj_wynik();
}
/*!
 * \brief Calculator::szesnastkowy - Funkcja zmieniająca system na szesnastkowy
 */
void Calculator::szesnastkowy()
{
    m_system=16;
    if(m_currentNumebr !=0)
    {
        wyswietlaj_aktualny();
    }
    else wyswietlaj_wynik();
}
/*!
 * \brief Calculator::osemkowy -Funkcja zmieniająca system na ósemkowy
 */
void Calculator::osemkowy()
{
    m_system=8;
    if(m_currentNumebr !=0)
       {wyswietlaj_aktualny();
    }
    else wyswietlaj_wynik();
}
/*!
 * \brief Calculator::dziesietny - Funkcja zmieniająca system na dziesiętny
 */
void Calculator::dziesietny()
{
    m_system=10;
    if(m_currentNumebr !=0)
     {
        wyswietlaj_aktualny();
    }
    else wyswietlaj_wynik();
}
/*!
 * \brief Calculator::przesuniecieLewo - Funckja załączająca tryb przesunięcie bitowe w lewo
 */
void Calculator::przesuniecieLewo()
{
    m_operation=5;
    calculate();
}
/*!
 * \brief Calculator::przesunieciePrawo - Funckja załączająca tryb przesunięcie bitowe w prawo
 */
void Calculator::przesunieciePrawo()
{
    m_operation=6;
    calculate();
}
/*!
 * \brief Calculator::memoryAdd - Funckja dodająca liczbę do pamięci programu
 */
void Calculator::memoryAdd()
{
    m_memoryResult+=m_lastResult;
}
/*!
 * \brief Calculator::memoryMinus - Funkcja odejmująca liczbę od wartości zapisanej w pamięci
 */
void Calculator::memoryMinus()
{
    m_memoryResult-=m_lastResult;
}
/*!
 * \brief Calculator::memoryClear - Funckja zerująca liczbę zapisaną w pamięci
 */
void Calculator::memoryClear()
{
    m_memoryResult=0;
}
/*!
 * \brief Calculator::memoryRecall - Funckja wyświetlająca wartość zapisaną w pamięci
 */
void Calculator::memoryRecall()
{
    emit displayChanged(QString::number(m_memoryResult,m_system));
    emit displayChanged10(QString::number(m_memoryResult,10));
}
/*!
 * \brief Calculator::numEntered - funckja odpowiadająca za obliczenia aktualnej liczby według
 * ustawionego systemu liczbowego i wyświetlanie aktualnej liczby na wyświetlaczu
 * \param a
 */
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
/*!
 * \brief Calculator::wyswietlaj_wynik - Funkcja wyświetlająca wartość przechowywaną w zmiennej m_lastResult
 */
void Calculator::wyswietlaj_wynik()
{
    emit displayChanged(QString::number(m_lastResult,m_system));
    emit displayChanged10(QString::number(m_lastResult,10));
}
/*!
 * \brief Calculator::wyswietlaj_aktualny - Funkcja wyświetlająca wartość przechowywaną w zmiennej m_currentNumber
 */
void Calculator::wyswietlaj_aktualny()
{
    emit displayChanged(QString::number(m_currentNumebr,m_system));
    emit displayChanged10(QString::number(m_lastResult,10));
}
/*!
 * \brief Calculator::clear - Funkcja zerująca aktualną liczbę
 */
void Calculator::clear()
{
m_currentNumebr=0;
wyswietlaj_aktualny();
}
/*!
 * \brief Calculator::allClear - Funckja zerująca aktualną liczbę i ostatni wynik
 */
void Calculator::allClear()
{
m_currentNumebr=0;
m_lastResult=0;
wyswietlaj_aktualny();
}
/*!
 * \brief Calculator::additionMode - Funkcja załączająca tryb dodawanie
 */
void Calculator::additionMode()
{
m_operation=1;
calculate();
}
/*!
 * \brief Calculator::substractionMode -Funkcja załączająca tryb odejmowanie
 */
void Calculator::substractionMode()
{
m_operation=2;
calculate();
}
/*!
 * \brief Calculator::multiplicationMode -Funkcja załączająca tryb mnożenie
 */
void Calculator::multiplicationMode()
{
m_operation=3;
calculate();
}
/*!
 * \brief Calculator::divisionMode - Funkcja załączająca tryb dzielenie
 */
void Calculator::divisionMode()
{
m_operation=4;
calculate();
}
/*!
 * \brief Calculator::calculate - Funkcja odpowiadająca za wykonywanie obliczeń i ustawianie zmiennych
 * m_lastResult i m_currentNumebr
 */
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
