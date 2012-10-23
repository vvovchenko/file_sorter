#ifndef FILTER_H
#define FILTER_H

#include "config.h"
#include <QString>
#include "fsplugin.h"

class Config
{
public:
    Config() {}
};

class Filter
{
protected:
    QVector<QString> pluginFileList;
public:
    /**
     * @brief Конструктор.
     * @detailed Читает из конфига имена библиотек для загрузки и загружает их.
     */
    Filter(Config& conf);

    /***************************************/
    void loadPluginList();

    /***************************************/

    /**
     * @brief Обработать файл.
     *
     * @detailed Опрашивает все плагины, на предмет ты обработаешь файл, если
     * да, то отправляем ему файл.
     *
     * @param filename - имя файла
     */
    void process(QString filename);
};

#endif // FILTER_H
