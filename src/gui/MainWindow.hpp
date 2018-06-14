#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>


namespace Ui { class MainWindow;}
class BrozeFileDialog;

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

private slots:
   void on_pushButton_EditFile_clicked();

   void on_pushButton_CreateNewFile_clicked();

private:
   Ui::MainWindow *ui;
   BrozeFileDialog* pBrozeFileDialog;
};

#endif // MAINWINDOW_HPP
