#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include<QDebug>

/*!
 * \brief The Calculator class
 * Klasa która realizuje całą logikę zawartą w kalkulatorze
 */

class Calculator : public QWidget
{
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = 0);   ///<Konstruktor Klasy Calculator
signals:
    void displayChanged(QString);       ///< metoda odpowiadająca za zmianę tekstu wyświetlanego na wyświetlaczu głównym
    void displayChanged10(QString);     ///< metoda odpowiadająca za zmianę tekstu wyświetlanego na wyświetlaczu pomocniczym

public slots:
    void numEntered(int);               ///<metoda dopasowująca wyświetlany tekst to aktualnego systemu
    void wyswietlaj_wynik();            ///<metoda wyświetlająca wynik na wyświetlaczu
    void wyswietlaj_aktualny();         ///<metoda wyświetlająca aktualną liczbę na wyświetlaczu
    void clear();                       ///<metoda zerująca aktualną liczbę
    void allClear();                    ///<metoda zerująca aktualną liczbę i ostatni wynik
    void additionMode();                ///<metoda załącza tryb dodawania
    void substractionMode();            ///<metoda załącza tryb odejmowania
    void multiplicationMode();          ///<metoda załącza tryb mnożenia
    void divisionMode();                ///<metoda załącza tryb dzielenia
    void calculate();                   ///<metoda wykonująca obliczenia
    void dwojkowy();                    ///<metoda ustawiająca system liczbowy na dwójkowy
    void szesnastkowy();                ///<metoda ustawiająca system liczbowy na szesnastkowy
    void osemkowy();                    ///<metoda ustawiająca system liczbowy na ósemkowy
    void dziesietny();                  ///<metoda ustawiająca system liczbowy na dziesiętny
    void przesuniecieLewo();            ///<metoda załącza tryb przesunięcia bitowego w lewo
    void przesunieciePrawo();           ///<metoda załącza tryb przesunięcia bitowego w prawo
    void memoryAdd();                   ///<metoda dodająca wartość do pamięci
    void memoryMinus();                 ///<metoda odejmująca daną wartość od pamięci
    void memoryClear();                 ///<metoda zerująca pamięć
    void memoryRecall();                ///<metoda wyświetlająca liczbę w pamięci na wyświetlaczu


private:
    int m_lastResult;                   ///<zmienna przechowująca wynik
    int m_currentNumebr;                ///<zmienna przechowująca aktualną liczbę
    int m_operation;                    ///<zmienna przechowująca typ aktualnej operacji
    int m_system;                       ///<zmienna przechowująca aktualny system liczbowy
    int m_memoryResult;                 ///<zmienna przechowująca wartość liczbową w pamięci

};

#endif // CALCULATOR_H
