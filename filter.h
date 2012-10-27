#ifndef FILTER_H
#define FILTER_H

#include "config.h"
#include <QString>

class Filter
{
public:
    /**
     * @brief Конструктор.
     *
     * @detailed Читает из конфига имена библиотек для загрузки и загружает их.
     */
    Filter(Config& conf) {};

    /**
     * @brief Обработать файл.
     *
     * @detailed Опрашивает все плагины, на предмет ты обработаешь файл, если
     * да, то отправляем ему файл.
     *
     * @param filename - имя файла
     */
    void process(QString filename) {};
};

#endif // FILTER_H
