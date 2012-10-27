#include "eventhandler.h"
#include <QDebug>

void EventHandler::handle(QString filename)
{
    qDebug() << "handle(" << filename << ")";
    //filter.process(filename);
}
