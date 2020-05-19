#pragma once

#include <QtWidgets>
#include <string>

/*
 * class qui derive du QPushButton, elle represente un QPushButton avec deux information de plus un cout et un effet avec le signal qui les donnes
*/

class powerButton : public QPushButton
{
    Q_OBJECT
public:
    powerButton(const QString &text, QWidget* parent, const int &cost, const std::string &effect);
    powerButton() = default;
    void isClicked();


signals :
     void powerEmit(int cost, std::string effect);

private:
    int _cost;
    std::string _effect;
};
