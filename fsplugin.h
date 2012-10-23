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
    QString     pluginFileName; /**  Файл-плагин */
    QString     fileName; /** Файл, который необходимо обработать */
    QLibrary    lib; /** Динамическая библиотека (плагин) */
    pluginfunc  mainFunc; /** Главная bool функция плагина*/
public:
    /**
      @
        */
    FSPlugin(QString filename);

    void setPluginFileName(QString filename);
    void setFileName(QString filename);
    void loadPlugin();
    bool process();
    bool process(QString filename);

    QString getFileName();
    QString getPluginFileName();

    ~FSPlugin();
};

#endif // FSPLUGIN_H
