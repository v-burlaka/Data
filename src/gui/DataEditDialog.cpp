#include "DataEditDialog.hpp"
#include "ui_DataEditDialog.h"
#include "gui/CSetNQBox.hpp"
#include "gui/CSetCoordDialogCtrl.hpp"
#include "gui/CSetBoxSettingDialog.hpp"
#include "gui/HeatCoefficientDialog.hpp"
#include "fileProcessingCore/api/CCUBSerializator.hpp"
#include "fileProcessingCore/api/CCUBDeserializator.hpp"
#include <QDebug>


DataEditDialog::DataEditDialog(QWidget *parent)
   : QDialog(parent)
   , mParent(parent)
   , ui(new Ui::DataEditDialog())
   , settingEmptyBlocksDialog(new CSetBoxSettingDialog("Empty Bloks Settings" , this))
   , settingTrancalancyBlocksDialog(new CSetBoxSettingDialog("Another Trancalancy Settings" , this, true))
   , settingNQBlocksDialog(new CSetNQBox("NQ setting block" , this, true))
   , pDeserealizator(new CCUBDeserializator)
   , pSerializator(new CCUBSerializator)
   , pSetXCoordDialog(new CSetCoordDialogCtrl(std::string("X"), this))
   , pSetYCoordDialog(new CSetCoordDialogCtrl(std::string("Y"), this))
   , pSetZCoordDialog(new CSetCoordDialogCtrl(std::string("Z"), this))
   , settingHeatCoefficientDialog(new HeatCoefficientDialog(this, "Коэффициенты теплоотдачи "))
   , settingHoleHeatCollection(new HeatCoefficientDialog(this, "Коэффициенты теплоотдачи с поверхности выемок [Вт/(м²*°С)]:"))
{
   ui->setupUi(this);

   initMainInfo();
   //initEditLinesByDefault();
}

void DataEditDialog::initMainInfoForSave()
{
   mMainInfo.mBaseCoord.countX = ui->lineEdit_Count_CoordBy_X->text().toInt();
   mMainInfo.mBaseCoord.countY = ui->lineEdit_Count_CoordBy_Y->text().toInt();
   mMainInfo.mBaseCoord.countZ = ui->lineEdit_Count_CoordBy_Z->text().toInt();

   pSetXCoordDialog->initCoord(mMainInfo.mBaseCoord.coordX);
   pSetYCoordDialog->initCoord(mMainInfo.mBaseCoord.coordY);
   pSetZCoordDialog->initCoord(mMainInfo.mBaseCoord.coordZ);

   mMainInfo.mBlocksInfo.countEmptyBlocks = ui->lineEdit_CuntEmptyBlocks->text().toInt();
   settingEmptyBlocksDialog->initBloks(mMainInfo.mBlocksInfo.coordEmptyBlocks);

   mMainInfo.mBlocksInfo.countAnotherTrancalancy = ui->lineEdit_countAnotherTrancalancy->text().toInt();
   settingTrancalancyBlocksDialog->initBloks(mMainInfo.mBlocksInfo.AnotherTrancalancyBoxes);

   mMainInfo.mBlocksInfo.countNQ = ui->lineEdit_countNQ->text().toInt();
   settingNQBlocksDialog->initBloks(mMainInfo.mBlocksInfo.NQBoxes);

   mMainInfo.mMainTranscalancy = ui->lineEdit_MainTranscalancy->text().toDouble();

   settingHeatCoefficientDialog->initCoefficient(mMainInfo.mHeatCoefficient);
   settingHoleHeatCollection->initCoefficient(mMainInfo.mHoleHeatCollection);

   mMainInfo.mCountFlatNp = ui->lineEdit_CountFlatNp->text().toInt();
   mMainInfo.mTemperatureEnvironment = ui->lineEdit_TemperatureEnvironment->text().toDouble();
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
   pSerializator->setURL(URL);
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

//   for (int i = 0; i < 2; ++i)
//   {
//      mMainInfo.mBlocksInfo.coordEmptyBlocks.push_back(coord);
//      mMainInfo.mBlocksInfo.coordAnotherTrancalancy.push_back(coord);
//      mMainInfo.mBlocksInfo.coordNQ.push_back(coord);
//      mMainInfo.mBlocksInfo.valueNQ.push_back(221.5);
//   }

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
}

void DataEditDialog::on_pushButton_SetCount_CoordBy_X_clicked()
{
   pSetXCoordDialog->setCountOfCoord(ui->lineEdit_Count_CoordBy_X->text().toInt() + 1);
   this->close();

   pSetXCoordDialog->showForm();
}

void DataEditDialog::on_pushButton_SetCount_CoordBy_Y_clicked()
{
   pSetYCoordDialog->setCountOfCoord(ui->lineEdit_Count_CoordBy_Y->text().toInt() + 1);
   this->close();

   pSetYCoordDialog->showForm();
}

void DataEditDialog::on_pushButton_SetCount_CoordBy_Z_clicked()
{
   pSetZCoordDialog->setCountOfCoord(ui->lineEdit_Count_CoordBy_Z->text().toInt() + 1);
   this->close();

   pSetZCoordDialog->showForm();
}

void DataEditDialog::on_pushButton_SetHeatCoefficient_clicked()
{
   this->close();
   settingHeatCoefficientDialog->show();
}

void DataEditDialog::on_pushButton_SetHoleHeatCollection_clicked()
{
   this->close();
   settingHoleHeatCollection->show();
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

void DataEditDialog::on_pushButton_SetCountNQ_clicked()
{
   settingNQBlocksDialog->setCountOfCoords(ui->lineEdit_countNQ->text().toInt());
   settingNQBlocksDialog->showForm();
}

void DataEditDialog::on_Save_clicked()
{
   initMainInfoForSave();

   pSerializator->execute(mMainInfo);
   this->close();
   /*if(0 != mParent)
   {
      mParent->show();
   }*/
}

void DataEditDialog::on_Back_clicked()
{
   this->close();
   if(0 != mParent)
   {
      mParent->show();
   }
}
