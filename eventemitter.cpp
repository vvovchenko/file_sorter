#include <Qt/QtCore>
#include "eventemitter.h"
#include <QFileSystemWatcher>
#include <QStringList>
#include <QtAlgorithms>
#include <QDebug>

/**
 @todo Рекурсивный поиск в подкаталогах
 @todo Загрузка имени каталога для загрузок из конфига
 */

void EventEmitter::start()
{
    QDir dir("/home/stamerlan/Debug/");
    filelist = dir.entryList();
    watcher.addPath("/home/stamerlan/Debug/");
    connect(&watcher, SIGNAL(directoryChanged(QString)),
            SLOT(dir_changed(QString)));
}

void EventEmitter::dir_changed(QString dir_name)
{
    qDebug() << "dir_name:" << dir_name;
    QDir dir(dir_name);

    QStringList entry_list = dir.entryList();
    QStringList old_list = filelist;
    qDebug() << "entry_list:" << entry_list;
    qDebug() << "old_list  :" << old_list;

    for (auto it = entry_list.begin(); it != entry_list.end(); ++it) {
        QStringList::Iterator f = qFind(old_list.begin(), old_list.end(), *it);
        if (f == old_list.end()) {
            // Это новый файл, добавить его в filelist
            qDebug() << "New file: " << *it;
            filelist.push_back(*it);
            emit file_added(dir_name + *it);
        } else {
            // Этот файл уже был в каталоге
            old_list.erase(f);
        }
    }

    /* Теперь список old_list содержит файлы, которые были в каталоге, но теперь
       их нет, удалим их из filelist */
    for (auto it = old_list.begin(); it != old_list.end(); ++it) {
        filelist.erase(qFind(filelist.begin(), filelist.end(), *it));
    }

    qDebug() << "filelist: " << filelist;
}
