#include "DataEditDialog.hpp"
#include "ui_DataEditDialog.h"
#include "gui/CSetBoxSettingDialog.hpp"
#include "fileProcessingCore/api/CCUBDeserializator.hpp"
#include "fileProcessingCore/api/CCUBSerializator.hpp"
#include <QDebug>
#include "gui/CSetCoordDialogCtrl.hpp"

DataEditDialog::DataEditDialog(QWidget *parent)
   : QDialog(parent)
   , mParent(parent)
   , ui(new Ui::DataEditDialog())
   , settingEmptyBlocksDialog(new CSetBoxSettingDialog("Empty Bloks Settings" , this))
   , settingTrancalancyBlocksDialog(new CSetBoxSettingDialog("Empty Trancalancy Settings" , this, true))
   , pDeserealizator(new CCUBDeserializator)
   , pSerializator(new CCUBSerializator)
   , pSetXCoordDialog(new CSetCoordDialogCtrl(std::string("X"), this))
   , pSetYCoordDialog(new CSetCoordDialogCtrl(std::string("Y"), this))
   , pSetZCoordDialog(new CSetCoordDialogCtrl(std::string("Z"), this))
{
   ui->setupUi(this);

   initMainInfo();
   initEditLinesByDefault();
}

DataEditDialog::~DataEditDialog()
{
   delete ui;
   delete pDeserealizator;
   delete pSerializator;
}

void DataEditDialog::setMainInfo(const std::string& URL)
{
   pDeserealizator->setURL(URL);
   mMainInfo = pDeserealizator->execute();
   initEditLinesByDefault();
}

void DataEditDialog::createFail(const QString& URL)
{
   pSerializator->setURL(URL.toUtf8().constData());
   qDebug(URL.toUtf8().constData());
}

void DataEditDialog::initMainInfo()
{
   sBlockCoord coord;

   coord.startCoord.X = 0;
   coord.startCoord.Y = 0;
   coord.startCoord.Z = 0;
   coord.endCoord.X = 1;
   coord.endCoord.Y = 1;
   coord.endCoord.Z = 1;

   mMainInfo.mBaseCoord.countX = 5;
   mMainInfo.mBaseCoord.countY = 5;
   mMainInfo.mBaseCoord.countZ = 5;

   for (int i = 0; i < 5; ++i)
   {
      mMainInfo.mBaseCoord.coordX.push_back(i);
      mMainInfo.mBaseCoord.coordY.push_back(i);
      mMainInfo.mBaseCoord.coordZ.push_back(i);
   }

   mMainInfo.mBlocksInfo.countEmptyBlocks = 2;
   mMainInfo.mBlocksInfo.countAnotherTrancalancy = 2;
   mMainInfo.mBlocksInfo.countNQ = 2;

   for (int i = 0; i < 2; ++i)
   {
      mMainInfo.mBlocksInfo.coordEmptyBlocks.push_back(coord);
      mMainInfo.mBlocksInfo.coordAnotherTrancalancy.push_back(coord);
      mMainInfo.mBlocksInfo.coordNQ.push_back(coord);
      mMainInfo.mBlocksInfo.valueNQ.push_back(221.5);
   }

   mMainInfo.mMainTranscalancy = 3.5;

   mMainInfo.mHeatCoefficient.push_back(0.5);
   mMainInfo.mHoleHeatCollection.push_back(0.5);

   mMainInfo.mCountFlatNp = 0;

   mMainInfo.mTemperatureEnvironment = 36.6;
}

void DataEditDialog::initEditLinesByDefault()
{
   ui->lineEdit_Count_CoordBy_X->setText(QString::number(mMainInfo.mBaseCoord.countX));
   ui->lineEdit_Count_CoordBy_Y->setText(QString::number(mMainInfo.mBaseCoord.countY));
   ui->lineEdit_Count_CoordBy_Z->setText(QString::number(mMainInfo.mBaseCoord.countZ));

   ui->lineEdit_countAnotherTrancalancy->setText(QString::number(mMainInfo.mBlocksInfo.countAnotherTrancalancy));
   ui->lineEdit_countNQ->setText(QString::number(mMainInfo.mBlocksInfo.countNQ));
   ui->lineEdit_CuntEmptyBlocks->setText(QString::number(mMainInfo.mBlocksInfo.coordEmptyBlocks.size()));

   ui->lineEdit_CountFlatNp->setText(QString::number(mMainInfo.mCountFlatNp));
   ui->lineEdit_MainTranscalancy->setText(QString::number(mMainInfo.mMainTranscalancy));
   ui->lineEdit_TemperatureEnvironment->setText(QString::number(mMainInfo.mTemperatureEnvironment));
}

void DataEditDialog::on_pushButton_9_clicked()
{
   this->close();
   mParent->show();
}

void DataEditDialog::on_pushButton_SetCount_CoordBy_X_clicked()
{
   pSetXCoordDialog->setCountOfCoord(ui->lineEdit_Count_CoordBy_X->text().toInt());
   this->close();

   pSetXCoordDialog->showForm();
}

void DataEditDialog::on_pushButton_SetHeatCoefficient_clicked()
{

}

void DataEditDialog::on_pushButton_SetcountAnotherTrancalancy_clicked()
{
   settingTrancalancyBlocksDialog->setCountOfCoords(ui->lineEdit_CuntEmptyBlocks->text().toInt());
   settingTrancalancyBlocksDialog->showForm();
}

void DataEditDialog::on_pushButton_SetEmptyBlocks_clicked()
{
   settingEmptyBlocksDialog->setCountOfCoords(ui->lineEdit_CuntEmptyBlocks->text().toInt());
   settingEmptyBlocksDialog->showForm();
}

void DataEditDialog::on_Save_clicked()
{
   pSerializator->execute(mMainInfo);
}

void DataEditDialog::on_pushButton_SetCount_CoordBy_Y_clicked()
{
   pSetYCoordDialog->setCountOfCoord(ui->lineEdit_Count_CoordBy_Y->text().toInt());
   this->close();

   pSetYCoordDialog->showForm();
}

void DataEditDialog::on_pushButton_SetCount_CoordBy_Z_clicked()
{
   pSetZCoordDialog->setCountOfCoord(ui->lineEdit_Count_CoordBy_Z->text().toInt());
   this->close();

   pSetZCoordDialog->showForm();
}
