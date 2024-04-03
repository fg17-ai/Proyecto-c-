#ifndef TABLONMUEBLES_H
#define TABLONMUEBLES_H
#include<string>
#include"tablon.h"

using namespace std;

//Clase Tablon para muebles
class TablonMuebles : public Tablon {
    public:
    TablonMuebles(string tipo, float largo, float ancho, string fechaEntrada, string identificador);

    float calcularGanancia() override ;
};
#endif // TABLONMUEBLES_H
