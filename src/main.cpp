#include "gui/MainWindow.hpp"
#include <QApplication>
#include "gui/CSetBoxSettingDialog.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
//    CFormsCreator dialog(std::string("main"));
//    dialog.showForm();

    return a.exec();
}
