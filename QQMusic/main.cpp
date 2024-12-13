#include "qqmusic.h"

#include <QApplication>
#include <QMessageBox>
#include <QSharedMemory>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSharedMemory sharedMem("QQMusic");
    if(sharedMem.attach())
    {
        QMessageBox::information(nullptr,"QQMusic","QQMusic已经在运行...");
        return 0;
    }
    sharedMem.create(1);
    QQMusic w;
    w.show();
    return a.exec();
}
