#include "FormCoordInput.hpp"
#include "ui_FormCoordInput.h"

FormCoordInput::FormCoordInput(QWidget *parent) :
   QWidget(parent),
   ui(new Ui::FormCoordInput)
{
   ui->setupUi(this);
}

FormCoordInput::~FormCoordInput()
{
   delete ui;
}
