#ifndef FORM_HPP
#define FORM_HPP

#include <QWidget>

namespace Ui {
   class Form;
}

class Form : public QWidget
{
   Q_OBJECT

public:
   explicit Form(QWidget *parent = 0);
   ~Form();

private:
   Ui::Form *ui;
};

#endif // FORM_HPP
