#ifndef EVENTEMITTER_H
#define EVENTEMITTER_H

class EventEmitter
{
    Q_OBJECT;
public:
    EventEmitter();

    /**
     * @brief Основной цикл программы.
     *
     * @detailed По тику таймера проверяет наличие новых файлов. Сигнал
     * file_added посылается только тогда, когда к файлу никто не обращается
     * (т.е. он уже загружен до конца и ниодна программа не работает с данным
     * файлом)
     */
    void start();

signals:
    /**
     * @brief Сигнал: файл добавлен.
     *
     * @detailed Вызывается когда нужно обработать файл.
     */
    void file_added(QString filename);
};

#endif // EVENTEMITTER_H
