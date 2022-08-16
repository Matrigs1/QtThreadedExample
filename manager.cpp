#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{

}

Manager::~Manager()
{
    quit();
}

void Manager::process()
{
    //async - vai rodar a func com o objeto em outro thread
    QFuture<void> value = QtConcurrent::run(Manager::createWorker, this);
}

void Manager::quit()
{
    qInfo() << "Stopping Manager";
    //emite o signal stop para quem tiver usando o slot
    emit stop();
}

void Manager::createWorker(Manager *manager)
{
    qInfo() << "Creating Worker";
    //recomendado usar shared
    Worker* worker = new Worker();
    connect(manager, &Manager::start, worker, &Worker::start, Qt::QueuedConnection);
    connect(manager, &Manager::stop, worker, &Worker::stop, Qt::QueuedConnection);
    //chama a start do worker
    worker->start();
}
