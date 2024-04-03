#include "almacen.h"
#include<iostream>
#include<vector>
#include<string>


    Almacen::Almacen(){cantidad_tablones=0;};

    void Almacen::setV_tablon(vector<Tablon*> v_tablon){this->v_tablon = v_tablon;};
    vector<Tablon*> Almacen::getV_tablon()const{return v_tablon;};
    void Almacen::setCantidad_tablones(int cantidad_tablones){this->cantidad_tablones = cantidad_tablones;};
    int Almacen::getCantidad_tablones()const{return cantidad_tablones;}

    void Almacen::agregar(Tablon* tab){
        if(buscar((*tab).getIdentificador())!=-1)
            std::cout<<"Este tablon ya fue agregado"<<endl;
        else{
            v_tablon.push_back(tab);
            cantidad_tablones++;
        }
    }

    void Almacen::eliminar(std::string identificador){
        int indice = buscar(identificador);
        if(indice==-1)
            std::cout<<"El tablon no existe"<<endl;
        else
            v_tablon.erase(v_tablon.begin()+indice);
            cantidad_tablones--;
    }

    float Almacen::ganancia_un_tablon(std::string identificador){
        int indice = buscar(identificador);
        if(indice != -1){
                return (*v_tablon[indice]).calcularGanancia();
        }else{
            std::cout<<"El tablon no existe"<<endl;
            return 0.0;
            }
    }

    float Almacen::ganancia_total(){
        float suma = 0;
        for(auto vec : v_tablon){
            suma+=ganancia_un_tablon((*vec).getIdentificador());
        }
        return suma;
    }

    int Almacen::buscar(std::string identificador){
        int indice = 0;
        while(indice < cantidad_tablones && (*v_tablon[indice]).getIdentificador() != identificador){
                indice++;
        }
        return indice == cantidad_tablones? -1 : indice;
    }


    std::string Almacen::operator ~(){
        std::string mostrar = "El almacen contiene " + std::to_string(this -> getCantidad_tablones())+"\n";
        if(this -> getCantidad_tablones()==0){
            mostrar = "El almacen no contiene tablones aun.";
        }
        for(auto vec : this -> getV_tablon()){
            mostrar += vec->tostring() + '\n';
        }
        return mostrar;
    }
