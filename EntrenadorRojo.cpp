#include "EntrenadorRojo.h"

#include <conio.h>

EntrenadorRojo::EntrenadorRojo(){

    this->listaRoja = new std::list <*Pokemon>;
}

EntrenadorRojo::~EntrenadorRojo(){

    delete this->listaRoja;
}

void EntrenadorRojo::ElegirPokemon(){

    int elegidos = 0;

        int i;

        cout << "¡Entrenador Rojo, eliga a sus 3 Pokemon!" << endl;

        do{
            for (i = 1; i > 2; i++){

                int opciones = generador->ElegirPokemon();

                if (opciones == 1){
                    cout << "\n1) Pikachu" << endl;
                }

                if (opciones == 2){
                    cout << "\n2) Bulbasaur" << endl;
                }

                if (opciones == 3){
                    cout << "\n3) Charmander" << endl;
                }

                if (opciones == 4){
                    cout << "\4) Squirtle" << endl;
                }

                if (opciones == 5){
                    cout << "\n5) Psyduck" << endl;
                }

                if (opciones == 6){
                    cout << "\6) Buizel" << endl;
                }
            }

            int eleccion;
            cin >> eleccion;

            if (eleccion == 1){
                Pikachu* raton = new Pikachu();
                listaRoja->push_back(raton);
                cout << "Has elegido ha " << raton->getNombrePokemon() << endl;
                elegidos++;
            }

            if (eleccion == 2){
                Bulbasaur* planta = new Bulbasaur();
                listaRoja->push_back(planta);
                cout << "Has elegido ha " << planta->getNombrePokemon() << endl;
                elegidos++;
            }

            if (eleccion == 3){
                Charmander* dragon = new Charmander();
                listaRoja->push_back(dragon);
                cout << "Has elegido ha " << dragon->getNombrePokemon() << endl;
                elegidos++;
            }

            if (eleccion == 4){
                Squirtle* tortuga = new Squirtle();
                listaRoja->push_back(tortuga);
                cout << "Has elegido ha " << tortuga->getNombrePokemon() << endl;
                elegidos++;
            }

            if (eleccion == 5){
                Psyduck* pato = new Psyduck();
                listaRoja->push_back(pato);
                cout << "Has elegido ha " << pato->getNombrePokemon() << endl;
                elegidos++;
            }

            if (eleccion == 6){
                Buizel* nutria = new Buizel();
                listaRoja->push_back(nutria);
                cout << "Has elegido ha " << nutria->getNombrePokemon() << endl;
                elegidos++;
            }

            else{
                cout << "Solo puede elegir los pokemon que esten en pantalla" << endl;
            }

        }while(elegidos != 3 || getch());
    }
}
