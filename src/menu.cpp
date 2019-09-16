#include "../include/menu.h"
#include "../include/juego.h"
#include <conio.h>

#include <iostream>

#include <string>

// AQUI TODOS LAS IMPLIMENTACIONES
/*Padre hangmann("Hangmann");
Padre chinos("Chinos");
Padre chinchan("Chin chan poe");*/


Hangmann hangmann;
Chinos chinos;
Chinchan chinchan;


 int tHM;
 int tCH;
 int tCC;
 int tTJ;
////////////////////////////////
void inicia_menu_principal(){

    char answer;
       do{
            get_menu();
            // stuff to be repeated here
            system("cls");
            titulo("MATA TIEMPOS");
            std::cout   << "\n\tQuieres regresar al menu principal\n"
                        << "\n\tSi, regresar\t[ y ]"
                        << "\n\t para Salir\t[ x ]"
                        << std::endl;

            std::cin >> answer;


        }
        while (answer == 'y');
        goodbyetext();
}



void get_menu(){

        char seleccion;
        system("cls");
        titulo("MATA TIEMPOS");

        std::cout   << "\n\tAsi que quieres jugar una partida rapida."
                    << "\n\tTenemos para ti los siguentes juegos:\n\n"
                    << "\t [ 1 ] Hangman\n"
                    << "\t [ 2 ] Los Chinos\n"
                    << "\t [ 3 ] Chin Chan Pu\n"
                    << "\t [ 4 ] Estadisticas\n"
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
                    repeat = answer == 'y' ;

                }break;


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

            case '4':

                showEsta();

                break;

            default:
                goodbyetext();
                break;
        }
    return s;
};

//////////////////////////// Estadisticas //////////////////////////////////////

void showEsta(){

    tHM = hangmann.get_Pperd() + hangmann.get_Pgana()  + hangmann.get_pEmpat();
    tCH = chinos.get_Pperd()   + chinos.get_Pgana()    + chinos.get_pEmpat();
    tCC = chinchan.get_Pperd() + chinchan.get_Pgana()  + chinchan.get_pEmpat();
    tTJ = tHM + tCC + tCH;

    system("cls");
    titulo("Estadisticas");
    std::cout   << "\n\tTotal de partidads jugadas: "
                << tTJ << std::endl;

    std::cout   << "\n\n\t" << int_to_x100(tHM, tTJ)
                << "%   Hangmann"
                << "\n\n\t" << int_to_x100(tCH, tTJ)
                << "%   Chinos"
                << "\n\n\t" << int_to_x100(tCC, tTJ)
                << "%   Chin Chan Pu"
                << std::endl;

    std::cout   << "\n\t----------------------------------" << "\n\n\t"
                << hangmann.get_Pgana() + chinos.get_Pgana() + chinchan.get_Pgana()
                << "   Total de partidas ganadas "
                << "\n\t" << hangmann.get_Pperd() + chinos.get_Pperd() + chinchan.get_Pperd()
                << "   Total de partidas perdidas "
                << std::endl;
                makePausa();
}

float int_to_x100(int n, int NtX100){
    float x100;

    x100 = (n * 100) / NtX100;
    return x100;
}


void makePausa(){
    std::string nobody;
    std::cin >> nobody;
}


/////////////////////////////////////////////////


void goodbyetext(){
        system("cls");
        titulo("MATA TIEMPOS");
        std::cout << "\n\tHasta la vista, Babie!" << std::endl;
        std::cout << "\n\tMade whit <3 in Muenchen" << std::endl;
        std::cout << "\n\n\t\t2019" << std::endl;
        std::cout << "\n\tillahacandi.rivera@gmail.com " << std::endl;
        exit(EXIT_FAILURE); //salir para siempre
}
