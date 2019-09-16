#ifndef _menu_     //  header datei
#define _menu_


#include <string>

void get_menu();
void inicia_menu_principal();
void titulo(std::string texto);
void subtitulo(std::string name);
void linea(int l);
void lineaVacia(int l);

int callGame(char s);
int get_inte();
int validacion( int entra, int maximo);
void showEsta();
void makePausa();
float int_to_x100(int n, int NtX100);
void backText();
void goodbyetext();



#endif
