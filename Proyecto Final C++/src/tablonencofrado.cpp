#include "tablonencofrado.h"
#include<string>

using namespace std;

//Clase tablon para Encofrados
    TablonEncofrado::TablonEncofrado(string tipo, float largo, float ancho, string fechaEntrada, string identificador, string resistencia)
        : Tablon::Tablon(tipo, largo, ancho, fechaEntrada, identificador), resistencia(resistencia) {}

    string TablonEncofrado::getResistencia(){return resistencia;}

    float TablonEncofrado::cantidad_tablas(){return (getLargo() > 3) ? 10 : 5;}
    float TablonEncofrado::calcularGanancia(){
        double factor_resistencia = (resistencia == "alta") ? 3 : (resistencia == "media") ? 2 : 1;
        return cantidad_tablas() * 200 * factor_resistencia;
    }
