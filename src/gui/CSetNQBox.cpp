#include "CSetNQBox.hpp"
#include <QDebug>

CSetNQBox::CSetNQBox(const std::string& name, QWidget* parent, bool isNeedTrancalancy)
: mParent(parent)
, mName(name)
, mCountOfCoords(0)
, Form(new QWidget)
, mIsNeedTrancalancy(isNeedTrancalancy)
{
   initAllWidgets();
}

CSetNQBox::~CSetNQBox()
{
   delete Form;
   delete gridLayout_3;
   delete verticalLayout_2;

   for(auto dialog : inputDialogs)
   {
      delete dialog;
   }

   delete horizontalLayout;
   delete horizontalSpacer;
   delete pushButton_close;
   delete pushButton_save;
}

void CSetNQBox::setCountOfCoords(int countOfCoords)
{
   const int diference = mCountOfCoords - countOfCoords;

   Form->resize(627, 229);

   if(0 < diference)
   {
      qDebug("Counts Delete old coord: %d", diference );

      for(int i = 0; i < diference; ++i )
      {
         delete inputDialogs.back();
         inputDialogs.pop_back();
      }
   }
   else
   {
      qDebug("Add new coord: %d", diference * (-1));
      createNewTableForInput(diference * (-1));
   }

   mCountOfCoords = countOfCoords;
}

void CSetNQBox::showForm()
{
   if( 0 != mParent)
   {
      mParent->close() ;
   }
   Form->show();
}

void CSetNQBox::initBloks(std::vector<sBoxInfo>& bloks)
{
   bloks.clear();

   for(auto table : inputDialogs)
   {
      sBoxInfo boxInfo;

      boxInfo.coord.startCoord.X = table->lineEdit_x1->text().toInt();
      boxInfo.coord.startCoord.Y = table->lineEdit_y1->text().toInt();
      boxInfo.coord.startCoord.Z = table->lineEdit_z1->text().toInt();

      boxInfo.coord.endCoord.X = table->lineEdit_x2->text().toInt();
      boxInfo.coord.endCoord.Y = table->lineEdit_y2->text().toInt();
      boxInfo.coord.endCoord.Z = table->lineEdit_z2->text().toInt();

      boxInfo.value = table->lineEdit_Trancalancy->text().toDouble();

      bloks.push_back(boxInfo);
   }
}

void CSetNQBox::on_pushButton_close_clicked()
{
   Form->close();
   mParent->show();
}

void CSetNQBox::on_pushButton_save_clicked()
{

}

void CSetNQBox::initAllWidgets()
{
   if (Form->objectName().isEmpty())
   {
      Form->setObjectName(mName.c_str());
   }
   Form->resize(627, 229);
   gridLayout_3 = new QGridLayout(Form);
   gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));

   verticalLayout_2 = new QVBoxLayout();
   verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

   createNewTableForInput(mCountOfCoords);

   horizontalLayout = new QHBoxLayout();
   horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
   horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

   horizontalLayout->addItem(horizontalSpacer);

   pushButton_close = new QPushButton(Form);
   pushButton_close->setObjectName(QStringLiteral("pushButton_2"));

   horizontalLayout->addWidget(pushButton_close);

   pushButton_save = new QPushButton(Form);
   pushButton_save->setObjectName(QStringLiteral("pushButton"));

   horizontalLayout->addWidget(pushButton_save);
   verticalLayout_2->addLayout(horizontalLayout);
   gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

   retranslateUi(Form);

   connect(pushButton_close, SIGNAL(clicked()), this, SLOT(on_pushButton_close_clicked()));
   connect(pushButton_save, SIGNAL(clicked()), this, SLOT(on_pushButton_save_clicked()));

   QMetaObject::connectSlotsByName(Form);
}

void CSetNQBox::createNewTableForInput(const int countOfNewCoords)
{
   for(int i = 0; i < countOfNewCoords; ++i)
   {
      inputDialogs.push_back(new InputDialog(Form, mIsNeedTrancalancy));
      verticalLayout_2->addLayout(inputDialogs.back()->verticalLayout);
   }
}// retranslateUi

void CSetNQBox::retranslateUi(QWidget *Form)
{
   Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
   pushButton_close->setText(QApplication::translate("Form", "\320\235\320\260\320\267\320\260\320\264", 0));
   pushButton_save->setText(QApplication::translate("Form", "\320\223\320\276\321\202\320\276\320\262\320\276", 0));
}

//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
CSetNQBox::InputDialog::InputDialog(QWidget* parent, bool IsNeedTrancalancy)
: Form(parent)
, mIsNeedTrancalancy(IsNeedTrancalancy)
{
   createWidgets();
   initWidgets();
}

CSetNQBox::InputDialog::~InputDialog()
{
   delete label_head_text;
   delete gridLayout;
   delete label_x1;
   delete label_z2;
   delete label_x2;
   delete label_z1;
   delete label_y2;
   delete label_y1;
   delete lineEdit_x1;
   delete lineEdit_z1;
   delete lineEdit_z2;
   delete lineEdit_x2;
   delete lineEdit_y1;
   delete lineEdit_y2;
}

void CSetNQBox::InputDialog::setName(const std::string& name)
{
   label_head_text->setText(name.c_str());
}

void CSetNQBox::InputDialog::createWidgets()
{
   verticalLayout = new QVBoxLayout();
   verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

   label_head_text = new QLabel(Form);
   label_head_text->setObjectName(QStringLiteral("label_head_text"));
   verticalLayout->addWidget(label_head_text);

   gridLayout = new QGridLayout();
   gridLayout->setObjectName(QStringLiteral("gridLayout"));
   addLineEditForms();
   addLabels();

   verticalLayout->addLayout(gridLayout);
}

void CSetNQBox::InputDialog::addLineEditForms()
{
   lineEdit_x1 = new QLineEdit(Form);
   lineEdit_x1->setObjectName(QStringLiteral("lineEdit"));

   lineEdit_z2 = new QLineEdit(Form);
   lineEdit_z2->setObjectName(QStringLiteral("lineEdit_4"));

   lineEdit_x2 = new QLineEdit(Form);
   lineEdit_x2->setObjectName(QStringLiteral("lineEdit_2"));

   lineEdit_y1 = new QLineEdit(Form);
   lineEdit_y1->setObjectName(QStringLiteral("lineEdit_6"));

   lineEdit_y2 = new QLineEdit(Form);
   lineEdit_y2->setObjectName(QStringLiteral("lineEdit_5"));

   lineEdit_z1 = new QLineEdit(Form);
   lineEdit_z1->setObjectName(QStringLiteral("lineEdit_3"));

   gridLayout->addWidget(lineEdit_x1, 0, 1, 1, 1);
   gridLayout->addWidget(lineEdit_x2, 1, 1, 1, 1);
   gridLayout->addWidget(lineEdit_y1, 0, 3, 1, 1);
   gridLayout->addWidget(lineEdit_y2, 1, 3, 1, 1);
   gridLayout->addWidget(lineEdit_z2, 1, 5, 1, 1);
   gridLayout->addWidget(lineEdit_z1, 0, 5, 1, 1);

   if(true == mIsNeedTrancalancy)
   {
      lineEdit_Trancalancy = new QLineEdit(Form);
      lineEdit_Trancalancy->setObjectName(QStringLiteral("label_Trancalancy"));
      gridLayout->addWidget(lineEdit_Trancalancy, 2, 1, 1, 1);
   }
}

void CSetNQBox::InputDialog::addLabels()
{
   label_x1 = new QLabel(Form);
   label_x1->setObjectName(QStringLiteral("label_x1"));

   label_x2 = new QLabel(Form);
   label_x2->setObjectName(QStringLiteral("label_x2"));

   label_z1 = new QLabel(Form);
   label_z1->setObjectName(QStringLiteral("label_z1"));

   label_y2 = new QLabel(Form);
   label_y2->setObjectName(QStringLiteral("label_y2"));

   label_y1 = new QLabel(Form);
   label_y1->setObjectName(QStringLiteral("label_y1"));

   label_z2 = new QLabel(Form);
   label_z2->setObjectName(QStringLiteral("label_z2"));

   gridLayout->addWidget(label_x1, 0, 0, 1, 1);
   gridLayout->addWidget(label_x2, 1, 0, 1, 1);
   gridLayout->addWidget(label_z1, 0, 4, 1, 1);
   gridLayout->addWidget(label_z2, 1, 4, 1, 1);
   gridLayout->addWidget(label_y2, 1, 2, 1, 1);
   gridLayout->addWidget(label_y1, 0, 2, 1, 1);

   if(true == mIsNeedTrancalancy)
   {
      label_Trancalancy = new QLabel(Form);
      label_Trancalancy->setObjectName(QStringLiteral("label_y1"));
      gridLayout->addWidget(label_Trancalancy, 2, 0, 1, 1);
   }
}

void CSetNQBox::InputDialog::initWidgets()
{
   label_head_text->setText(QApplication::translate("Form", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 -\320\263\320\276 \320\261\320\273\320\276\320\272\320\260", 0));
   label_x1->setText(QApplication::translate("Form", "X1:", 0));
   label_x2->setText(QApplication::translate("Form", "X2 :", 0));
   label_z1->setText(QApplication::translate("Form", "Z1 :", 0));
   label_y2->setText(QApplication::translate("Form", "Y2 :", 0));
   label_y1->setText(QApplication::translate("Form", "Y1 :", 0));
   label_z2->setText(QApplication::translate("Form", "Z2 :", 0));
   if(true == mIsNeedTrancalancy)
   {
      label_Trancalancy->setText(QApplication::translate("Form", "Q (Вт*10E-6)/м³ :", 0));
   }
}
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
