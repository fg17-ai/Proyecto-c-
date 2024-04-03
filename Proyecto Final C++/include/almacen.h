#ifndef ALMACEN_H
#define ALMACEN_H
#include <vector>
#include "tablon.h"
#include<string>


class Almacen{
    protected:
    vector<Tablon*> v_tablon;
    int cantidad_tablones;

    public:
    Almacen();

    void setV_tablon(vector<Tablon*> v_tablon);
    vector<Tablon*> getV_tablon()const;
    void setCantidad_tablones(int cantidad_tablones);
    int getCantidad_tablones()const;

    void agregar(Tablon* tab);
    void eliminar(std::string identificador);
    float ganancia_un_tablon(std::string identificador);
    float ganancia_total();
    int buscar(std::string identificador);
    std::string operator ~();
};

#endif // ALMACEN_H
