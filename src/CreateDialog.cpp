#include <QFileDialog>
#include <QMessageBox>

#include "CreateDialog.hpp"
#include "ui_CreateDialog.h"
#include "fileProcessingCore/api/ChoiceName.hpp"
#include "fileProcessingCore/api/Structs.hpp"

CreateDialog::CreateDialog(QWidget *parent)
   : QDialog(parent)
   , ui(new Ui::CreateDialog)
   , mParent(parent)
   , mPathToFile()
   , pChoiceName(new ChoiceName(this))
{
   ui->setupUi(this);
}

CreateDialog::~CreateDialog()
{
   delete ui;
   delete pChoiceName;
}

void CreateDialog::on_Create_Back_clicked()
{
   this->close();
   mParent->show();
}

void CreateDialog::on_Create_Choice_clicked()
{
   this->close();
   pChoiceName->setDirectory(mPathToFile);
   pChoiceName->show();
}

void CreateDialog::on_Create_Observe_clicked()
{
   mPathToFile = QFileDialog::getExistingDirectory(this, tr("Open Directory"), ui->Create_LineEdit->text(), QFileDialog::ShowDirsOnly);
   ui->Create_LineEdit->setText(mPathToFile);
}
