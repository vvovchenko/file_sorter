#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QFile>
#include <QMap>

/**
 @brief Класс для работы с конфигурационным файлом
 
 @todo Использовать XML.
 @todo Обработка при аварийном завершении программы или завершении работы ОС.
 */
class Config
{
public:
    /**
     @brief Конструктор.
     
     @detailed Открывает конфигурационный файл для чтения. Читает все строки в
     конфигурационном и записывает их в conf. Значения в файле хранятся в 
     формате:
      key1
      value1
      key2
      value2
     
     @param filename - имя файла конфига
     */
    Config(QString filename);

    /**
     @brief Деструктор.
     
     @detailed Открывает конфигурационный файл и записывает conf в него.
     Значения записываются в формате:
      key1
      value1
      key2
      value2
     */
    ~Config();

    /**
     @brief Прочитать значение.
     
     @param name - имя параметра.
     
     @return Значение параметра или пустая строка, если параметр не найден.
     */
    QString get_value(QString name);

    /**
     @brief Записать значение.
     
     @detailed Записывает значение параметра в conf, если параметр
     отсутствует, то создает его.
     */
    void set_value(QString name, QString value);

private:
    /// Конфигурационый файл
    QFile *file;

    /// Текущее значение конфигурации, в конце работы оно будет записанно в файл
    QMap<QString, QString> conf;
};

#endif // CONFIG_H
