#ifndef CALCULATORINTERFACE_H
#define CALCULATORINTERFACE_H

#include <QWidget>
#include"calculator.h"

namespace Ui {
/*!
 * Klasa zarządzająca interfejsem użytkownika
 */
class CalculatorInterface;
}

class CalculatorInterface : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorInterface(QWidget *parent = 0);  ///<Konstruktor Klasy CalculatorInterface
    ~CalculatorInterface();                             ///<Destruktor Klasy CalculatorInterface

private slots:
    void on_button_dziesiec_clicked();                  ///<metoda odpowidzialna za zmianę aktywnych klawiszy dla systemu dziesiętnego
    void on_button_dwa_clicked();                       ///<metoda odpowidzialna za zmianę aktywnych klawiszy dla systemu dwójkowego
    void on_button_osiem_clicked();                     ///<metoda odpowidzialna za zmianę aktywnych klawiszy dla systemu ósemkowego
    void on_button_szesnascie_clicked();                ///<metoda odpowidzialna za zmianę aktywnych klawiszy dla systemu szesnastkowego

private:
    Ui::CalculatorInterface *ui;                        ///<wskaźnik na interfejs użytkownika
    Calculator *m_calculator;                           ///<wskaźnik na część logiczną kalkulatora
};

#endif // CALCULATORINTERFACE_H
