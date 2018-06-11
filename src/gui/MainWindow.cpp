#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "QIntValidator"
#include "BrozeFileDialog.hpp"


MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
, pBrozeFileDialog(new BrozeFileDialog(this))
, mMainInfo()
{
   ui->setupUi(this);

   init();
}

MainWindow::~MainWindow()
{
   delete ui;
   delete pBrozeFileDialog;
}

void MainWindow::init()
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

   mMainInfo.mCountFlatNp = 4;

   mMainInfo.mTemperatureEnvironment = 36.6;
}

void MainWindow::on_pushButton_EditFile_clicked()
{
   this->close();
   pBrozeFileDialog->show();
}

void MainWindow::on_pushButton_CreateNewFile_clicked()
{

}
