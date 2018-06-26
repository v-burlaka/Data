#include "HeatCoefficientDialog.hpp"
#include "ui_HeatCoefficientDialog.h"

HeatCoefficientDialog::HeatCoefficientDialog(QWidget *parent, const char * headerLabelName)
   : QDialog(parent)
   , ui(new Ui::HeatCoefficientDialog)
   , mParent(parent)
{
   ui->setupUi(this);
   ui->heder_label->setText(QString(headerLabelName));
}

HeatCoefficientDialog::~HeatCoefficientDialog()
{
   delete ui;
}

void HeatCoefficientDialog::initCoefficient(std::vector<double> coefficients)
{
   coefficients.push_back(ui->lineEdit_1_HeatCoefficient->text().toDouble());
   coefficients.push_back(ui->lineEdit_2_HeatCoefficient->text().toDouble());
   coefficients.push_back(ui->lineEdit_3_HeatCoefficient->text().toDouble());
   coefficients.push_back(ui->lineEdit_4_HeatCoefficient->text().toDouble());
   coefficients.push_back(ui->lineEdit_5_HeatCoefficient->text().toDouble());
   coefficients.push_back(ui->lineEdit_6_HeatCoefficient->text().toDouble());
}

void HeatCoefficientDialog::on_pushButton_clicked()
{
   mParent->show();
   this->close();
}
