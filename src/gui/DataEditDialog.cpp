#include "DataEditDialog.hpp"
#include "ui_DataEditDialog.h"


DataEditDialog::DataEditDialog(QWidget *parent)
   : QDialog(parent)
   , mParent(parent)
   , ui(new Ui::DataEditDialog())
{
   ui->setupUi(this);

   initMainInfo();
   initEditLinesByDefault();
}

DataEditDialog::~DataEditDialog()
{
   delete ui;
}

void DataEditDialog::setMainInfo(const sMainInfo& MainInfo)
{
   mMainInfo = MainInfo;
   initEditLinesByDefault();
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
