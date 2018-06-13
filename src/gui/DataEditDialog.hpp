#ifndef DATAEDITDIALOG_HPP
#define DATAEDITDIALOG_HPP

#include <QDialog>
#include "../fileProcessingCore/api/Structs.hpp"

namespace Ui { class DataEditDialog; }


class DataEditDialog : public QDialog
{
   Q_OBJECT

public:
   explicit DataEditDialog(QWidget *parent = 0);
   ~DataEditDialog();

   void setMainInfo(const sMainInfo& MainInfo);

private slots:
   void on_pushButton_9_clicked();

private:
   void initMainInfo();
   void initEditLinesByDefault();

private:
   Ui::DataEditDialog *ui;
   QWidget* mParent;
   sMainInfo mMainInfo;

};

#endif // DATAEDITDIALOG_HPP
