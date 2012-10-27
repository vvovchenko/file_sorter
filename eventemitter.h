#ifndef EVENTEMITTER_H
#define EVENTEMITTER_H

#include <QFileSystemWatcher>
#include <QStringList>

class EventEmitter : public QObject
{
    Q_OBJECT
public:
    EventEmitter(){};

    /**
     @brief Основной цикл программы.

     @detailed По тику таймера проверяет наличие новых файлов. Сигнал
     file_added посылается только тогда, когда к файлу никто не обращается
     (т.е. он уже загружен до конца и ниодна программа не работает с данным
     файлом)

     @todo Загрузка имени каталога для загрузок из конфига
     */
    void start();

private:
    QFileSystemWatcher watcher;
    QStringList filelist;

public slots:
    /**
     @brief Слот: в каталоге произошли изменения.

     @detailed Сравнение старого и нового списков файлов, удаленяет
     несуществующие, а при добавлении нового вызывает file_added

     @param dir_name - имя каталога, в котором произошли изменения

     @todo Отслеживать изменения и в подкаталогах
     */
    void dir_changed(QString dir_name);

signals:
    /**
     @brief Сигнал: файл добавлен.

     @detailed Вызывается когда нужно обработать файл.

     @param Имя файла для обработки
     */
    void file_added(QString filename);
};

#endif // EVENTEMITTER_H
