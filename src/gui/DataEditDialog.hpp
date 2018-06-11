#ifndef DATAEDITDIALOG_HPP
#define DATAEDITDIALOG_HPP

#include <QDialog>

namespace Ui { class DataEditDialog; }

class DataEditDialog : public QDialog
{
   Q_OBJECT

public:
   explicit DataEditDialog(QWidget *parent = 0);
   ~DataEditDialog();

private:
   Ui::DataEditDialog *ui;
};

#endif // DATAEDITDIALOG_HPP
