#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

//#include "filter.h"
#include <QString>
#include <QObject>

/// @todo А нужен ли нам этот класс? Мб сразу ловить сигнал в фильтре?

class EventHandler : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор.
     *
     * @detailed Запоминает фильтр к которому будет обращаться.
     */
    EventHandler(){};

public slots:
    /**
     * @brief Слот: реакция на добавленный файл
     *
     * @detailed Должен передать имя файла фильтру
     */
    void handle(QString filename);
};

#endif // EVENTHANDLER_H
