#include "calculatorinterface.h"
#include "ui_calculatorinterface.h"
#include <QSignalMapper>

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

  connect(ui->button_plus,SIGNAL(clicked()),m_calculator,SLOT(additionMode()));
  connect(ui->button_minus,SIGNAL(clicked()),m_calculator,SLOT(substractionMode()));
  connect(ui->button_razy,SIGNAL(clicked()),m_calculator,SLOT(multiplicationMode()));
  connect(ui->button_dziel,SIGNAL(clicked()),m_calculator,SLOT(divisionMode()));
  connect(ui->button_rowna,SIGNAL(clicked()),m_calculator,SLOT(calculate()));
  connect(ui->button_lewo,SIGNAL(clicked()),m_calculator,SLOT(przesuniecieLewo()));
  connect(ui->button_prawo,SIGNAL(clicked()),m_calculator,SLOT(przesunieciePrawo()));
  connect(ui->button_AC,SIGNAL(clicked()),m_calculator,SLOT(allClear()));
  connect(ui->button_C,SIGNAL(clicked()),m_calculator,SLOT(clear()));

  connect(ui->button_dwa,SIGNAL(clicked()),m_calculator,SLOT(dwojkowy()));
connect(ui->button_osiem,SIGNAL(clicked()),m_calculator,SLOT(osemkowy()));
connect(ui->button_szesnascie,SIGNAL(clicked()),m_calculator,SLOT(szesnastkowy()));
connect(ui->button_dziesiec,SIGNAL(clicked()),m_calculator,SLOT(dziesietny()));


    connect(signalMapper,SIGNAL(mapped(int)),m_calculator,SLOT(numEntered(int)));
    connect(m_calculator,SIGNAL(displayChanged(QString)),ui->label,SLOT(setText(QString)));
    connect(m_calculator,SIGNAL(displayChanged10(QString)),ui->label_dziesietny,SLOT(setText(QString)));


}

CalculatorInterface::~CalculatorInterface()
{
    delete ui;
    delete m_calculator;
}
