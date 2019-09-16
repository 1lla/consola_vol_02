#include <cstdlib>                   //for srand() rand()
#include <ctime>
#include "juego.h"
#include "menu.h"

Chinos::Chinos()
    : Padre("Juego de los Chinos"){
        instruciones = "Tu y dos amigos: Paco y Pablo, tienen 3 canicas cada uno\nTodos ponen de 0 a 3 canicas en un saco.\nGanas si adivinas cuantas canicas hay en total dentro del saco";
        lifes = 1;
    }


void Chinos::play(){

    int userC;
    int userT;

    srand(time(0));
    subtitulo(tituloGame);

    std::cout << "\n" << instruciones << std::endl;
    std::cout   << "\n\tAhora, dime:\n\tCuantas canicas pusiste?: ";
    userC = validacion(get_inte(), 3); // valida la respuesta de user mov, el 3 es el max

    system("cls");
            titulo("MATA TIEMPOS");
    std::cout   << "\n\tCuantas canicas crees que hay en total?: ";
    userT = validacion(get_inte(),9); // valida la respuesta de user mov, el 9 es el max

// con vertir respuestas a int
    person1 = getNum();
    person2 = getNum();
    int sum = person1 + person2 + userC;


    std::cout   << "\n\tTu pusiste\t"       << userC
                << "\n\tPablo puso\t"       << person1
                << "\n\ty Paco puso\t"      << person2
                << "\n\n\tEn el saco hay: " << sum
                << std::endl;

    compara(userT, sum);

}

void Chinos::youWin(){
    pGanad++;
    youwinText();
        }

void Chinos::youLose(){
    pPerdi++;
    gameoverText();
}

// nejorar
int Chinos::getNum(){
        int noRand = rand()%3;
        return noRand;
}

 void Chinos::compara(int us, int su){
    if ( us == su ){
        youWin();
    }else{

        std::cout   << "\n\tMas suerte para la proxima";
        youLose();
    }
 }

