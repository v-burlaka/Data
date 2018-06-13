#ifndef BROZEFILEDIALOG_HPP
#define BROZEFILEDIALOG_HPP

#include <QDialog>

namespace Ui { class BrozeFileDialog; }
class DataEditDialog;

class BrozeFileDialog : public QDialog
{
   Q_OBJECT

public:
   explicit BrozeFileDialog(QWidget *parent = 0);
   ~BrozeFileDialog();

private slots:
   void on_pushButton_2_clicked();
   void on_pushButton_clicked();

   void on_pushButton_3_clicked();

private:
   Ui::BrozeFileDialog *ui;
   QWidget* mParent;
   DataEditDialog* pDataEditDialog;
   QString mPathToFile;
};

#endif // BROZEFILEDIALOG_HPP
