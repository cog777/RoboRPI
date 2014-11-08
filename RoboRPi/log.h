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
	QTime timeStamp = QTime::currentTime();

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

	QString fullMessage;
	QTextStream textBuilder(&fullMessage);
	textBuilder << timeStamp.toString("hh:mm:ss.zzz") << " [" << messageLevel << "] " << msg << " File:" << context.file << \
		   " Function:" << context.function << " Line:" << context.line << "\n";

	QTextStream out(stdout);
	out << fullMessage;

#ifdef WRITE_LOG_TO_FILE
	QFile file("Log.log");
	QTextStream outF(&file);
	file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
	outF << fullMessage;
	file.flush();
	file.close();
#endif
}

#endif // LOG_H
