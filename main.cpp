#include <iostream>
#include <windows.h>
#include "config.h"
#include "tablero.h"

using namespace std;

int main(){
	
	system("mode con: cols=150 lines=60");
	
	FichasDePartida nuevaPartida;
	nuevaPartida.cantBotesA = 1;//4
	nuevaPartida.cantBotesB = 0;//4
	nuevaPartida.cantBotesC = 0;//2
	int botesEnJuego = nuevaPartida.cantBotesA + nuevaPartida.cantBotesB + nuevaPartida.cantBotesC;//10
	
  cargarTableroJugador(nuevaPartida);
	
	generarTableroPC(nuevaPartida);
	hackearTableroPC();
	
	
	gotoxy(70,30);
	cout << "CARGA EXITOSA!" << endl;
	Sleep(3000);
	
	transiciones();
	
	
	
	
	return 0;
}
