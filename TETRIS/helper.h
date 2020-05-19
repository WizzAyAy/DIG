#pragma once

#include "patternwidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <vector>

/*
 *  classe qui gere les touches utilisateur, elle peuvent etre changée et son sauvegarder dans un fichier text pour la prochaine utilisation
*/

struct key{
    QLabel* label;
    QLineEdit* key;
};

class helper : public patternWidget
{
    Q_OBJECT
public:
    helper();
    void hideHelper();
    void showHelper();

    QPushButton* getBackButton(){return _back;}
    std::vector<Qt::Key> getKey(){return _keyToEmit;}

    //regarde si toutes les touches sont bien differente et toutes des lettres
    bool checkAllKey();
    //met toutes les touches dans le vecteur de touche
    void updateKey();
    //permet juste d'emettre les touches
    void emitKey();

    //lit le fichier des touches
    void readFile();
    //sauvegarde les touches dans un fichier
    void saveKeyInFile();
    //transpose les touches du fichier dans le jeu
    void fileKeyToGame();
    //remet les touches par default
    void resetKeyToDefault();

    void paintEvent(QPaintEvent *s);

public slots:
    //permet de lancer des sons en fonction de la validitée des touches
    void validKey();

signals:
    void playSound(std::string name);
    void newKey(std::vector<Qt::Key> k);

private:
    std::vector<key> _vectorKey;
    std::vector<Qt::Key> _keyToEmit;

    QString _fileName;
    QFile _file;
    QTextStream _flux;

    QPushButton* _saveKey;
    QPushButton* _defaultKey;
    QPushButton* _back;
    QVBoxLayout* _layout;
    bool _allKeyValid;
};
