#ifndef DATAEDITDIALOG_HPP
#define DATAEDITDIALOG_HPP

#include <QDialog>
#include "../fileProcessingCore/api/Structs.hpp"

namespace Ui { class DataEditDialog; }
class CSetCoordDialog;
class CSetBoxSettingDialog;
class CCUBDeserializator;
class CCUBSerializator;


class DataEditDialog : public QDialog
{
   Q_OBJECT

public:
   explicit DataEditDialog(QWidget *parent = 0);
   ~DataEditDialog();

   void setMainInfo(const std::string& URL);
   void createFail(const QString &URL);

private slots:
   void on_pushButton_9_clicked();

   void on_pushButton_SetCount_CoordBy_X_clicked();

   void on_pushButton_SetHeatCoefficient_clicked();

   void on_pushButton_SetcountAnotherTrancalancy_clicked();

   void on_pushButton_SetEmptyBlocks_clicked();

   void on_Save_clicked();

private:
   void initMainInfo();
   void initEditLinesByDefault();

private:
   Ui::DataEditDialog *ui;
   QWidget* mParent;
   CSetCoordDialog* pSetXCoordDialog;
   CSetCoordDialog* pSetYCoordDialog;
   CSetCoordDialog* pSetZCoordDialog;
   CSetBoxSettingDialog* settingEmptyBlocksDialog;
   CSetBoxSettingDialog* settingTrancalancyBlocksDialog;
   sMainInfo mMainInfo;
   CCUBDeserializator* pDeserealizator;
   CCUBSerializator* pSerializator;
};

#endif // DATAEDITDIALOG_HPP
