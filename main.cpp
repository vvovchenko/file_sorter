#include <QCoreApplication>
#include "eventhandler.h"
#include "eventemitter.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    //Config cfg("config.file");
    //Filter fltr(cfg);
    EventHandler eh;//(fltr);
    EventEmitter em;

    QObject::connect(&em, SIGNAL(file_added(QString)),
                     &eh, SLOT(handle(QString)));

    qDebug() << "Start...";
    em.start();

    return app.exec();
}
