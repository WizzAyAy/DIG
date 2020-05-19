#pragma once

#include <QFile>
#include <QObject>
#include <QTextStream>
#include <string>

/*
 *  cette classe represente une base de donnée ou l'on stock apres chaque partie le score du joueur et son nom a la date du jour
*/

struct nuplet{
    int score;
    std::string name;
    std::string date;
};

class database : public QObject
{
    Q_OBJECT
public:
    database();
    //insert en derniere ligne du fichier un nouvel enregistrement
    void insertBase(const std::string &name, int const & score);
    //lit entierement la base
    void readBase();
    //methode qui emit le world record (plus gros score)
    void worldRecord();

signals:
    void wordlRecordSignal(int const & score, std::string const & name, std::string const & date);
private:
    QFile _dataBase;
    QTextStream _flux;
};

