#include "BrozeFileDialog.hpp"
#include "ui_BrozeFileDialog.h"
#include <QFileDialog>
#include "gui/DataEditDialog.hpp"

BrozeFileDialog::BrozeFileDialog(QWidget *parent)
: QDialog(parent)
, ui(new Ui::BrozeFileDialog)
, mParent(parent)
, pDataEditDialog(new DataEditDialog(this))
, mPathToFile()
{
   ui->setupUi(this);
}

BrozeFileDialog::~BrozeFileDialog()
{
   delete ui;
   delete pDataEditDialog;
}

void BrozeFileDialog::on_pushButton_2_clicked()
{
   this->close();
   mParent->show();
}

void BrozeFileDialog::on_pushButton_clicked()
{
   mPathToFile = QFileDialog::getOpenFileName(this, tr("Open file"), ui->lineEdit_pathToFile->text(), "Data (*.CUB)" );
   ui->lineEdit_pathToFile->setText(mPathToFile);
}

void BrozeFileDialog::on_pushButton_3_clicked()
{
   this->close();
//   pDataEditDialog->setMainInfo(); todo edit desirializer here
   pDataEditDialog->show();
}
