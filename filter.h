#ifndef FILTER_H
#define FILTER_H

#include "config.h"
#include <QString>
#include <QVector>
#include "fsplugin.h"

/**
  @brief Класс, который обрабатывает и сортирует файлы.
  @detailed Загружает плагины и обрабатывает определенный файл этими плагинами
   */
class Filter
{
protected:
    QVector<QString> plugin_file_list; ///< Список имен файлов-плагинов, в текущем объекте Filter. Считывается из конфига из "plugin_n_X" , где X - номер плагина
    int plugin_count; ///< Количество плагинов. Считывается из конфига из "plugin_count"

public:
    /**
      @brief Конструктор.
      @detailed Читает из конфига количество и имена файлов плагинов
                для загрузки и загружает их в список plugin_file_list
      @param &conf - Класс Config, из которого будут читаться настройки.
     */
    Filter(Config &conf);

    /**
      @brief Загрузить список файлов-плагинов.
      @detailed Читает из конфига имена библиотек для загрузки и загружает их в список plugin_file_list.
     */
    void loadPluginList();

    /**
      @brief Установить количество используемых файлов-плагинов.
      @detailed Устанавливает количество используемый файлов-плагинов для текущего объекта.
      @param count - Количество используемый файлов-плагинов.
       */
    void setPluginCount(int count);

    /**
      @brief Получить количество используемых файлов-плагинов.
      @detailed Получает количество используемый файлов-плагинов для текущего объекта.
       */
    int getPluginCount();

    /**
      @brief Обработать файл.
      @detailed Опрашивает все плагины, на предмет ты обработаешь файл, если
                да, то отправляем ему файл.
      @param filename - имя файла
     */
    void process(QString filename);
};

#endif // FILTER_H
