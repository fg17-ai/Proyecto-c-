#include "tablon.h"
#include <iostream>
#include <string>

using namespace std;

    Tablon::Tablon(string tipo, float largo, float ancho, string fechaEntrada, string identificador)
    : tipo(tipo), largo(largo), ancho(ancho), fechaEntrada(fechaEntrada), identificador(identificador) {}


    float Tablon::getLargo(){return largo;}
    float Tablon::getAncho(){return ancho;}
    string Tablon::getTipo(){return tipo;}
    string Tablon::getFechaEntrada(){return fechaEntrada;}
    string Tablon::getIdentificador(){return identificador;}

    string Tablon::tostring(){
    string mostrar = identificador + " _ " + tipo + " _ " + fechaEntrada;
        return mostrar;
    }

    Tablon::~Tablon(){}
