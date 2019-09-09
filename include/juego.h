#ifndef _juego_
#define _juego_


#include <string>
#include <vector>
#include <iostream>

class Padre{
    private:
    protected:
        std::string instruciones;
        std::string tituloGame;
        void gameoverText();
        int lifes;

    public:
        Padre(const std::string& titulo);
        ~Padre();




};


class Hangmann : public Padre{
    private:
        std::string getWort();
        std::string createAmorfa(std::string xx);
        bool game();
        void youLose();
        void youWin();

    protected:
    public:

        std::string word;
        std::string amorfa;
        char getUserW();
        Hangmann();
        void play();
};

class Chinos : public Padre{
    private:
    protected:
        char userC;
        char userT;

        int person1;
        int person2;
        int sum;



    public:
        Chinos();
        void play();
        void compara(char us, int su);


        int getNum();
        void youLose();
        void youWin();

};



#endif
