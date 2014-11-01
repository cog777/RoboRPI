#include <QCoreApplication>
#include <QDebug>
#include <log.h>

int main(int argc, char *argv[])
{
	qInstallMessageHandler(msgHandler);
	QCoreApplication a(argc, argv);

    return a.exec();
}
