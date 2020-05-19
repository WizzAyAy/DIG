#include "database.h"

#include <iostream>
#include <sstream>
#include <ctime>

database::database()
    : QObject(), _dataBase("./res/save/database.txt"), _flux(&_dataBase){
    _flux.setCodec("UTF-8");
    worldRecord();
}

void database::insertBase(const std::string &name, const int &score){
    if(name == "") return;
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d/%m/%Y %H:%M",timeinfo);
    std::string str(buffer);


        if(!_dataBase.open(QIODevice::ReadWrite| QIODevice::Text))
            return;
        //je lis tout pour mettre le pointeur a la fin du fichier
        _dataBase.readAll();
        _flux << score << " " << QString::fromStdString(name) << " " << QString::fromStdString(str) << endl;

    _dataBase.close();
}

void database::readBase(){
    if(!_dataBase.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString ligne;
    while(! _flux.atEnd())
    {
        ligne = _flux.readLine();
        std::cout << ligne.toStdString() << std::endl;
    }
    _dataBase.close();
}

void database::worldRecord(){
    if(!_dataBase.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString ligne;
    nuplet wr = {0,"pas encore de wr","jamais"};
    int tmpScore;
    std::string tmpString;
    while(! _flux.atEnd())
    {
        ligne = _flux.readLine();
        std::stringstream ssin(ligne.toStdString());
        ssin >> tmpString;
        tmpScore = stoi(tmpString);
        if(tmpScore > wr.score){
            wr.score = tmpScore;
            ssin >> wr.name;
            ssin >> wr.date;
            ssin >> tmpString;
            wr.date += " à ";
            wr.date += tmpString;
        }
    }
    _dataBase.close();
    emit wordlRecordSignal(wr.score, wr.name, wr.date);
}
