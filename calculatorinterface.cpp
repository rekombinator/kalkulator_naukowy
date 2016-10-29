#include "calculatorinterface.h"
#include "ui_calculatorinterface.h"
#include <QSignalMapper>
/*!
 * \brief CalculatorInterface::CalculatorInterface - Konstruktor Klasy CalculatorInterface
 * \param parent - wskaźnik na obiekt nadrzędny
 */
CalculatorInterface::CalculatorInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorInterface),m_calculator(new Calculator(this))
{
    ui->setupUi(this);


    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(ui->button_0,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_0,0);
     connect(ui->button_1,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_1,1);
     connect(ui->button_2,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_2,2);
     connect(ui->button_3,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_3,3);
     connect(ui->button_4,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_4,4);
     connect(ui->button_5,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_5,5);
     connect(ui->button_6,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_6,6);
     connect(ui->button_7,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_7,7);
    connect(ui->button_8,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_8,8);
    connect(ui->button_9,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_9,9);
    connect(ui->button_A,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_A,10);
     connect(ui->button_B,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_B,11);
    connect(ui->button_C,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_C,12);
    connect(ui->button_D,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_D,13);
    connect(ui->button_E,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_E,14);
    connect(ui->button_F,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(ui->button_F,15);

  connect(ui->button_plus,SIGNAL(clicked()),m_calculator,SLOT(additionMode()));
  connect(ui->button_minus,SIGNAL(clicked()),m_calculator,SLOT(substractionMode()));
  connect(ui->button_razy,SIGNAL(clicked()),m_calculator,SLOT(multiplicationMode()));
  connect(ui->button_dziel,SIGNAL(clicked()),m_calculator,SLOT(divisionMode()));
  connect(ui->button_rowna,SIGNAL(clicked()),m_calculator,SLOT(calculate()));
  connect(ui->button_lewo,SIGNAL(clicked()),m_calculator,SLOT(przesuniecieLewo()));
  connect(ui->button_prawo,SIGNAL(clicked()),m_calculator,SLOT(przesunieciePrawo()));
  connect(ui->button_AC,SIGNAL(clicked()),m_calculator,SLOT(allClear()));
  connect(ui->button_Clear,SIGNAL(clicked()),m_calculator,SLOT(clear()));
  connect(ui->button_Mplus,SIGNAL(clicked()),m_calculator,SLOT(memoryAdd()));
  connect(ui->button_Mminus,SIGNAL(clicked()),m_calculator,SLOT(memoryMinus()));
  connect(ui->button_Mclear,SIGNAL(clicked()),m_calculator,SLOT(memoryClear()));
  connect(ui->button_Mprzywroc,SIGNAL(clicked()),m_calculator,SLOT(memoryRecall()));

  connect(ui->button_dwa,SIGNAL(clicked()),m_calculator,SLOT(dwojkowy()));
  connect(ui->button_osiem,SIGNAL(clicked()),m_calculator,SLOT(osemkowy()));
  connect(ui->button_szesnascie,SIGNAL(clicked()),m_calculator,SLOT(szesnastkowy()));
  connect(ui->button_dziesiec,SIGNAL(clicked()),m_calculator,SLOT(dziesietny()));


  connect(signalMapper,SIGNAL(mapped(int)),m_calculator,SLOT(numEntered(int)));
  connect(m_calculator,SIGNAL(displayChanged(QString)),ui->label,SLOT(setText(QString)));
  connect(m_calculator,SIGNAL(displayChanged10(QString)),ui->label_dziesietny,SLOT(setText(QString)));

  ui->button_A->setEnabled(false);
  ui->button_B->setEnabled(false);
  ui->button_C->setEnabled(false);
  ui->button_D->setEnabled(false);
  ui->button_E->setEnabled(false);
  ui->button_F->setEnabled(false);
  ui->button_0->setEnabled(true);
  ui->button_1->setEnabled(true);
  ui->button_2->setEnabled(true);
  ui->button_3->setEnabled(true);
  ui->button_4->setEnabled(true);
  ui->button_5->setEnabled(true);
  ui->button_6->setEnabled(true);
  ui->button_7->setEnabled(true);
  ui->button_8->setEnabled(true);
  ui->button_9->setEnabled(true);


}
/*!
 * \brief CalculatorInterface::~CalculatorInterface - Desktruktor Klasy CalculatorInterface
 */
CalculatorInterface::~CalculatorInterface()
{
    delete ui;
    delete m_calculator;
}

void CalculatorInterface::on_button_dziesiec_clicked()
{
    ui->button_A->setEnabled(false);
    ui->button_B->setEnabled(false);
    ui->button_C->setEnabled(false);
    ui->button_D->setEnabled(false);
    ui->button_E->setEnabled(false);
    ui->button_F->setEnabled(false);
    ui->button_0->setEnabled(true);
    ui->button_1->setEnabled(true);
    ui->button_2->setEnabled(true);
    ui->button_3->setEnabled(true);
    ui->button_4->setEnabled(true);
    ui->button_5->setEnabled(true);
    ui->button_6->setEnabled(true);
    ui->button_7->setEnabled(true);
    ui->button_8->setEnabled(true);
    ui->button_9->setEnabled(true);

}

void CalculatorInterface::on_button_dwa_clicked()
{
    ui->button_A->setEnabled(false);
    ui->button_B->setEnabled(false);
    ui->button_C->setEnabled(false);
    ui->button_D->setEnabled(false);
    ui->button_E->setEnabled(false);
    ui->button_F->setEnabled(false);
    ui->button_0->setEnabled(true);
    ui->button_1->setEnabled(true);
    ui->button_2->setEnabled(false);
    ui->button_3->setEnabled(false);
    ui->button_4->setEnabled(false);
    ui->button_5->setEnabled(false);
    ui->button_6->setEnabled(false);
    ui->button_7->setEnabled(false);
    ui->button_8->setEnabled(false);
    ui->button_9->setEnabled(false);
}

void CalculatorInterface::on_button_osiem_clicked()
{
    ui->button_A->setEnabled(false);
    ui->button_B->setEnabled(false);
    ui->button_C->setEnabled(false);
    ui->button_D->setEnabled(false);
    ui->button_E->setEnabled(false);
    ui->button_F->setEnabled(false);
    ui->button_0->setEnabled(true);
    ui->button_1->setEnabled(true);
    ui->button_2->setEnabled(true);
    ui->button_3->setEnabled(true);
    ui->button_4->setEnabled(true);
    ui->button_5->setEnabled(true);
    ui->button_6->setEnabled(true);
    ui->button_7->setEnabled(true);
    ui->button_8->setEnabled(false);
    ui->button_9->setEnabled(false);
}

void CalculatorInterface::on_button_szesnascie_clicked()
{
    ui->button_A->setEnabled(true);
    ui->button_B->setEnabled(true);
    ui->button_C->setEnabled(true);
    ui->button_D->setEnabled(true);
    ui->button_E->setEnabled(true);
    ui->button_F->setEnabled(true);
    ui->button_0->setEnabled(true);
    ui->button_1->setEnabled(true);
    ui->button_2->setEnabled(true);
    ui->button_3->setEnabled(true);
    ui->button_4->setEnabled(true);
    ui->button_5->setEnabled(true);
    ui->button_6->setEnabled(true);
    ui->button_7->setEnabled(true);
    ui->button_8->setEnabled(true);
    ui->button_9->setEnabled(true);
}
