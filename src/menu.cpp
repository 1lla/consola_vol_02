#include "../include/menu.h"

#include <iostream>
#include <cstdio>
#include <string>

// AQUI TODOS LAS IMPLIMENTACIONES
void inicio_menu(){
        char seleccion;

        titulo("MATA TIEMPOS");
        std::cout   << "\n\nHola! Así que quieres jugar una partida rapida."
                    << "\nTenemos para ti los siguentes juegos:\n\n"
                    << "\t [1] Juego Uno\n"
                    << "\t [2] Juego dos\n"
                    << "\t [3] Juego tres\n"
                    << "\t [0] Salir\n" << std::endl;


        std::cout   << "Por favor selecciona una opcion para continuar: ";
        std::cin    >> seleccion;
        callGame(seleccion);

}

///////// titulo ////////////////

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


int callGame(char s){
    switch(s){
        case '0':
            std::cout << "\nHasta la vista, Babie!" << std::endl;
            return 0;
        case '1': std::cout << "Escogiste: " << s << std::endl; break;
        case '2': std::cout << "Escogiste: " << s << std::endl; break;
        case '3': std::cout << "Escogiste: " << s << std::endl; break;
    }
};

