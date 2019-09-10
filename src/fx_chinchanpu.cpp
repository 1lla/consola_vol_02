#include <cstdlib>                   //for srand() rand()
#include <ctime>
#include <string>

#include "juego.h"

Chinchan::Chinchan()
    : Padre("Chin Chan Pu"){
        instruciones = "Estos son las instruciones para chinchan pu";
        lifes = 1;
    }

void Chinchan::play(){
        std::string userMovName;
        std::string robotMovName;
        int Cmov;
        int userMov;


        std::cout   << "\n\n\t" << tituloGame << "\n\n"
                    << instruciones << "\n" << std::endl;
        std::cout   << "\t[ 1 ] Piedra" << std::endl;
        std::cout   << "\t[ 2 ] Papel" << std::endl;
        std::cout   << "\t[ 3 ] Tijeras" << std::endl;

        std::cout   << "\tEscoge una opcion: ";
        userMov = getInt();
        validacion( userMov, 3); // valida la respuesta de user mov, el 3 es el max
        Cmov = getCmov();       //obtiene el movimieneto del robot

        userMovName = nombra(userMov);
        robotMovName = nombra(Cmov);

        std::cout << "\n-----------------------------";
        std::cout   << "\t" << userMovName
                    << "  VS  "
                    << robotMovName
                    << std::endl;
        switch ( compara(userMov, Cmov) ){
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
                case 1: return EMPATE;     // 2 de empate
                case 2: return 0;    // 0 de pierde
                case 3: return 1;     // 1 de Gana
            };
        break;

        case 2:     //papel
            switch ( c ){
                case 1: return 1;
                case 2: return 2;
                case 3: return 0;
            };
        break;
        case 3:
            switch ( c ){
                case 1: return 0;
                case 2: return 1;
                case 3: return 2;
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

