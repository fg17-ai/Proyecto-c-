#include "tablonmuebles.h"
#include<string>

using namespace std;

//Clase Tablon para muebles

    TablonMuebles::TablonMuebles(string tipo, float largo, float ancho, string fechaEntrada, string identificador)
        : Tablon::Tablon(tipo, largo, ancho, fechaEntrada, identificador){}

    float TablonMuebles::calcularGanancia() {
        double area = getLargo() * getAncho();
        return area * 500;
    }

