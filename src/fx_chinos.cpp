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
        std::cout << "\n" << instruciones << "\n" << std::endl;
    std::cout   << "\n\tAhora, dime:\n\tCuantas canicas pusiste?: ";
    userC = getInt();
    userC = validacion( userC, 3); // valida la respuesta de user mov, el 3 es el max

    system("cls");
            titulo("MATA TIEMPOS");
    std::cout   << "\n\tCuantas canicas crees que hay en total?: ";
    userT = getInt();
    userT = validacion( userT, 9); // valida la respuesta de user mov, el 9 es el max

// con vertir respuestas a int
    person1 = getNum();
    person2 = getNum();
  //  sum = ;

    std::cout   << "\n\tTu pusiste\t" << userC
                << "\n\tPablo puso\t" << person1
                << "\n\ty Paco puso\t" << person2
                << "\n\n\tEn el saco hay: "
                << (person1 + person2 + userC)
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
        std::cout   << "\n\tMás suerte para la proxima";
        youLose();
    }
 }

