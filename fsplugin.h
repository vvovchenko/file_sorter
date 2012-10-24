#ifndef FSPLUGIN_H
#define FSPLUGIN_H

#include <QString>
#include <qlibrary.h>

typedef bool(*pluginfunc)(QString filename);

/**
   @brief Класс для работы с плагинами FS
   @detailed Осуществляет подключение плагину при создании
   и закрывает соединение при уничтожении
  */
class FSPlugin
{
protected:
    QString     plugin_file_name; ///<  Файл-плагин
    QString     file_name; ///< Файл, который необходимо обработать
    QLibrary    lib; ///< Динамическая библиотека (плагин)
    pluginfunc  main_func; ///< Главная bool функция плагина, возвращает true, если файл обработан, иначе - else
public:
    /**
      @brief Конструктор
      @detailed Создается объект FSPlugin, который далее будет
                работать с плагином. Так же в конструкторе
                плагин загружается.
      @param filename - файл-плагин, который нужно загрузить.
        */
    FSPlugin(QString filename);

    /**
      @brief Установить имя файла-плагина.
      @detailed Связывает файл-плагин с объектом.
      @param filename - файл-плагин, который нужно связать с объектом.
        */
    void setPluginFileName(QString filename);

    /**
      @brief Установить имя файла, который будет обработан плагином.
      @detailed Установить имя файла, который будет обработан плагином.
      @param filename - файл, обрабатываемый плагином.
        */
    void setFileName(QString filename);

    /**
      @brief Загрузить файл-плагин.
      @detailed Загрузить файл-плагин. Если он уже загружен - то он будет
                выгружен и загружен заново. Это может понадобиться, если
                у текущего объекта изменить путь к файлу-плагину.
        */
    void loadPlugin();

    /**
      @brief Обработать файл плагином.
      @detailed Обрабатывает файл плагином, вызывая главную функцию из
                плагина bool fsmain(QString filename) и передавая файл,
                связанный с текущим объектом.
        */
    bool process();

    /**
      @brief Обработать файл плагином.
      @detailed Обрабатывает файл плагином, вызывая главную функцию из
                плагина bool fsmain(QString filename).
      @param filename - файл, обрабатываемый плагином.
        */
    bool process(QString filename);

    /**
      @brief Получить имя обрабатываемого файла, связанного с текущим объектом.
      @detailed Возвращает имя файла, связанного с текущим объектом,
                который будет обработан плагином.
        */
    QString getFileName();

    /**
      @brief Получить имя файла-плагина, связанного с текущим объектом.
      @detailed Возвращает имя файла-плагина, связанного с текущим объектом.
        */
    QString getPluginFileName();

    /**
      @brief Деструктор
      @detailed Выгружает плагин из памяти.
        */
    ~FSPlugin();
};

#endif // FSPLUGIN_H
