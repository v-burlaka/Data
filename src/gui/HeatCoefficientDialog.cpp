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

void HeatCoefficientDialog::on_pushButton_clicked()
{
   mParent->show();
   this->close();
}
