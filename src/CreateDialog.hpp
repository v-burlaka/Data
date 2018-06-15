#ifndef CREATEDIALOG_HPP
#define CREATEDIALOG_HPP

#include <QDialog>
#include <QString>

namespace Ui {
class CreateDialog;
}

class ChoiceName;

class CreateDialog : public QDialog
{
   Q_OBJECT

public:
   explicit CreateDialog(QWidget *parent = 0);
   ~CreateDialog();

private slots:
   void on_Create_Back_clicked();

   void on_Create_Choice_clicked();

   void on_Create_Observe_clicked();

private:
   Ui::CreateDialog *ui;
   QWidget* mParent;
   QString mPathToFile;
   ChoiceName* pChoiceName;
};

#endif // CREATEDIALOG_HPP
