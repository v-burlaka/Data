#ifndef C_SET_NQ_BOX_HPP
#define C_SET_NQ_BOX_HPP

#include <QDialog>
#include <string>

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <vector>
#include "fileProcessingCore/api/Structs.hpp"

class CSetNQBox : public QDialog
{
   Q_OBJECT

public:
   explicit CSetNQBox(const std::string& name, QWidget *parent = 0, bool isNeedTrancalancy = false);
   ~CSetNQBox();

   void setCountOfCoords(int countOfCoords);
   void showForm();
   void initBloks(std::vector<sBoxInfo>& bloks);

   private slots:
   void on_pushButton_close_clicked();
   void on_pushButton_save_clicked();

private:
   void initAllWidgets();
   void retranslateUi(QWidget *Form);
   void createNewTableForInput(const int countOfNewCoords);

private:
   std::string mName;
   QWidget* mParent;
   QWidget     * Form;
   QGridLayout *gridLayout_3;
   QVBoxLayout *verticalLayout_2;
//------------------------------------
   struct InputDialog
   {
   public:
      InputDialog(QWidget* parent, bool IsNeedTrancalancy);
      ~InputDialog();

      void setName(const std::string& name);
      QVBoxLayout *verticalLayout;

      int index;

   private:
      void createWidgets();
      void addLineEditForms();
      void addLabels();
      void initWidgets();

   private:
      QWidget     * Form;

      QLabel      *label_head_text;
      QGridLayout *gridLayout;
      QLabel      *label_x1;
      QLabel      *label_z2;
      QLabel      *label_x2;
      QLabel      *label_z1;
      QLabel      *label_y2;
      QLabel      *label_y1;
      QLabel      *label_Trancalancy;

   public:
      QLineEdit   *lineEdit_x1;
      QLineEdit   *lineEdit_z1;
      QLineEdit   *lineEdit_z2;
      QLineEdit   *lineEdit_x2;
      QLineEdit   *lineEdit_y1;
      QLineEdit   *lineEdit_y2;
      QLineEdit   *lineEdit_Trancalancy;

      bool mIsNeedTrancalancy;
   };

   std::vector<InputDialog *> inputDialogs;
//------------------------------------
   QHBoxLayout *horizontalLayout;
   QSpacerItem *horizontalSpacer;
   QPushButton *pushButton_close;
   QPushButton *pushButton_save;
   int mCountOfCoords;
   bool mIsNeedTrancalancy;
};

#endif // C_SET_NQ_BOX_HPP
