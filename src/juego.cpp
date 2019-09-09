#include <iostream>
#include <string>
#include <time.h>
#include <cstdio>
#include <cstdlib>                   //for srand() rand()
#include <vector>



#include "../include/juego.h"
#include "../include/fx_hangmann.h"


Padre::Padre(const std::string& titulo){
    tituloGame = titulo;
    }

Padre::~Padre(){
    std::cout << "Se destruyO Juego_Padre" << std::endl;
    }

void Padre::gameoverText(){
    std::cout << "\n\n    d888b   .d8b.  .88b  d88. d88888b       .d88b.  db    db d88888b d8888b. " << std::endl;
    std::cout << "   88' Y8b d8' `8b 88'YbdP`88 88'          .8P  Y8. 88    88 88'     88  `8D " << std::endl;
    std::cout << "   88      88ooo88 88  88  88 88ooooo      88    88 Y8    8P 88ooooo 88oobY' " << std::endl;
    std::cout << "   88  ooo 88~~~88 88  88  88 88~~~~~      88    88 `8b  d8' 88~~~~~ 88`8b   " << std::endl;
    std::cout << "   88. ~8~ 88   88 88  88  88 88.          `8b  d8'  `8bd8'  88.     88 `88. " << std::endl;
    std::cout << "    Y888P  YP   YP YP  YP  YP Y88888P       `Y88P'     YP    Y88888P 88   YD " << std::endl;
    std::cout << "\n" << std::endl;
}



// CHINOS //////////////////

Chinos::Chinos()
    : Padre("Juego de los Chinos"){
        instruciones = "Tu y dos amigos Paco y Pablo, tienen 3 canicas cada uno\n Todos ponen en un saca de 0 a 3 canicas\nGanas si adivinas cuantas canicas hay en el saco";
        lifes = 1;

    }




void Chinos::play(){
     srand(time(0));



    std::cout   << "\n\n\t" << tituloGame << "\n\n"
                << instruciones << "\n"
                << std::endl;

    std::cout   << "Ahora, dime: Cuantas canicas sacaste?: ";
    std::cin    >> userC;


    std::cout   << "\nSabes, Cuantas canicas crees que son?: ";
    std::cin    >> userT;

// con vertir respuestas a int
    person1 = getNum();
    person2 = getNum();
    sum = person1 + person2 + (userC - '0');

    std::cout   << "\nPablo puso\t" << person1
                << "\ny Paco puso\t" << person2
                << "\n\nEn el saco hay: " << sum
                << std::endl;

    compara(userT, sum);

}

void Chinos::youWin(){
    std::cout << "felicidades" << std::endl;
}

void Chinos::youLose(){
    gameoverText();
}

int Chinos::getNum(){
    int noRand = rand() %3;
    return noRand;
}

 void Chinos::compara(char us, int su){
    if ( (us - '0') == su ){
        youWin();
    }else{
        youLose();
    }
 }



///////////////////////////////////////////
////// info von hangmann //

std::string allWords[13]= {"mentira", "escribir", "elefante", "reingresar", "cerebro", "escrito", "implementacion", "imagen", "resferiado", "helaedo", "egoistas", "cafe", "necesitar" };

Hangmann::Hangmann()
  : Padre("Hangmann" ){
        instruciones = "\n\tEste es el juego de Ahorcado de toda la vida\n\tTienes que adivinar una palabra apartir de letras.\n\tTienes 5 oportunidades para adivinar";
        lifes = 5;

  }

void Hangmann::play()
{
    bool have_i_won = game();
    if (true == have_i_won) {
        youWin();
    } else {
        youLose();
    }
}


bool Hangmann::game(){



    word = getWort();
    amorfa = createAmorfa(word);

   std::cout   << "\n\n\t" << tituloGame << "\n\n"
                << instruciones << "\n"
                << std::endl;

    std::cout   << "\nTu palabra tiene " << word.length()
                << " letras." << std::endl;
    std::cout   << "\n\t" << amorfa << std::endl;


    while ( lifes > 0 ) // Primero, se puede jugar, hay vidas?
    {
        std::cout << "\nAun tienes " << lifes << " vidas. Tecla una letra para iniciar: ";
        char wortU = getUserW();                                                             // User tipp die erste buchstabe
        int  contador = 0;                                                                      // inicia contador

        for(size_t i = 0; i < word.length(); i++)                                         // por cada letra de la palabra haz:
        {
            char wortNturno = word[i];                                              // wortNturno letra en turno

            if ( wortNturno == wortU )                                              // si en la letra en turno es igual a la latra del usuario
            {

                amorfa[i] = wortNturno;                                             // dibuja en amorfa la letra adivinada
                contador++;                                                         // suma un valor x cada letra adivinada aunque se la misma
                std::cout << "\nMuy bien, sigue adelante\n"<< std::endl;                //. Esto ayuda a no quitar vidas si alguien preciona dos veces sin querer la misma letra
                std::cout << "\n     " << amorfa << std::endl;

                if (amorfa == word )                                                // si amorfa tiene todas sus letras
                {
                    return true;
                    //youWin();                                                   // entonces ganas y te sales del juego

                }

            }
        }
        if( contador <= 0 )                                                             // si contador se queda igual haz
        {

            std::cout << "\nnope. Try again\n"<< std::endl;                     // limpia todo, muestra el inicio
            std::cout << "\n     " << amorfa << std::endl;                      // MUESTRA EL ESTADO ACTUAL DE AMORFA
            lifes --;                                                           //quita una vida
        }



    }

                                                                         // si ya no hay vidas, pierdes
    return false;



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
    gameoverText();
    std::cout << "\nPss. La palabra original es : " << word << std::endl;
    std::cout << "\nPero tu solo tenias esto    : " << amorfa << std::endl;

}

void Hangmann::youWin(){
    std::cout << "Felicidades, ganaste!\n\n" << std::endl;
    std::cout << "Yb  dP  dP\"Yb   88°88     Yb        dP 88 88b 88 " << std::endl;
    std::cout << " YbdP  dP   Yb 88   88      Yb  db  dP  88 88Yb88 " << std::endl;
    std::cout << "  8P   Yb   dP Y8   8P       YbdPYbdP   88 88 Y88 " << std::endl;
    std::cout << " dP     YbodP  `YbodP'        YP  YP    88 88  Y8 " << std::endl;
                               // se acabo. salir del juego
}
