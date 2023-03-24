#include <iostream>
#include <list>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string>

#include "Pokemon.h"
#include "Pikachu.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Squirtle.h"
#include "Psyduck.h"
#include "Buizel.h"
#include "GeneradorAleatorio.h"
#include "Entrenadores.h"

using namespace std;

int main()
{
    GeneradorAleatorio generador;

    Entrenadores entrenadores;

    list<Pokemon*>* listaAzul = new list <Pokemon*>;
    list<Pokemon*>* listaRoja = new list <Pokemon*>;

    list <Pokemon*>::iterator posA;
    list <Pokemon*>::iterator posR;

    bool azulEligio = false;
    bool rojoEligio = false;
    bool azulSeleccionado = false;
    bool rojoSeleccionado = false;
    bool inicioPelea = true;
    bool hayGanador = false;
    int puntosAzul = 0;
    int puntosRojo = 0;
    string turnoEntrenador;

    cout << "\tBienvenidos al Combate Pokemon!" << endl << endl << "Presione una tecla para continuar...";
    getch();
    system("cls");

    entrenadores.Reglas();
    getch();
    system("cls");

    if (generador.ElegirEntrenador() == 1){

        turnoEntrenador = "AZUL";
    }
    else  if (generador.ElegirEntrenador() == 2){

        turnoEntrenador = "ROJO";
    }

    do{

        if(turnoEntrenador == "AZUL" && !azulEligio){
            //turno Azul
            std::cout << "\t-- ENTRENADOR AZUL --" << std::endl;

            entrenadores.ElegirPokemon(listaAzul);
            entrenadores.RecorrerLista(listaAzul, turnoEntrenador);

            std::cout << "\n\nPresione cualquier tecla para continuar...";
            getch();
            system("cls");

            turnoEntrenador = "ROJO";
            azulEligio = true;
        }

        if (turnoEntrenador == "ROJO" && !rojoEligio){
            //turno Rojo
            std::cout << "\t-- ENTRENADOR ROJO --" << std::endl;

            entrenadores.ElegirPokemon(listaRoja);
            entrenadores.RecorrerLista(listaRoja, turnoEntrenador);

            std::cout << "\n\nPresione cualquier tecla para continuar...";
            getch();
            system("cls");

            turnoEntrenador = "AZUL";
            rojoEligio = true;
        }
    }while(!azulEligio || !rojoEligio);

    posA = listaAzul->begin();
    posR = listaRoja->begin();

    std::cout << "Pokemones elegidos. Presione cualquier boton para seleccionar Pokemones para la batalla...";
    getch();

    do{
        system("cls");
        if (turnoEntrenador == "AZUL" && !azulSeleccionado){
            std::cout << "\t-- ENTRENADOR AZUL --" << std::endl;

            int numeroElegido;
            entrenadores.RecorrerLista(listaAzul, turnoEntrenador);
            std::cout << "\nIngrese el numero del Pokemon que desee seleccionar para la Batalla Pokemon." << std::endl;
            std::cin >> numeroElegido;

            while(numeroElegido < 1 || numeroElegido > 3){
                std::cout << "Entrada invalida. Intente nuevamente." << std::endl << std::endl;
                std::cin >> numeroElegido;
            }

            numeroElegido -= 1;
            int i;
            for (i = 0; i < numeroElegido; i++){
                posA++;
            }
            std::cout << "El ENTRENADOR AZUL ha liberado a " << (*posA)->getNombrePokemon() << std::endl;
            std::cout << "\nPresione una tecla para continuar...";
            getch();

            turnoEntrenador = "ROJO";
            azulSeleccionado = true;
        }

        if (turnoEntrenador == "ROJO" && !rojoSeleccionado){
            std::cout << "\t-- ENTRENADOR ROJO --" << std::endl;

            int numeroElegido;
            entrenadores.RecorrerLista(listaRoja, turnoEntrenador);
            std::cout << "\nIngrese el numero del Pokemon que desee seleccionar para la Batalla Pokemon" << std::endl;
            std::cin >> numeroElegido;

            while(numeroElegido < 1 || numeroElegido > 3){
                std::cout << "Entrada invalida. Intente nuevamente." << std::endl << std::endl;
                std::cin >> numeroElegido;
            }

            numeroElegido -= 1;
            int i;
            for (i = 0; i < numeroElegido; i++){
                posR++;
            }
            std::cout << "\n\nEl ENTRENADOR ROJO ha liberado a " << (*posR)->getNombrePokemon() << std::endl;
            std::cout << "\nPresione una tecla para continuar...";
            getch();

            turnoEntrenador = "AZUL";
            rojoSeleccionado = true;
        }
    }while(!azulSeleccionado || !rojoSeleccionado);

    std::cout << "- Entrenadores y Pokemones listos -\nPresione 'x' para CONTINUAR o cualquier otra tecla para SALIR" << std::endl;


    while(getch() == 'x' || !hayGanador){

        if (inicioPelea){
            std::cout << "\tLa Batalla Pokemon empieza en..." << std::endl;
            Sleep(2500);
            std::cout << "\t3..." << std::endl;
            Sleep(1000);
            std::cout << "\t2..." << std::endl;
            Sleep(1000);
            std::cout << "\t1..." << std::endl;
            Sleep(1000);
            std::cout << "\tPELEEN! " << std::endl;
            Sleep(1500);
            system("cls");
            inicioPelea = false;
        }

        if (turnoEntrenador == "AZUL" && (*posA)->getVida() > 0){
            std::cout << "\t- AZUL ATACA -" << std::endl << std::endl;

            std::cout << (*posA)->getNombrePokemon() << " ataca a " << (*posR)->getNombrePokemon() <<
            " con un ataque de " << (*posA)->ataque((*posR)) << "puntos" << std::endl << std::endl;

            std::cout << "La salud de " << (*posR)->getNombrePokemon() << " queda en " <<
            (*posR)->getVida() << " puntos." << std::endl << std::endl;

            turnoEntrenador = "ROJO";
        }
        if ((*posA)->getVida() <= 0){
            std::cout << "\t- AZUL -" << std::endl;
            std::cout << "\nEl Pokemon " << (*posA)->getNombrePokemon() << " del ENTRENADOR AZUL ha sido derrotado" << std::endl;

            posA = listaAzul->begin();

            int numeroElegido;
            entrenadores.RecorrerLista(listaAzul, turnoEntrenador);
            std::cout << "\nIngrese el numero del Pokemon que desee seleccionar para la Batalla Pokemon" << std::endl;
            std::cin >> numeroElegido;

            while(numeroElegido < 1 || numeroElegido > 3){
                std::cout << "Entrada invalida. Intente nuevamente." << std::endl << std::endl;
                std::cin >> numeroElegido;
            }

            numeroElegido -= 1;
            int i;
            for (i = 0; i < numeroElegido; i++){
                posA++;
            }

            while ((*posA)->getVida() <= 0){
                std::cout << "\nEste Pokemon esta fuera de combate. Elija otro..." << std::endl;
                posA = listaAzul->begin();
                std::cin >> numeroElegido;
                numeroElegido -= 1;
                int i;
                for (i = 0; i < numeroElegido; i++){
                    posA++;
                }
            }

            std::cout << "\n\nEl ENTRENADOR ROJO ha liberado a " << (*posA)->getNombrePokemon() << std::endl;
            puntosRojo++;
            std::cout << "\nPresione una tecla para continuar...";
            getch();
        }

        std::cout << "--------------" << std::endl << std::endl;

        if (turnoEntrenador == "ROJO" && (*posR)->getVida() > 0){
            std::cout << "\t- ROJO ATACA -" << std::endl << std::endl;

            std::cout << (*posR)->getNombrePokemon() << " ataca a " << (*posA)->getNombrePokemon() <<
            " con un ataque de " << (*posR)->ataque((*posA)) << "puntos" << std::endl << std::endl;

            std::cout << "La salud de " << (*posA)->getNombrePokemon() << " queda en " <<
            (*posA)->getVida() << " puntos." << std::endl << std::endl;

            turnoEntrenador = "AZUL";
        }
        if ((*posR)->getVida() <= 0){
            std::cout << "\t- ROJO -" << std::endl;
            std::cout << "El Pokemon " << (*posR)->getNombrePokemon() << " del ENTRENADOR ROJO ha sido derrotado" << std::endl;

            posR = listaRoja->begin();

            int numeroElegido;
            entrenadores.RecorrerLista(listaRoja, turnoEntrenador);
            std::cout << "\nIngrese el numero del Pokemon que desee seleccionar para la Batalla Pokemon" << std::endl;
            std::cin >> numeroElegido;

            while(numeroElegido < 1 || numeroElegido > 3){
                std::cout << "Entrada invalida. Intente nuevamente." << std::endl << std::endl;
                std::cin >> numeroElegido;
            }

            numeroElegido -= 1;
            int i;
            for (i = 0; i < numeroElegido; i++){
                posR++;
            }

            while ((*posR)->getVida() <= 0){
                std::cout << "\nEste Pokemon esta fuera de combate. Elija otro..." << std::endl;
                posR = listaRoja->begin();
                std::cin >> numeroElegido;
                numeroElegido -= 1;

                for (int i = 0; i < numeroElegido; i++){
                    posR++;
                }
            }

            std::cout << "\n\nEl ENTRENADOR ROJO ha liberado a " << (*posR)->getNombrePokemon() << std::endl;
            puntosAzul++;
            std::cout << "\nPresione una tecla para continuar...";
            getch();
        }

        std::cout << "--------------" << std::endl << std::endl;

        if (puntosAzul >= 3 || puntosRojo >= 3){
            hayGanador = true;
        }
    };

    std::cout << "\t\tBatalla terminada! " << std::endl;
    std::cout << "\tEl GANADOR de la batalla es... ";
    Sleep(3000);

    if (puntosAzul = 3){
        std::cout << "ENTRENADOR AZUL!!!" << std::endl << std::endl;
    }

    if (puntosRojo = 3){
        std::cout << "ENTRENADOR ROJO!!!" << std::endl << std::endl;
    }

    entrenadores.LimpiarLista(listaAzul);
    entrenadores.LimpiarLista(listaRoja);

    delete listaAzul;
    delete listaRoja;

    std::cout << "Gracias por jugar" << std::endl << "Presione cualquier tecla para finalizar...";

    //agregar pausas y limpieza de pantalla

    return 0;
}

//for (i = 1; i > 2; i++)
