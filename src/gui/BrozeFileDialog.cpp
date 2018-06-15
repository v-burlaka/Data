#include <string>

#include "BrozeFileDialog.hpp"
#include "DataEditDialog.hpp"
#include "ui_BrozeFileDialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include "gui/DataEditDialog.hpp"
#include "fileProcessingCore/api/Helper.hpp"

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
   try
   {
      pDataEditDialog->setMainInfo(std::string(mPathToFile.toUtf8().constData()));
      pDataEditDialog->show();
   }
   catch(std::bad_alloc)
   {
      QMessageBox::warning(0,"Warning", "Incorrect path");
      this->show();
   }
   catch(exceptions::InvalidPathOrFile)
   {
      //QMessageBox::warning(0,"Warning", QString::fromUtf8(exception.getException().c_str(), exception.getException().length()));
      QMessageBox::warning(0,"Warning", "Incorrect file");
      this->show();
   }
}
