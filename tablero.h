#ifndef TABLERO_H
#define TABLERO_H

struct FichasDePartida{
	int cantBotesA;
	int cantBotesB;
	int cantBotesC;
};


void hackearTableroJugador();
void hackearTableroPC(); //ver el tableroPC pero con los ENTEROS que representa cada bote
void iniciarJuego();
void generarTableroPC(const FichasDePartida & fichas);
void cargarTableroJugador(const FichasDePartida & fichas);


bool estaDisponible(const int cantMovimientos, const int fil, const int col,const char direccion);
bool estaDisponibleJugador(const int cantMovimientos, const int fil, const int col,const char direccion);
bool sePuedeArriba(const int fil);
bool sePuedeDerecha(const int col);
bool sePuedeAbajo(const int fil);
bool sePuedeIzquierda(const int col);
#endif
