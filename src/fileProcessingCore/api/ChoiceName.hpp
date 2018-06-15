#ifndef CHOICENAME_HPP
#define CHOICENAME_HPP

#include <QDialog>

namespace Ui {
class ChoiceName;
}
class DataEditDialog;
class CreateDialog;
class ChoiceName : public QDialog
{
   Q_OBJECT

public:
   explicit ChoiceName(QWidget *parent = 0);
   ~ChoiceName();

   void setDirectory(const QString& dir);
private slots:
   void on_Name_Choice_clicked();

   void on_Name_Back_clicked();

   void on_Name_LineEdit_textEdited(const QString &arg1);

private:
   Ui::ChoiceName *ui;
   QString mDirectory;
   QString mName;
   DataEditDialog* pDataEditDialog;
};

#endif // CHOICENAME_HPP
