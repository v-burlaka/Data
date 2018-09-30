#ifndef HEATCOEFFICIENTDIALOG_HPP
#define HEATCOEFFICIENTDIALOG_HPP

#include <QDialog>

namespace Ui {
   class HeatCoefficientDialog;
}

class HeatCoefficientDialog : public QDialog
{
   Q_OBJECT

public:
   HeatCoefficientDialog(QWidget *parent, const char * headerLabelName);
   ~HeatCoefficientDialog();

   void initCoefficient(std::vector<double> &coefficients);

private slots:
   void on_pushButton_clicked();

private:
   Ui::HeatCoefficientDialog *ui;
   QWidget* mParent;
};

#endif // HEATCOEFFICIENTDIALOG_HPP
