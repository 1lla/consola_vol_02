#include <iostream>
#include <string>
#include <time.h>
#include <cstdio>
#include <cstdlib>   //for srand() rand()
#include <vector>




// todas las variantes necesarias

int lifes = 3;
std::string allWords[20]= { "libro","escribir", "especiales", "hombre", "pistola",                      // palabras a adivinar
                            "doctor", "cerebro", "escrito", "resfriado", "helado",                       // no olvidar actualizar
                            "restaurante", "pulmones", "minuto", "audiencia", "egoistas",               // el inicializador al agregar palabras
                            "despertador", "procesador", "donaciones", "entrevista", "presion"
                          };

std::string getWord();                              // incia el anzualo de la palabra
std::string word = getWord();                   // crea la palabra
std::string creaAmorfa(std::string xx);             // inicia creador de amorfa
std::string amorfa = creaAmorfa(word);          // set amorfa

void intro();
int getWortUser();                                  //demás inicializaciones necesarias
bool game();
void titulo();
void youLose();
void youWin();


int main()                                          // main prima, nur 3 func
{
    titulo();
    bool have_i_won = game();
    if (true == have_i_won) {
        youWin();
    } else {
        youLose();
    }

    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void intro()
{

    std::cout << "88  88    db    88b 88  dP""b8 8b    d8    db    88b 88 " << std::endl;
    std::cout << "88  88   dPYb   88Yb88 dP   `\" 88b  d88   dPYb   88Yb88" << std::endl;
    std::cout << "888888  dP__Yb  88 Y88 Yb  \"88 88YbdP88  dP__Yb  88 Y88" << std::endl;
    std::cout << "88  88 dPc\"\"\"\"Yb 88  Y8  YboodP 88 YY 88 dP\"\"\"\"Yb 88  Y8" << std::endl;

}


void titulo()
{
    system("cls");
    std::cout << "\n-------------------------------------------\n           juego de horacados\n-------------------------------------------\n" << std::endl;
}

std::string getWord()
{
    srand(time(0));
    int noRand = rand() % (sizeof(allWords) / sizeof(allWords[1]));  //rando()%5 donde 5 es el valor maximo
    return allWords[noRand];
}

std::string creaAmorfa(std::string xx)
{
    std::string a(xx.length(), '-');
    return a;
}

int getWortUser()
{
    char i;
    std::cout << "Los, Tipp eine Wort ein:" << std::endl;
    std::cin >> i;
    return i;
}

void youLose()
{
    titulo();
    std::cout << "    d888b   .d8b.  .88b  d88. d88888b       .d88b.  db    db d88888b d8888b. " << std::endl;
    std::cout << "   88' Y8b d8' `8b 88'YbdP`88 88'          .8P  Y8. 88    88 88'     88  `8D " << std::endl;
    std::cout << "   88      88ooo88 88  88  88 88ooooo      88    88 Y8    8P 88ooooo 88oobY' " << std::endl;
    std::cout << "   88  ooo 88~~~88 88  88  88 88~~~~~      88    88 `8b  d8' 88~~~~~ 88`8b   " << std::endl;
    std::cout << "   88. ~8~ 88   88 88  88  88 88.          `8b  d8'  `8bd8'  88.     88 `88. " << std::endl;
    std::cout << "    Y888P  YP   YP YP  YP  YP Y88888P       `Y88P'     YP    Y88888P 88   YD " << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "\nPss. La palabra original es : " << word << std::endl;
    std::cout << "\nPero tu solo tenias esto    : " << amorfa << std::endl;

}

void youWin()
{
    std::cout << "Felicidades, ganaste!\n\n" << std::endl;
    std::cout << "Yb  dP  dP\"Yb   88°88     Yb        dP 88 88b 88 " << std::endl;
    std::cout << " YbdP  dP   Yb 88   88      Yb  db  dP  88 88Yb88 " << std::endl;
    std::cout << "  8P   Yb   dP Y8   8P       YbdPYbdP   88 88 Y88 " << std::endl;
    std::cout << " dP     YbodP  `YbodP'        YP  YP    88 88  Y8 " << std::endl;


    exit(-1);                            // se acabo. salir del juego
}



bool game()                              //  inicia el juego
{

    // void intro();
    std::cout << "\nDie Wort hat " << word.length() << " Buchstabe" <<  std::endl;              //crea palabra y amorfa
    std::cout << "\n     " << amorfa << std::endl;
    //    std::cout << "\n\n\nPssss. La palabra es : " << word << std::endl;

    while ( lifes > 0 )                                                                         // Primero, se puede jugar, hay vidas?
    {
        std::cout << "\nDu hast noch " << lifes << " chances" << std::endl;
        char wortU = getWortUser();                                                             // User tipp die erste buchstabe
        int  contador = 0;                                                                      // inicia contador

        for(size_t i = 0; i < word.length(); i++)                                         // por cada letra de la palabra haz:
        {
            char wortNturno = word[i];                                              // wortNturno letra en turno

            if ( wortNturno == wortU )                                              // si en la letra en turno es igual a la latra del usuario
            {
                titulo();
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
            titulo();
            std::cout << "\nnope. Try again\n"<< std::endl;                     // limpia todo, muestra el inicio
            std::cout << "\n     " << amorfa << std::endl;                      // MUESTRA EL ESTADO ACTUAL DE AMORFA
            lifes --;                                                           //quita una vida
        }



    }

    //youLose();                                                                          // si ya no hay vidas, pierdes
    return false;
}

