#include "config.h"
#include <QFile>
#include <QDebug>

Config::Config(QString filename)
{
    file = new QFile(filename);
    if (file->open(QIODevice::ReadOnly)) {
        QTextStream stream(file);
        QString key;
        QString value;

        while (!stream.atEnd()) {
            if (key.isEmpty()) {
                stream >> key;
                continue;
            }
            if (value.isEmpty()) {
                stream >> value;
            }

            conf[key] = value;

            key.clear();
            value.clear();
        }
        file->close();
    }
    else {
        qDebug() << "Couldn't open file \"" << filename << "\" for reading";
    }
}

Config::~Config()
{
    // Запись значений в file
    if (file->open(QIODevice::WriteOnly)) {
        QTextStream stream(file);
        for (auto i = conf.begin(); i != conf.end(); ++i) {
            stream << i.key() << endl << i.value() << endl;
        }
        file->close();
    }
    else {
        qDebug() << "Couldn't open file \"" << file->fileName() << "\" for " \
                    "writing";
    }

    delete file;
}

QString Config::get_value(QString name)
{
    if (conf.contains(name)) {
        return conf[name];
    }
    else
        return QString();
}

void Config::set_value(QString name, QString value)
{
    conf[name] = value;
}
