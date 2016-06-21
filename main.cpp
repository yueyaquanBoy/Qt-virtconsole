#include "eccloud.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    eccloud w;
    w.show();

    return a.exec();
}
