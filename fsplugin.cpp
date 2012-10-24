#include "fsplugin.h"

#include <iostream>
using namespace std;

FSPlugin::FSPlugin(QString filename)
{
    this->setPluginFileName(filename);
    this->loadPlugin();
}

FSPlugin::~FSPlugin()
{
    this->lib.unload();
}

QString FSPlugin::getPluginFileName()
{
    return this->plugin_file_name;
}

void FSPlugin::setPluginFileName(QString filename)
{
    this->plugin_file_name = filename;
}

void FSPlugin::setFileName(QString filename)
{
    this->file_name = filename;
}

QString FSPlugin::getFileName()
{
    return this->file_name;
}

void FSPlugin::loadPlugin()
{
    if (this->lib.isLoaded()) {
        this->lib.unload();
    }

    this->lib.setFileName(this->getPluginFileName());
    this->lib.load();

    this->main_func = (pluginfunc)(this->lib.resolve("fsmain"));
}

bool FSPlugin::process()
{
    return this->main_func(this->file_name);
}

bool FSPlugin::process(QString filename)
{
    this->setFileName(filename);
    return this->main_func(this->file_name);
}
