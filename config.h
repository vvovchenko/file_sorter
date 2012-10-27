#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

class Config
{
public:
    /**
     * @brief Конструктор.
     *
     * @detailed Открывает конфигурационный файл для чтения/записи.
     *
     * @param filename - имя файла конфига
     */
    Config(QString filename){};

    /**
     * @brief Прочитать значение.
     *
     * @param name - имя параметра
     *
     * @return Значение параметра или пустая строка, если параметр не найден
     */
    QString get_value(QString name){};

    /**
     * @brief Записать значение.
     *
     * @detailed Записывает значение параметра, если параметр отсутствует, то
     * создает его
     */
    void set_value(QString name, QString value){};
};

#endif // CONFIG_H
