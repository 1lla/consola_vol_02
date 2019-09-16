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
        int lifes;
        int pPerdi;
        int pGanad;
        int pEmpat;



        void gameoverText();
        void youwinText();
        int get_inte();
        int validacion( int entra, int maximo);


    public:
        Padre(const std::string& titulo);
        ~Padre();

        int get_Pperd();
        int get_Pgana() const;
        int get_pEmpat() const;




};

class Chinchan : public Padre{
    private:
        int getUsermov();
        int getCmov();
        int compara( char u, int c);
        std::string nombra( int v);
        void youLose();
        void youWin();
    public:
        Chinchan();
        void play();
};

class Hangmann : public Padre{
    private:
    public:
        std::string getWort();
        std::string createAmorfa(std::string xx);
        bool game();
        void youLose();
        void youWin();

        std::string word;
        std::string amorfa;
        char getUserW();
        Hangmann();
        void play();
};

class Chinos : public Padre{
    private:
    protected:
        int person1;
        int person2;
        int sum;

    public:
        Chinos();
        void play();
        void compara(int us, int su);
        int getNum();
        void youLose();
        void youWin();

};



#endif
