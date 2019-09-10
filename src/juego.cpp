#include <iostream>
#include "juego.h"


Padre::Padre(const std::string& titulo){
    tituloGame = titulo;
    }

Padre::~Padre(){}


void Padre::gameoverText(){
    std::cout << "\n\n    d888b   .d8b.  .88b  d88. d88888b       .d88b.  db    db d88888b d8888b. " << std::endl;
    std::cout << "   88' Y8b d8' `8b 88'YbdP`88 88'          .8P  Y8. 88    88 88'     88  `8D " << std::endl;
    std::cout << "   88      88ooo88 88  88  88 88ooooo      88    88 Y8    8P 88ooooo 88oobY' " << std::endl;
    std::cout << "   88  ooo 88~~~88 88  88  88 88~~~~~      88    88 `8b  d8' 88~~~~~ 88`8b   " << std::endl;
    std::cout << "   88. ~8~ 88   88 88  88  88 88.          `8b  d8'  `8bd8'  88.     88 `88. " << std::endl;
    std::cout << "    Y888P  YP   YP YP  YP  YP Y88888P       `Y88P'     YP    Y88888P 88   YD " << std::endl;
    std::cout << "\n" << std::endl;
}

void Padre::youwinText(){
    std::cout << "\n\tFelicidades, ganaste!\n\n" << std::endl;
    std::cout << "Yb  dP  dP\"Yb   88°88     Yb        dP 88 88b 88 " << std::endl;
    std::cout << " YbdP  dP   Yb 88   88      Yb  db  dP  88 88Yb88 " << std::endl;
    std::cout << "  8P   Yb   dP Y8   8P       YbdPYbdP   88 88 Y88 " << std::endl;
    std::cout << " dP     YbodP  `YbodP'        YP  YP    88 88  Y8 " << std::endl;
}


int Padre::getInt(){
    char vchar;
    std::cin >>  vchar;
    return vchar - '0';
}

int Padre::validacion( int entra, int maximo){
    while ( entra > maximo ){
        std::cout << "\n\tCreo que te has equivocado,\n\ttrátalo otra vez: ";
        entra = getInt();
    }
    return entra;
}




