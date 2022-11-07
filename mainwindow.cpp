#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPen"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Create Object From Bin
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);



    ui->customplot->addGraph();
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
   // ui->customplot->xAxis->setVisible(false);

   // ui->customplot->yAxis->setVisible(false);

    ui->customplot->graph(0)->setLineStyle(QCPGraph::lsLine);
    // To Change Color of Graph and Background
    ui->customplot->graph(0)->setPen(QPen(QColor(33, 212, 253)));
    ui->customplot->axisRect()->setBackground(QColor(101, 13, 217));


    // For Zooming Or Drag
    ui->customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    // to Name Axis and Range and Change Color oF Axix
    ui->customplot->xAxis->setLabel("X");
    ui->customplot->yAxis->setLabel("Y");
    ui->customplot->xAxis->labelFont();
    ui->customplot->xAxis->setRange(-1, 1);
    ui->customplot->yAxis->setRange(-1, 1);

    ui->customplot->xAxis->setLabelColor(QColor(11, 129, 158));
    ui->customplot->yAxis->setLabelColor(QColor(219, 13, 175));
    ui->customplot->yAxis->setTickLabelColor(QColor(219, 13, 175));
    ui->customplot->xAxis->setTickLabelColor(QColor(11, 129, 158));
    ui->customplot->xAxis->selectedTickLabelColor().blue();

    // Enter Data
    double secs = QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime());
    int n = 500;
    double phase = secs*5;
    double k = 3;
    QVector<double> x(n), y(n);
    for (int i=0; i<n; ++i)
    {
      x[i] = i/(double)(n-1)*34 - 17;
      y[i] = qExp(-x[i]*x[i]/20.0)*qSin(k*x[i]+phase);
    }
       ui->customplot->graph(0)->setData(x, y);
       ui->customplot->graph(0)->rescaleAxes();
       ui->customplot->replot();
       ui->customplot->update();


    // Timer
    /*time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(repeatGraph()));
    time->start(500);*/




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::repeatGraph()
{



}

