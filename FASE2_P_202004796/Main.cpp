#include <iostream>

#include "crow.h"

#include<iostream>



using namespace std;

#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#include "listaUsuarios.cpp"
#include "colaTutorial.cpp"
#include "listaCategorias.cpp"

#include "pilaMovimientos.cpp"
#include "usersOrdenados.cpp"
#include "skinsOrdenados.cpp"



void cargar(listaUser &listaUsuarios, orden &usersOrdenados, colaTuto &colaTutorial, listaS2 &skinsOrdenados, listaS &listaSkins, lista &listaCategoria) {
    std::ifstream f("prueba.json");
    json data = json::parse(f);



    for (int i = 0; i < data["usuarios"].size(); i++)//cant de usuarios
    {
        string q1 = data["usuarios"][i]["nick"].get<string>();//Obtenemos el nickname del usuario en posicion i
        string q2 = data["usuarios"][i]["password"].get<string>();
        int q3 = stoi(data["usuarios"][i]["monedas"].get<string>());
        int q4 = stoi(data["usuarios"][i]["edad"].get<string>());
        int q5 = stoi(data["usuarios"][i]["id"].get<string>());
        usersOrdenados.insert(q1, q2, q3, q4);
        listaUsuarios.insert(q5, q1, q2, q3, q4); //ciframos contra
    }

    colaTutorial.agregar(stoi(data["tutorial"]["ancho"].get<string>()), stoi(data["tutorial"]["alto"].get<string>()));
    for (int i = 0; i < data["tutorial"]["movimientos"].size(); i++)//cant de usuarios
    {
        int q1 = stoi(data["tutorial"]["movimientos"][i]["x"].get<string>());//Obtenemos el x del movimiento en posicion i
        int q2 = stoi(data["tutorial"]["movimientos"][i]["y"].get<string>());
        colaTutorial.agregar(q1, q2);
    }

    for (int i = 0; i < data["articulos"].size(); i++)
    {
        string cat = data["articulos"][i]["categoria"].get<string>();
        int id = stoi(data["articulos"][i]["id"].get<string>());
        int precio = stoi(data["articulos"][i]["precio"].get<string>());
        string nombre = data["articulos"][i]["nombre"].get<string>();
        string src = data["articulos"][i]["src"].get<string>();
        listaSkins.agregar(id, cat, precio, nombre, src);
        skinsOrdenados.insert(id, cat, precio, nombre, src);

        if (listaCategoria.compararCategoria(cat) == false) {
            listaCategoria.agregar(cat);
            listaCategoria.agergarLista(id, cat, precio, nombre, src);
        }
        else {
            listaCategoria.agergarLista(id, cat, precio, nombre, src);
        }
    }

    cout << "listo" << endl;
}

int main()
{
    listaUser listaUsuarios;
    colaTuto colaTutorial;
    lista listaCategoria;
    listaS listaSkins;
    pilaM pilaMovimientos;
    orden usersOrdenados;
    listaS2 skinsOrdenados;


    string usuario, contra;

    cargar(listaUsuarios,usersOrdenados,colaTutorial,skinsOrdenados,listaSkins,listaCategoria);
    listaUsuarios.imprimir(); 

	crow::SimpleApp app;
	CROW_ROUTE(app, "/")([]() {
		return "Hello world";
		});
	

    //LOGIN ------------------------------------------------------------------------------------------
    CROW_ROUTE(app, "/login")
        .methods("POST"_method)([&listaUsuarios](const crow::request& req)
            {
                //convierte a json el string
                auto x = crow::json::load(req.body);
                //revisa que no este vacio
                if (!x)
                    return crow::response(400);
                string nick = x["nick"].s();
                string pass = x["password"].s();

                if (listaUsuarios.login(nick,pass)==true) {
                    
                    return crow::response(200);
                }
                else {
                    crow::json::wvalue cuerpo({ {"error", "usuario no encontrado"} });
                    crow::response send(std::move(cuerpo));
                    send.code = 700;
                    return send;
                }
            });
    // EDITAR USUARIO--------------------------------------------------------------------------------------
    CROW_ROUTE(app, "/edit")
        .methods("POST"_method)([&listaUsuarios](const crow::request& req)
            {
                //convierte a json el string
                auto x = crow::json::load(req.body);
                //revisa que no este vacio
                if (!x)
                    return crow::response(400);
                string user = x["user"].s();
                string new_user = x["new_user"].s();
                string new_pass = x["new_pass"].s();
                int new_age = stoi(x["new_age"].s());

                listaUsuarios.editarUsuario(user,new_user,new_pass,new_age);
                listaUsuarios.imprimir();
                return crow::response(200);
                
            });
    //BORRAR USUARIO--------------------------------------------------------------------------------------
    CROW_ROUTE(app, "/erase")
        .methods("POST"_method)([&listaUsuarios](const crow::request& req)
            {
                //convierte a json el string
                auto x = crow::json::load(req.body);
                //revisa que no este vacio
                if (!x)
                    return crow::response(400);
                string user = x["user"].s();
                

                listaUsuarios.borrar(user);
                listaUsuarios.imprimir();
                return crow::response(200);

            });
    // CREAR USUARIO--------------------------------------------------------------------------------------
    CROW_ROUTE(app, "/create")
        .methods("POST"_method)([&listaUsuarios](const crow::request& req)
            {
                //convierte a json el string
                auto x = crow::json::load(req.body);
                //revisa que no este vacio
                if (!x)
                    return crow::response(400);
                string user = x["user"].s();
                string pass = x["pass"].s();
                int age = stoi(x["age"].s());
                int id = stoi(x["id"].s());

                listaUsuarios.insert(id,user,pass,0,age);
                listaUsuarios.imprimir();
                return crow::response(200);

            });
    // AGREGAR MOV --------------------------------------------------------------------------------------
    CROW_ROUTE(app, "/agregar_mov")
        .methods("POST"_method)([&pilaMovimientos](const crow::request& req)
            {

                //convierte a json el string
                auto x = crow::json::load(req.body);
                //revisa que no este vacio
                if (!x)
                    return crow::response(400);
                int posx = stoi(x["x"].s());
                int posy = stoi(x["y"].s());

                pilaMovimientos.agregar(posx, posy);
                pilaMovimientos.imprimir();
                return crow::response(200);

            });
    // REGRESAR MOV --------------------------------------------------------------------------------------
    CROW_ROUTE(app, "/regresar_mov")
        .methods("GET"_method)([&pilaMovimientos]()
            {

                pilaMovimientos.eliminar();
                pilaMovimientos.imprimir();
                return crow::response(200);

            });
    // AGREGAR TOKENS----------------------------------------------
    CROW_ROUTE(app, "/agregar_tokens")
        .methods("POST"_method)([&listaUsuarios](const crow::request& req)
            {

                //convierte a json el string
                auto x = crow::json::load(req.body);
                //revisa que no este vacio
                if (!x)
                    return crow::response(400);
                string user = x["user"].s();

                listaUsuarios.agregarPuntos(user);
                return crow::response(200);

            });
    // REGRESAR MOV --------------------------------------------------------------------------------------
    CROW_ROUTE(app, "/reportes")
        .methods("GET"_method)([&listaUsuarios, &usersOrdenados, &colaTutorial, &skinsOrdenados, &pilaMovimientos, &listaCategoria]()
            {
                cout << "GRAFICA USERS\n\n" << endl;
                listaUsuarios.textoDot();
                cout << "}" << endl;
                cout << "\n\nGRAFICA TIENDA\n\n" << endl;
                listaCategoria.textoDot();
                cout << "}" << endl;
                cout << "\n\nGRAFICA TUTORIAL\n\n" << endl;
                colaTutorial.textoDot();
                cout << "}" << endl;
                cout << "\n\nGRAFICA MOVIMIENTOS\n\n" << endl;
                pilaMovimientos.textoDot();
                cout << "}" << endl;

                cout << "\n\nUSERS ASCENDENTE" << endl;
                usersOrdenados.imprimirAscendente();
                cout << "\n\nUSERS DESCENDENTE" << endl;
                usersOrdenados.imprimirDescendente();

                cout << "\n\nSKINS ASCENDENTE" << endl;
                skinsOrdenados.imprimirAscendente();
                cout << "\n\nSKINS DESCENDENTE" << endl;
                skinsOrdenados.imprimirDescendente();
                pilaMovimientos.eliminar();
                pilaMovimientos.imprimir();

                return crow::response(200);

            });
    app.port(8080).run();
}