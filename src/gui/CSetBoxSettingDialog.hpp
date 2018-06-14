#ifndef CFORMSCREATOR_HPP
#define CFORMSCREATOR_HPP

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

class CSetBoxSettingDialog : public QDialog
{
   Q_OBJECT

public:
   explicit CSetBoxSettingDialog(const std::string& name, QWidget *parent = 0, bool isNeedTrancalancy = false);
   ~CSetBoxSettingDialog();

   void setCountOfCoords(int countOfCoords);
   void showForm();

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
      QLineEdit   *lineEdit;
      QLineEdit   *lineEdit_3;
      QLineEdit   *lineEdit_4;
      QLineEdit   *lineEdit_2;
      QLineEdit   *lineEdit_6;
      QLineEdit   *lineEdit_5;

      QLabel      *label_Trancalancy;
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

#endif // CFORMSCREATOR_HPP
