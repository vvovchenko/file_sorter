#include "filter.h"

Filter::Filter(Config& conf)
{
    this->setPluginCount(conf.get_value("plugin_count").toInt()); ///< Загружаем количество плагинов

    for (int i = 0; i < this->getPluginCount(); i++) { ///< Загружаем имена плагинов формата plugin_n_X , где X - номер плагина
        this->plugin_file_list.push_back(conf.get_value("plugin_n_") + QString::number(i));
    }
}

void Filter::setPluginCount(int count)
{
    this->plugin_count = count;
}

int Filter::getPluginCount()
{
    return this->plugin_count;
}

void Filter::process(QString filename)
{
    bool processed = false;
    int used_plugin_number = 0;
    QString used_plugin;

    while (!processed) {
        used_plugin = this->plugin_file_list[used_plugin_number];
        FSPlugin processor(used_plugin);

        if (processor.process(filename)) {
            processed = true;
            delete &processor;
            break;
        }
    }
}
