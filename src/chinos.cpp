#include <cstdlib>                   //for srand() rand()
#include <ctime>
#include "juego.h"

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
    youwinText();
    }

void Chinos::youLose(){
    gameoverText();
}

// nejorar
int Chinos::getNum(){
        int noRand = rand()%3;
        return noRand;
}

 void Chinos::compara(char us, int su){
    if ( (us - '0') == su ){
        youWin();
    }else{
        youLose();
    }
 }

