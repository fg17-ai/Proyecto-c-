#ifndef TABLONDECORATIVO_H
#define TABLONDECORATIVO_H
#include<string>
#include"tablon.h"

using namespace std;

//Clase tablon para Articulos decorativos
class TablonDecorativo : public Tablon{
public:
    bool esfina;
    TablonDecorativo(string tipo, float largo, float ancho, string fechaEntrada, string identificador, bool esfina);

    bool getEsfina();

    float calcularGanancia() override;
};

#endif // TABLONDECORATIVO_H
