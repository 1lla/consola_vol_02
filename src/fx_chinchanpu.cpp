#include <cstdlib>                   //for srand() rand()
#include <ctime>
#include <string>


#include "menu.h"
#include "juego.h"

Chinchan::Chinchan()
    : Padre("Chin Chan Pu"){
        instruciones = "\n\texisten tres elementos:\n";
        lifes = 1;
    }

void Chinchan::play(){
        std::string userMovName;
        std::string robotMovName;
        int Cmov;
        int userMov;

        subtitulo(tituloGame);
        std::cout << "\n" << instruciones << std::endl;
        std::cout   << "\t[ 1 ] Piedra\t que vence a la tijera rompiéndola" << std::endl;
        std::cout   << "\t[ 2 ] Papel\t que vence a la piedra envolviéndola y" << std::endl;
        std::cout   << "\t[ 3 ] Tijeras\t que vence al papel cortándolo" << std::endl;
        std::cout   << "\n\tEscoge una opcion: ";
        userMov = getInt();
        userMov = validacion( userMov, 3); // valida la respuesta de user mov, el 3 es el max
        Cmov = getCmov();       //obtiene el movimieneto del robot

        userMovName = nombra(userMov);
        robotMovName = nombra(Cmov);
            system("cls");
        subtitulo(tituloGame);
        std::cout   << "\n\t" << userMovName
                    << "  VS  "
                    << robotMovName
                    << std::endl;
        int res = compara(userMov, Cmov);
        switch (res){
                    case 0: gameoverText(); break;
                    case 1: youwinText(); break;
                    case 2: std::cout << "\n\t Empate"; break;
        }
}

int Chinchan::getCmov(){
        srand(time(0));
        int noRand = rand()%2;
        return noRand + 1;
}
enum {
    PERDISTE = 0,
    GANASTE = 1,
    EMPATE = 2
};

int Chinchan::compara( char u, int c){
    switch ( u - '0' ){
        case 1:     //piedra
            switch ( c ){
                case 1:
                    std::cout << "\n\tPiedra no rompe piedra, nadie gana." << std::endl;
                    return EMPATE;     // 2 de empate
                case 2:
                    std::cout << "\n\tPapel vence a la piedra envolviéndola." << std::endl;
                    return 0;    // 0 de pierde
                case 3:
                    std::cout << "\n\tPiedra rompe a la tijera." << std::endl;
                    return 1;     // 1 de Gana
            };
        break;

        case 2:     //papel
            switch ( c ){
                case 1:
                    std::cout   << "\n\tPapel vence a la piedra envolviéndola." << std::endl;
                    return 1;
                case 2:
                    std::cout   << "\n\tPapel no le hace nada al papel"
                                << "\n\tNadie gana." << std::endl;
                    return 2;
                case 3:
                    std::cout   << "Tijeras cortan papel" << std::endl;
                    return 0;
            };
        break;
        case 3:
            switch ( c ){
                case 1:
                    std::cout << "\n\tPiedra rompe a la tijera." << std::endl;
                    return 0;
                case 2:
                    std::cout << "\n\tTijeras cortan el papel." << std::endl;
                    return 1;

                case 3:
                    std::cout   << "\n\tTijera no corta tijera."
                                << "\n\tNadie gana."
                                << std::endl;
                    return 2;
            };
        break;
    }
    return 0;
}

std::string Chinchan::nombra( int v){
    std::string name;
    switch( v ){
        case 1 : name = "Piedra";   break;
        case 2 : name = "Papel";    break;
        case 3 : name = "tijeras";  break;
    }
    return name;
}

