#include <cstdlib>                   //for srand() rand()
#include <ctime>
#include "juego.h"
#include "menu.h"

std::string allWords[13]= {"mentira", "escribir", "elefante", "reingresar", "cerebro", "escrito", "implementacion", "imagen", "resferiado", "helaedo", "egoistas", "cafe", "necesitar" };

Hangmann::Hangmann()
  : Padre("Hangmann" ){
        instruciones = "\n\tEste es el juego de Ahorcado de toda la vida\n\tTienes que adivinar una palabra apartir de letras.\n\tTienes 5 oportunidades para adivinar";



  }

void Hangmann::play(){

    do{
        game();
    }


/*
    bool have_i_won = game();
    if (true == have_i_won) {
        youWin();

    } else {
        youLose();
     }
*/
}


bool Hangmann::game(){
    word = getWort();
    lifes = 5;
    amorfa = createAmorfa(word);

        subtitulo(tituloGame);
        std::cout << "\n" << instruciones << "\n" << std::endl;
    std::cout   << "\n\tTu palabra tiene " << word.length()
                << " letras." << std::endl;
    std::cout   << "\n\t" << amorfa << std::endl;


    while ( lifes > 0 ){ // Primero, se puede jugar, hay vidas?
        std::cout   << "\n\tAun tienes " << lifes << " vidas." << std::endl;
        std::cout   << "\n\tQue letra escojes? ";
        char wortU = getUserW();                                                             // User tipp die erste buchstabe
        int  contador = 0;                                                                      // inicia contador

        for(size_t i = 0; i < word.length(); i++){                                         // por cada letra de la palabra haz:{
            char wortNturno = word[i];                                              // wortNturno letra en turno

            if ( wortNturno == wortU ){                                              // si en la letra en turno es igual a la latra del usuario
                amorfa[i] = wortNturno;                                             // dibuja en amorfa la letra adivinada
                contador++;                                                         // suma un valor x cada letra adivinada aunque se la misma

                system("cls");
                subtitulo(tituloGame);
                std::cout << "\n\n\tMuy bien, sigue adelante\n"<< std::endl;                //. Esto ayuda a no quitar vidas si alguien preciona dos veces sin querer la misma letra
                std::cout << "\n\t" << amorfa << std::endl;

                if ( amorfa == word ){  return true; }
                //ganar
            }
        }

        if( contador <= 0 ){                                                             // si contador se queda igual haz
             system("cls");
             subtitulo(tituloGame);
            std::cout << "\n\tnope. Try again\n"<< std::endl;                     // limpia todo, muestra el inicio
            std::cout << "\n\t" << amorfa << std::endl;                      // MUESTRA EL ESTADO ACTUAL DE AMORFA
            lifes --;                                                           //quita una vida
        }
    }
  return false;                                                                      // si ya no hay vidas, pierdes

}



std::string Hangmann::getWort(){
    srand(time(0));
    int noRand = rand() % (sizeof(allWords) / sizeof(allWords[1]));  //rando()%5 donde 5 es el valor maximo
    return allWords[noRand];
}


std::string Hangmann::createAmorfa(std::string xx){       //en los parentices es la informacion que entre
    std::string a(xx.length(), '-');                 //creas a y le pones una linea por cada uno de sus largos
    return a;                                   //regresa valor de a
}


char Hangmann::getUserW(){
    char a;
    std::cin >> a;
    return a;
}


void Hangmann::youLose(){
    pPerdi++;
    system("cls");
    gameoverText();
    std::cout << "\n\tPss. La palabra original es : " << word << std::endl;
    std::cout << "\n\tPero tu llegaste a esto     : " << amorfa << std::endl;
}

void Hangmann::youWin(){
    pGanad++;
    youwinText();
}

