#ifndef FORMCOORDINPUT_HPP
#define FORMCOORDINPUT_HPP

#include <QWidget>

namespace Ui {
   class FormCoordInput;
}

class FormCoordInput : public QWidget
{
   Q_OBJECT

public:
   explicit FormCoordInput(QWidget *parent = 0);
   ~FormCoordInput();

private:
   Ui::FormCoordInput *ui;
};

#endif // FORMCOORDINPUT_HPP
