#include "ChoiceName.hpp"
#include "ui_ChoiceName.h"
#include "gui/DataEditDialog.hpp"

ChoiceName::ChoiceName(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::ChoiceName)
 , pDataEditDialog(new DataEditDialog(this))
{
   ui->setupUi(this);
}

ChoiceName::~ChoiceName()
{
   delete ui;
}

void ChoiceName::setDirectory(const QString &dir)
{
   mDirectory = dir;
}

void ChoiceName::on_Name_Choice_clicked()
{
   mName = ui->Name_LineEdit->text();

   pDataEditDialog->createFail(mDirectory + "/" + mName);
   pDataEditDialog->show();
}

void ChoiceName::on_Name_Back_clicked()
{
   this->close();
}

void ChoiceName::on_Name_LineEdit_textEdited(const QString &arg1)
{
    mName = arg1;
}
