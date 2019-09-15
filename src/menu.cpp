#include "../include/menu.h"
#include "../include/juego.h"

#include <iostream>

#include <string>

// AQUI TODOS LAS IMPLIMENTACIONES
/*Padre hangmann("Hangmann");
Padre chinos("Chinos");
Padre chinchan("Chin chan poe");*/


Hangmann hangmann;
Chinos chinos;
Chinchan chinchan;

////////////////////////////////
void inicia_menu_principal(){
        bool repeat = true;

        while (repeat){

            get_menu();
            // stuff to be repeated here
            system("cls");
            titulo("MATA TIEMPOS");
            std::cout   << "\n\tQuieres jugar otra cosa?\n"
                        << "\n\tRegresa al menu principal"
                        << "\n\tSi, regresar\t[ y ]"
                        << "\n\n\tCualquier otra tecla"
                        << "\n\t para Salir\t[ x ]"
                        << std::endl;
            char answer;
            std::cin >> answer;
            repeat = answer == 'y';
        }
}



void get_menu(){

        char seleccion;
        system("cls");
        titulo("MATA TIEMPOS");

        std::cout   << "\n\tAsi que quieres jugar una partida rapida."
                    << "\n\tTenemos para ti los siguentes juegos:\n\n"
                    << "\t [1] Hangman\n"
                    << "\t [2] Los Chinos\n"
                    << "\t [3] Chin Chan Pu\n"
                    << "\n\t Para salir\n"
                    << "\tCualquier otra tecla" << std::endl;
        std::cout   << "\n\tSelecciona una opcion para continuar: ";
        std::cin    >> seleccion;
        callGame(seleccion);
}

///////// titulo ////////////////

void subtitulo(std::string name){
        system("cls");
        titulo("MATA TIEMPOS");
        std::cout   << "\n\t     "
                    << name
                    << std::endl;
}




void titulo(std::string texto){
    int longitud;
    std::string fakeTab = "     ";

    longitud = texto.size();

    linea(longitud);
    lineaVacia(longitud);
    std::cout << "\n\t*" << fakeTab << texto << fakeTab << "*";
    lineaVacia(longitud);
    linea(longitud);
}

void linea(int l){              // para el titulo y subtitulo
        std::cout << "\n\t" ;
         for(int i= 0 ; i <= (l + 11); i++){
                std::cout << "*";
        };

};

void lineaVacia(int l){              // para el titulo y subtitulo
        std::cout << "\n\t*";
         for(int i= 0 ; i <= (l + 9); i++){
                std::cout << " ";
        };
        std::cout << "*";
};

//////////////// call game //////////////////


int callGame(char s){
        bool repeat = true;
        switch(s){
            case '1'://////////////////////////////////////////////
                while (repeat){
                    hangmann.play();
                    // stuff to be repeated here

                    std::cout   << "\n\n\tQuieres intentarlo otra vez?"
                                << "\n\n\t[ y ] Otra vez soga al cuello"
                                << "\n\t[ x ] Muerto, Salir"
                                << "\n\tTambien cualquier otra tecla para salir."
                                << std::endl;
                    std::cout   << "\n\tPor favor selecciona una opcion para continuar: ";
                    char answer;
                    std::cin >> answer;
                    repeat = answer == 'y';
                    answer = 0;
                }

                break;
            case '2':
                while (repeat){
                    chinos.play();
                    // stuff to be repeated here

                    std::cout   << "\n\tOtra vez partida?"
                            << "\n\t[ y ] A contar canicas"
                            << "\n\t[ x ] No. Salir"
                            << "\n\tCualquier otra tecla";

                    char answer;
                    std::cin >> answer;
                    repeat = answer == 'y';
                }
                break;
            case '3':
                while (repeat){
                    chinchan.play();
                    // stuff to be repeated here

                    std::cout   << "\n\tOtra vez?"
                                << "\n\t[ y ] Revancha"
                                << "\n\t[ x ] No. Salir";

                    char answer;
                    std::cin >> answer;
                    repeat = answer == 'y';
                }
                break;
            default:
                system("cls");
                titulo("MATA TIEMPOS");
                std::cout << "\n\tHasta la vista, Babie!" << std::endl;
                std::cout << "\n\tMade whit <3 in Muenchen" << std::endl;
                std::cout << "\n\n\t\t2019" << std::endl;
                std::cout << "\n\tillahacandi.rivera@gmail.com " << std::endl;
                exit(EXIT_FAILURE); //salir para siempre
                break;
        }
    return s;
};



