#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QTime>
#include <QTextStream>
#include <QDebug>

#define WRITE_LOG_TO_FILE

void msgHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	Q_UNUSED(context)
	QString messageLevel;

	switch(type)
	{
	case QtDebugMsg:
			messageLevel = "DEBUG";
			break;
	case QtWarningMsg:
			messageLevel = "WARNING";
			break;
	case QtCriticalMsg:
			messageLevel = "CRITICAL";
			break;
	case QtFatalMsg:
			messageLevel = "FATAL";
	}

	QTextStream out(stdout);
	out <<QTime::currentTime().toString("h:m:s") <<" [" <<messageLevel << "] " <<msg <<"\n";

#ifdef WRITE_LOG_TO_FILE
	QFile file("Log.log");
	QTextStream outF(&file);
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	outF <<QTime::currentTime().toString("h:m:s") <<" [" <<messageLevel << "] " <<msg <<"\n";
	file.flush();
	file.close();
#endif
}

#endif // LOG_H
