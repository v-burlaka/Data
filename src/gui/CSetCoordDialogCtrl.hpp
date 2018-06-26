#ifndef CSETCOORDDIALOGCTRL_HPP
#define CSETCOORDDIALOGCTRL_HPP

#include <QDialog>

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class CSetCoordDialogCtrl : public QDialog
{
   Q_OBJECT

public:
   explicit CSetCoordDialogCtrl(const std::string& name, QWidget *parent = 0);
   ~CSetCoordDialogCtrl();

   void showForm();
   void setCountOfCoord(int countOfCoord);
   void initCoord(std::vector<double>& coordList);

private slots:
   void on_pushButton_close_clicked();
   void on_pushButton_save_clicked();

private:
   void createWidgets();
   void createNewCoordInputItems(int countNeedCreateCoordInputItems);
   void deleteExcessInputItems(int countExcessInputItems);
   void initWidgets();

private:
   std::string mName;
   QWidget* mParent;
   QWidget* FormCoordInput;
   int mCountOfCoord;


   QHBoxLayout *horizontalLayout_3;
   QVBoxLayout *verticalLayout;
   QHBoxLayout *horizontalLayout_2;

   struct CoordInitTable
   {
      CoordInitTable(QWidget *parent, const QString& name);
      ~CoordInitTable();

      int setCountOfCoord(int countOfCoord);
      int deleteExcessInputItems(int countExcessInputItems);

      QFormLayout *formLayout;


   public:
      int countOfElements() const;

      const std::vector<QLineEdit*>& getLineEdit_coords() const;

   private:
      void createWidgets();
      void intNewiEditLineAndLabel(const int countNew);
      void deleteEditLineAndLabel(const int countOfDeletedElements);

   private:
      std::vector<QLabel *> label_coords;
      std::vector<QLineEdit *> lineEdit_coords;
      QString mName;
      QWidget* FormCoordInput;
      int mCountOfElements;
      const int MAX_SIZE;
      int index;
   };

   std::vector<CoordInitTable *> coordInitTableList;

   QSpacerItem *horizontalSpacer_2;
   QSpacerItem *verticalSpacer;
   QHBoxLayout *horizontalLayout;
   QSpacerItem *horizontalSpacer;
   QPushButton *pushButton_close;
   QPushButton *pushButton_save;
};

#endif // CSETCOORDDIALOGCTRL_HPP
