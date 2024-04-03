#ifndef TABLONENCOFRADO_H
#define TABLONENCOFRADO_H
#include<string>
#include"tablon.h"

using namespace std;

//Clase tablon para Encofrados
class TablonEncofrado : public Tablon {
private:
    string resistencia;

public:
    TablonEncofrado(string tipo, float largo, float ancho, string fechaEntrada, string identificador, string resistencia);

    string getResistencia();

    float cantidad_tablas();
    float calcularGanancia() override;

};

#endif // TABLONENCOFRADO_H
