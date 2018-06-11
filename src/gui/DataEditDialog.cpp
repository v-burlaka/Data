#include "DataEditDialog.hpp"
#include "ui_DataEditDialog.h"

DataEditDialog::DataEditDialog(QWidget *parent) :
QDialog(parent),
ui(new Ui::DataEditDialog)
{
   ui->setupUi(this);
}

DataEditDialog::~DataEditDialog()
{
   delete ui;
}
