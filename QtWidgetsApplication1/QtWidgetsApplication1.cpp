#include "QtWidgetsApplication1.h"
#include "cmath"



QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::QtWidgetsApplication1Class)

{
     
    ui ->setupUi(this);
  
    connect(ui -> spinBox1, SIGNAL(valueChanged(int)), this, SLOT(result()));
    connect(ui -> spinBox2, SIGNAL(valueChanged(int)), this, SLOT(result()));
  
}
QtWidgetsApplication1::~QtWidgetsApplication1()
{}
   
void QtWidgetsApplication1::result() {
    int obs_height = ui->spinBox1->value();
    int obj_height = ui->spinBox2->value();
    int horizon_distance = (3.85 * sqrt(obs_height)) * 1000;
    int visibility_distance = (3.85 * (sqrt(obs_height) + sqrt(obj_height))) * 1000;
    ui ->label1->setText( QString::number(horizon_distance));
    ui->label2->setText(QString::number(visibility_distance));
}
