#include <QCoreApplication>
#include <QDebug>
#include "log.h"

int main(int argc, char *argv[])
{
	qInstallMessageHandler(msgHandler);
	QCoreApplication a(argc, argv);

	qDebug() << "HAHO message";
    return a.exec();
}
