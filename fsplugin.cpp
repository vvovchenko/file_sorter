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
    return this->pluginFileName;
}

void FSPlugin::setPluginFileName(QString filename)
{
    this->pluginFileName = filename;
}

void FSPlugin::setFileName(QString filename)
{
    this->fileName = filename;
}

QString FSPlugin::getFileName()
{
    return this->fileName;
}

void FSPlugin::loadPlugin()
{
    if (this->lib.isLoaded()) {
        this->lib.unload();
    }

    this->lib.setFileName(this->getPluginFileName());
    this->lib.load();

    this->mainFunc = (pluginfunc)(this->lib.resolve("fsprocess"));
}

bool FSPlugin::process()
{
    return this->mainFunc(this->fileName);
}

bool FSPlugin::process(QString filename)
{
    this->setFileName(filename);
    return this->mainFunc(this->fileName);
}
