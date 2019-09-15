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
int getInt();
int validacion( int entra, int maximo);

void backText();
#endif
