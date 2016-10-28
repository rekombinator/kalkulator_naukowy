#ifndef CALCULATORINTERFACE_H
#define CALCULATORINTERFACE_H

#include <QWidget>
#include"calculator.h"

namespace Ui {
class CalculatorInterface;
}

class CalculatorInterface : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorInterface(QWidget *parent = 0);
    ~CalculatorInterface();

private slots:
    void on_button_dziesiec_clicked();

    void on_button_dwa_clicked();

    void on_button_osiem_clicked();

    void on_button_szesnascie_clicked();

private:
    Ui::CalculatorInterface *ui;
    Calculator *m_calculator;
};

#endif // CALCULATORINTERFACE_H
