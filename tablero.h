#ifndef TABLERO_H
#define TABLERO_H
void iniciarJuego();
void generarTableroPC(const FichasDePartida & fichas);
void cargarTableroJugador();


bool sePuedeArriba(const int fil);
bool sePuedeDerecha(const int col);
bool sePuedeAbajo(const int fil);
bool sePuedeIzquierda(const int col);
#endif
