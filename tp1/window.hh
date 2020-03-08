#pragma once
#include <QtWidgets>
#include <vector>
#include <string>


class window : public QWidget
{
    Q_OBJECT
public:
    window();
    void onclickEgal();
    QPushButton* getButton(){return _egale;}
signals:
    void signalWindow(std::vector<std::string> attr);
public slots:
    void changeRes(int a);
private:
    QSpinBox* _op1;
    QSpinBox* _op2;
    QComboBox* _symbole;
    QPushButton* _egale;
    QLCDNumber* _resultat;
};
