#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "QIntValidator"
#include "BrozeFileDialog.hpp"


MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
, pBrozeFileDialog(new BrozeFileDialog(this))
{
   ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete ui;
   delete pBrozeFileDialog;
}

void MainWindow::on_pushButton_EditFile_clicked()
{
   this->close();
   pBrozeFileDialog->show();
}

void MainWindow::on_pushButton_CreateNewFile_clicked()
{

}
