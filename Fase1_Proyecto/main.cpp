#include<iostream>

#include <bits/stdc++.h>
using namespace std;
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include "listaUsuarios.cpp"
#include "colaTutorial.cpp"
#include "listaCategorias.cpp"
#include "Sha256.cpp"
#include "pilaMovimientos.cpp"
#include "usersOrdenados.cpp"
#include "skinsOrdenados.cpp"
listaUser listaUsuarios;
colaTuto colaTutorial;
lista listaCategoria;
listaS listaSkins;
pilaM pilaMovimientos;
orden usersOrdenados;
listaS2 skinsOrdenados;


string usuario,contra;

void cargar(){
    std::ifstream f("prueba.json");
    json data = json::parse(f);

    SHA256 sha; //uso de sha256 para encriptar
    
    for (int i = 0; i < data["usuarios"].size(); i++)//cant de usuarios
    {
        string q1=data["usuarios"][i]["nick"].get<string>();//Obtenemos el nickname del usuario en posicion i
        string q2=data["usuarios"][i]["password"].get<string>();
        int q3=data["usuarios"][i]["monedas"].get<int>();
        int q4=data["usuarios"][i]["edad"].get<int>();
        usersOrdenados.insert(q1,SHA256::cifrar(q2),q3,q4);
        listaUsuarios.insert(q1,SHA256::cifrar(q2),q3,q4); //ciframos contra
    }
   
    colaTutorial.agregar(data["tutorial"]["ancho"].get<int>(),data["tutorial"]["alto"].get<int>());
    for (int i = 0; i < data["tutorial"]["movimientos"].size(); i++)//cant de usuarios
    {
        int q1=data["tutorial"]["movimientos"][i]["x"].get<int>();//Obtenemos el x del movimiento en posicion i
        int q2=data["tutorial"]["movimientos"][i]["y"].get<int>();
        colaTutorial.agregar(q1,q2);
    }

    for (int i = 0; i < data["articulos"].size(); i++)
    {
        string cat=data["articulos"][i]["categoria"].get<string>();
        int id=data["articulos"][i]["id"].get<int>();
        int precio=data["articulos"][i]["precio"].get<int>();
        string nombre=data["articulos"][i]["nombre"].get<string>();
        string src=data["articulos"][i]["src"].get<string>();
        listaSkins.agregar(id,cat,precio,nombre,src);
        skinsOrdenados.insert(id,cat,precio,nombre,src);

        if(listaCategoria.compararCategoria(cat)==false){
            listaCategoria.agregar(cat);
            listaCategoria.agergarLista(id,cat,precio,nombre,src);
        }else{
            listaCategoria.agergarLista(id,cat,precio,nombre,src);
        }
    }
    

}

void registrar(){
    string new_nombre, new_contra;
    int new_edad;
    cout<<"Ingrese nuevo user..."<<endl;
    cin>>new_nombre;
    if(listaUsuarios.compararNombre(new_nombre)==false){
        cout<<"Ingrese password..."<<endl;
        cin>>new_contra;
        cout<<"Ingrese edad..."<<endl;
        cin>>new_edad;
        listaUsuarios.insert(new_nombre,SHA256::cifrar(new_contra),0,new_edad);
        cout<<"User creado con exito :)\n"<<endl;
    }else{
        cout<<"User ya existente :/"<<endl;
    }
}

void menu2(){
    cout<<"\nSeleccione una opcion...\n1. Editar informacion\n2. Eliminar cuenta\n3. Tutorial\n4. Ver tienda\n5. Realizar movimientos\n6. Menu principal"<<endl;
    string opc;
    cin>>opc;
    if(opc=="1"){
        string new_user,new_pass;
        int new_age;
        cout<<"Ingrese nuevo user:"<<endl;
        cin>> new_user;
        cout<<"Ingrese nueva password:"<<endl;
        cin>> new_pass;
        cout<<"Ingrese nueva edad:"<<endl;
        cin>> new_age;
        listaUsuarios.editarUsuario(usuario,new_user,SHA256::cifrar(new_pass),new_age);
        cout<<"Datos actualizados :)"<<endl;
        listaUsuarios.imprimir();
        menu2();
    }else if(opc=="2"){
        cout<<"\nEsta seguro que desea eliminar su cuenta permanentemente? [s/n]"<<endl;
        cin>>opc;
        if(opc=="s" or opc=="S"){
            listaUsuarios.borrar(usuario);
        }else{
            menu2();
        }
    }else if(opc=="3"){
        cout<<"\nTutorial:"<<endl;
        colaTutorial.imprimir();
        menu2();
    }else if(opc=="4"){
        cout<<"\nTienda:"<<endl;
        cout<<"\nID\r\t\tNombre\r\t\t\t\tCategoria\r\t\t\t\t\t\tPrecio"<<endl;
        listaSkins.imprimir();
        menu2();    
    }else if(opc=="5"){
        int x,y;
        cout<<"\n\n\nRealizar vovimientos:"<<endl;
        string mov;
        while (mov!="salir"){
            cin>>mov;
            if (mov!="salir"){
                int i=0;
                for (char c : mov){
                    if(i==0){
                        x= c-48;
                    }else if(i==2){
                        y= c-48;
                    }
                    i+=1;
                }
                pilaMovimientos.agregar(x,y);
            }
        }
        cout<<"Movimientos guardados :)"<<endl;
        listaUsuarios.agregarPuntos(usuario);

        menu2();
        
    }else if(opc=="6"){
        
    }else{
        cout<<"Ingrese una opcion valida :/"<<endl;
        menu2();
    }
}

void login(){
    cout<<"\n=====LOGIN====="<<endl;
    cout<<"User..."<<endl;
    cin>>usuario;
    cout<<"Password..."<<endl;
    cin>>contra;
    if (listaUsuarios.login(usuario,SHA256::cifrar(contra))==true){
        cout<<"\nBIENVENIDO"<<endl;
        menu2();
    }else{
        cout<<"User o Password incorrectos :/"<<endl;
    }
}

void graficaUsuarios(){
    string x;
    x="";
    x+="digraph G { \n";
    x+="node[shape=elipse] \n";
    int j=0;
    
    
}

void menu(){
    graficaUsuarios();
    cout<<"\n\n\n==========MENU========="<<endl;
    cout<<"Seleccione una opcion...\n1. Carga masiva\n2. Registrar usuario\n3. Login\n4. Reportes\n5. Salir"<<endl;
    string opc;
    cin>>opc;
    if(opc=="1"){
        cargar();
        menu();
    }else if(opc=="2"){
        registrar();
        menu();
    }else if(opc=="3"){
        login();
        menu();
    }else if(opc=="4"){
        cout<<"GRAFICA USERS\n\n"<<endl;
        listaUsuarios.textoDot();
        cout<<"}"<<endl;
        cout<<"\n\nGRAFICA TIENDA\n\n"<<endl;
        listaCategoria.textoDot();
        cout<<"}"<<endl;
        cout<<"\n\nGRAFICA TUTORIAL\n\n"<<endl;
        colaTutorial.textoDot();
        cout<<"}"<<endl;
        cout<<"\n\nGRAFICA MOVIMIENTOS\n\n"<<endl;
        pilaMovimientos.textoDot();
        cout<<"}"<<endl;

        cout<<"\n\nUSERS ASCENDENTE"<<endl;
        usersOrdenados.imprimirAscendente();
        cout<<"\n\nUSERS DESCENDENTE"<<endl;
        usersOrdenados.imprimirDescendente();

        cout<<"\n\nSKINS ASCENDENTE"<<endl;
        skinsOrdenados.imprimirAscendente();
        cout<<"\n\nSKINS DESCENDENTE"<<endl;
        skinsOrdenados.imprimirDescendente();
        menu();
    }else if(opc=="5"){

    }else{
        cout<<"Ingrese una opcion valida :/"<<endl;
    }
}

int main(int argc, char const *argv[])
{
    menu();
}