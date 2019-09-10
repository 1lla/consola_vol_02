#include <cstdlib>                   //for srand() rand()
#include <ctime>
#include "juego.h"

Chinos::Chinos()
    : Padre("Juego de los Chinos"){
        instruciones = "Tu y dos amigos: Paco y Pablo, tienen 3 canicas cada uno\nTodos ponen de 0 a 3 canicas en un saco.\nGanas si adivinas cuantas canicas hay en total dentro del saco";
        lifes = 1;

    }


void Chinos::play(){

    int userC;
    int userT;
    srand(time(0));

    std::cout   << "\n\n\t" << tituloGame << "\n\n"
                << instruciones << "\n"
                << std::endl;

    std::cout   << "Ahora, dime: Cuantas canicas pusiste?: ";
    userC = getInt();
    validacion( userC, 3); // valida la respuesta de user mov, el 3 es el max


    std::cout   << "\nSabes, Cuantas canicas crees que hay?: ";
    userT = getInt();
    validacion( userT, 9); // valida la respuesta de user mov, el 9 es el max

// con vertir respuestas a int
    person1 = getNum();
    person2 = getNum();
    sum = person1 + person2 + userC;

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

