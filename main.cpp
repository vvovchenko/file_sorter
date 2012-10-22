#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
    Config cfg("config.file");
    Filter fltr(cfg);
    EventHandler eh(fltr);
    EventEmitter em;

    em.start();

    return 0;
}
