#include "tablondecorativo.h"
#include<string>

using namespace std;

//Clase tablon para Articulos decorativos
    TablonDecorativo::TablonDecorativo(string tipo, float largo, float ancho, string fechaEntrada, string identificador, bool esfina)
    : Tablon::Tablon(tipo, largo, ancho, fechaEntrada, identificador), esfina(esfina){}

    bool TablonDecorativo::getEsfina(){return esfina;}

    float TablonDecorativo::calcularGanancia(){
        return getLargo()*getAncho()*(500 + (getEsfina()? 150 : 50));
    }

