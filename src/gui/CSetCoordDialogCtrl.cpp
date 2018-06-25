#include "CSetCoordDialogCtrl.hpp"
#include <QDebug>

CSetCoordDialogCtrl::CSetCoordDialogCtrl(const std::string& name, QWidget* parent)
   : mName(name)
   , mParent(parent)
   , mCountOfCoord(0)
   , FormCoordInput(new QWidget)
{
   qDebug("CSetCoordDialogCtrl cstr");
   createWidgets();
}

CSetCoordDialogCtrl::~CSetCoordDialogCtrl()
{
   delete horizontalLayout_3;
   delete verticalLayout;
   delete horizontalLayout_2;
   delete horizontalSpacer_2;
   delete verticalSpacer;
   delete horizontalLayout;
   delete horizontalSpacer;
   delete pushButton_close;
   delete pushButton_save;

   for(auto InitTable : coordInitTableList)
   {
      delete InitTable;
   }
}

void CSetCoordDialogCtrl::showForm()
{
   FormCoordInput->show();
}

void CSetCoordDialogCtrl::setCountOfCoord(int countOfCoord)
{
   int countOfNewItems = mCountOfCoord - countOfCoord;

   if(countOfNewItems < 0)
   {
      qDebug("Was: %d, need %d, count of new coord %d", mCountOfCoord, countOfCoord, countOfNewItems);
      qDebug("NewCoordInputItems %d", countOfNewItems * -1);
      createNewCoordInputItems(countOfNewItems * -1 );
   }
   else
   {
      qDebug("Was: %d, need %d, count of delete coord %d", mCountOfCoord, countOfCoord, countOfNewItems);
      qDebug("deleteExcessInputItems %d", countOfNewItems);
      deleteExcessInputItems(countOfNewItems);
   }

   mCountOfCoord = countOfCoord;
}

void CSetCoordDialogCtrl::on_pushButton_close_clicked()
{
   FormCoordInput->close();
   mParent->show();
}

void CSetCoordDialogCtrl::on_pushButton_save_clicked()
{

}

void CSetCoordDialogCtrl::createWidgets()
{
   if (FormCoordInput->objectName().isEmpty())
   {
       FormCoordInput->setObjectName(QStringLiteral("FormCoordInput"));
   }

   FormCoordInput->resize(375, 342);
   horizontalLayout_3 = new QHBoxLayout(FormCoordInput);
   horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
   verticalLayout = new QVBoxLayout();
   verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
   horizontalLayout_2 = new QHBoxLayout();
   horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

   qDebug(" before createNewCoordInputItems");

   coordInitTableList.push_back(new CoordInitTable(FormCoordInput, mName.c_str()));
   horizontalLayout_2->addLayout(coordInitTableList.back()->formLayout);

   createNewCoordInputItems(mCountOfCoord);

   qDebug(" after createNewCoordInputItems");

   verticalLayout->addLayout(horizontalLayout_2);

   horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

   verticalLayout->addItem(horizontalSpacer_2);

   verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

   verticalLayout->addItem(verticalSpacer);

   horizontalLayout = new QHBoxLayout();
   horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
   horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

   horizontalLayout->addItem(horizontalSpacer);

   pushButton_close = new QPushButton(FormCoordInput);
   pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

   horizontalLayout->addWidget(pushButton_close);

   pushButton_save = new QPushButton(FormCoordInput);
   pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

   horizontalLayout->addWidget(pushButton_save);
   verticalLayout->addLayout(horizontalLayout);
   horizontalLayout_3->addLayout(verticalLayout);

   FormCoordInput->setWindowTitle(QApplication::translate("FormCoordInput", "Input coordinats", Q_NULLPTR));
   pushButton_close->setText(QApplication::translate("FormCoordInput", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
   pushButton_save->setText(QApplication::translate("FormCoordInput", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));

   connect(pushButton_close, SIGNAL(clicked()), this, SLOT(on_pushButton_close_clicked()));
   connect(pushButton_save, SIGNAL(clicked()), this, SLOT(on_pushButton_save_clicked()));

   QMetaObject::connectSlotsByName(FormCoordInput);
}

void CSetCoordDialogCtrl::createNewCoordInputItems(int countNeedCreateCoordInputItems)
{
   while(countNeedCreateCoordInputItems > 0)
   {
      countNeedCreateCoordInputItems = coordInitTableList.back()->setCountOfCoord(countNeedCreateCoordInputItems);

      if(countNeedCreateCoordInputItems != 0)
      {
         qDebug("Create new table, need input %d", countNeedCreateCoordInputItems);
         coordInitTableList.push_back(new CoordInitTable(FormCoordInput, mName.c_str()));

         countNeedCreateCoordInputItems = coordInitTableList.back()->setCountOfCoord(countNeedCreateCoordInputItems);
         horizontalLayout_2->addLayout(coordInitTableList.back()->formLayout);
      }
   }
}

void CSetCoordDialogCtrl::deleteExcessInputItems(int countExcessInputItems)
{
   for(;countExcessInputItems != 0;)
   {
      countExcessInputItems = coordInitTableList.back()->deleteExcessInputItems(countExcessInputItems);

      if( 0 != countExcessInputItems)
      {
         coordInitTableList.pop_back();
      }
   }
    qDebug(" Delete success");
}

//--------------------------------------------------------------------------------
CSetCoordDialogCtrl::CoordInitTable::CoordInitTable(QWidget* parent, const QString& name)
   : mName(name)
   , FormCoordInput(parent)
   , mCountOfElements(0)
   , MAX_SIZE(12)
   , index(0)
{
   createWidgets();
}

CSetCoordDialogCtrl::CoordInitTable::~CoordInitTable()
{
   for( auto label_coord : label_coords)
   {
      delete  label_coord;
   }

   for( auto lineEdit_coord : lineEdit_coords)
   {
      delete lineEdit_coord;
   }

   delete formLayout;
}

int CSetCoordDialogCtrl::CoordInitTable::setCountOfCoord(int countOfCoord)
{
   int difference = 0;
   int countOfCanAddEditLine = MAX_SIZE - mCountOfElements;

   qDebug("Table, need input %d, was %d", countOfCoord, mCountOfElements);

   if (countOfCanAddEditLine == 0)
   {
      qDebug("Table, can`t add new elements");
      difference = countOfCoord;
   }
   else
   {
      if(countOfCanAddEditLine > countOfCoord)
      {
         difference = 0;
         qDebug("Table, add %d elements", countOfCoord);
         intNewiEditLineAndLabel(countOfCoord);
      }
      else
      {
         difference = countOfCoord - countOfCanAddEditLine;
         qDebug("Table, add %d elements", countOfCanAddEditLine);
         intNewiEditLineAndLabel(countOfCanAddEditLine);
      }
   }

   return difference;
}

int CSetCoordDialogCtrl::CoordInitTable::deleteExcessInputItems(int countExcessInputItems)
{
   int difference = mCountOfElements - countExcessInputItems;

   qDebug("Table, need delete %d, was %d", countExcessInputItems, mCountOfElements);

   if(mCountOfElements == 0)
   {
      qDebug("Table, can`t delete elements");
      difference = 0;
   }
   else
   {
      if(mCountOfElements > countExcessInputItems)
      {
         difference = 0;
         qDebug("Table, delete %d elements", countExcessInputItems);
         deleteEditLineAndLabel(countExcessInputItems);
      }
      else
      {
         difference = countExcessInputItems - mCountOfElements;
         qDebug("Table, delete %d elements", mCountOfElements);
         deleteEditLineAndLabel(mCountOfElements);
      }

      difference = 0;
   }

   return difference;
}

void CSetCoordDialogCtrl::CoordInitTable::createWidgets()
{
   formLayout = new QFormLayout();
   formLayout->setObjectName(QStringLiteral("formLayout"));

   intNewiEditLineAndLabel(mCountOfElements);
}

void CSetCoordDialogCtrl::CoordInitTable::intNewiEditLineAndLabel(const int countNew)
{
   mCountOfElements += countNew;

   for(int i = 0; i < countNew; ++i)
   {
      index++;
      qDebug("Table, NewItem : %d", i);
      QLabel* newLabel = new QLabel(FormCoordInput);

      newLabel->setObjectName(QStringLiteral("label_") + mName + QString(index));
      newLabel->setMaximumSize(QSize(133, 20));
      newLabel->setText(QApplication::translate("FormCoordInput",  QString(mName + QString::number(index)).toUtf8().constData(), Q_NULLPTR));

      qDebug("newLabel created");

      QLineEdit* newLineEdit = new QLineEdit(FormCoordInput);

      newLineEdit->setObjectName(QStringLiteral("lineEdit_X") + QString::number(i));
      newLineEdit->setMaximumSize(QSize(133, 20));

      qDebug("newLineEdit created");

      formLayout->setWidget(index - 1, QFormLayout::LabelRole, newLabel);
      qDebug("newLabel set to formLayout");

      formLayout->setWidget(index - 1, QFormLayout::FieldRole, newLineEdit);
      qDebug("newLineEdit set to formLayout");

      label_coords.push_back(newLabel);
      lineEdit_coords.push_back(newLineEdit);
   }
}

void CSetCoordDialogCtrl::CoordInitTable::deleteEditLineAndLabel(const int countOfDeletedElements)
{
   mCountOfElements -= countOfDeletedElements;

   for(int i = 0; i < countOfDeletedElements; ++i )
   {
      delete label_coords.back();
      delete lineEdit_coords.back();

      label_coords.pop_back();
      lineEdit_coords.pop_back();

      --index;
   }

   qDebug("Table, delete success");
}

