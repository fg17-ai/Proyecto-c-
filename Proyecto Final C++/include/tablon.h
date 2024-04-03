#ifndef TABLON_H
#define TABLON_H
#include <string>

using namespace std;

class Tablon{

protected:
    string tipo, fechaEntrada, identificador;
    float largo, ancho;
public:
    Tablon(string tipo, float largo, float ancho, string fechaEntrada, string identificador);


    float getLargo();
    float getAncho();
    string getTipo();
    string getFechaEntrada();
    string getIdentificador();

    virtual float calcularGanancia()=0;

    string tostring();
    virtual ~Tablon();
};

#endif // TABLON_H
