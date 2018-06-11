#include "BrozeFileDialog.hpp"
#include "ui_BrozeFileDialog.h"
#include <QFileDialog>

BrozeFileDialog::BrozeFileDialog(QWidget *parent)
: QDialog(parent)
, ui(new Ui::BrozeFileDialog)
, mParent(parent)
, mPathToFile()
{
   ui->setupUi(this);
}

BrozeFileDialog::~BrozeFileDialog()
{
   delete ui;
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
