#include<iostream>
#include<string>
#include"tablonmuebles.h"
#include"tablondecorativo.h"
#include"tablonencofrado.h"
#include"almacen.h"
#include<ctime>
//g++ main.cpp tablon.cpp tablonmuebles.cpp tablondecorativo.cpp tablonencofrado.cpp almacen.cpp -o programa.exe

using namespace std;


void menu_principal();



int main(){
    time_t now = time(nullptr);
    tm* tiempo = localtime(&now);
    string fecha = to_string(tiempo->tm_mday) +"/"+ to_string(tiempo->tm_mon + 1) +"/"+ to_string(tiempo->tm_year + 1900);
    int opcion1 = 0, opcion2 = 0;
    Almacen* alm = new Almacen();
    Tablon* tab;
    int codigo = alm -> getCantidad_tablones();
    string tipo;
    float largo,ancho;
    string id;
    int op;



    while(opcion1 != 6){
        menu_principal();
        cin>>opcion1;
        if(opcion1==1){
            //Leer los datos de los tablones y agregarlos al almacen
            cout<<"Que tipo de madera es la del tablon"<<endl;
            cin>>tipo;
            cout<<"Indique largo del tablon"<<endl;
            cin>>largo;
            cout<<"Indique el ancho del tablon"<<endl;
            cin>>ancho;
            cout<<"Teclee la opcion indicada para el uso del tablon\n"<<
                        "1. Muebles.\n"<<
                        "2. Articulos Decorativos.\n"<<
                        "3. Encofrado.\n";
                cin>>opcion2;
                if(opcion2==1){
                        tab = new TablonMuebles(tipo,largo,ancho,fecha,"M-"+to_string(++codigo));
                        alm->agregar(tab);
                }else if(opcion2==2){
                        cout<<"La madera es fina?\n"<<
                        "1. Si          2. No\n";
                        cin>> op;
                        tab = new TablonDecorativo(tipo,largo,ancho,fecha,"M-"+to_string(++codigo),op==1?true:false);
                        alm->agregar(tab);
                } else if(opcion2==3){
                        cout<<"Indique la reistencia de la madera\n"<<
                            "1. Baja          2. Media          3. Alta\n";
                        cin>> op;
                        tab = new TablonEncofrado(tipo,largo,ancho,fecha,"M-"+to_string(++codigo),op==1?"baja":op==2?"media":"alta");
                        alm->agregar(tab);
                }else{
                        cout<<"La opcion marcada no es correcta"<< endl;
                }
                 cout<< "El tablon fue agregado de forma correcta....\n";
        } else if(opcion1==2){
            cout<< "Teclee el identificador del tablon deseado\n"<<endl;
            cin>>id;
            if(alm->ganancia_un_tablon(id)!= 0){
                    float ganancia = alm->ganancia_un_tablon(id);
                cout<< "La ganancia esperada para ese tablon es: \n"<< ganancia <<endl;
            }
        }else if(opcion1==3){
            float ganancia_total = alm->ganancia_total();
            cout<<"\n\n\n La ganancia total que se espera de los tablones almacenados es: "<<ganancia_total<<endl;
        } else if(opcion1==4){
            cout<<"Indique el identificador del tablon que desea despachar.\n"<<endl;
            cin >> id;
            alm->eliminar(id);
             cout<< "El tablon "<<id<<" fue elimnado correctamente.\n";
        } else if(opcion1==5){
            string imprimir = ~(*alm);
            cout<< imprimir<<endl;
        }else if(opcion1==6){
             cout<<"Cerrando el programa.............";
            return 0;
        }else{
            cout<<"La opcion marcada es incorrecta"<< endl;
        }
    }



    delete(tab);
    delete(alm);
    return 0;
}

void menu_principal(){
    cout<<"******************************************************\n"<<
    "*****Bienvenido al Sistema de Control del Almacen*****\n"
    "#Marque el numero de su eleccion para realizar dicha accion y presione enter#\n"<<
    "1. Agregar un tablon al almacen.\n"<<
    "2. Obtener la ganancia esperada de cierto tablon.\n"<<
    "3. Obtener la ganancia total esperada de los tablones almacenados.\n"<<
    "4. Dar baja a un tablon para su uso.\n"<<
    "5. Mostrar los datos del almacen.\n"<<
    "6. Cerrar el sistema.\n";

}
