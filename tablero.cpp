#include <iostream>
#include <ctime>
#include <cstdlib>

#define FILAS 10
#define COLUMNAS 10

using namespace std;


struct FichasDePartida{
	int cantBotesA;
	int cantBotesB;
	int cantBotesC;
};


bool tableroPC[FILAS][COLUMNAS] = {0};
char tableroPC_pantalla[FILAS][COLUMNAS] = {'?'};



bool sePuedeArriba(const int fil, const int cantMovimientos){
	if(fil - cantMovimientos < 0)
		return false;
	return true;
}

bool sePuedeAbajo(const int fil, const int cantMovimientos){
		if(fil + cantMovimientos < FILAS)
			return true;
		return false;
}

bool sePuedeDerecha(const int col, const int cantMovimientos){
	if(col + cantMovimientos < COLUMNAS)
		return true;
	return false;
}

bool sePuedeIzquierda(const int col, const int cantMovimientos){
	if(col - cantMovimientos < 0)
		return false;
	return true;
}

	
	

//Botes A ocupan 3 casillas, Botes B ocupan 4 casillas, Botes C ocupan 5 casillas
void generarTableroPC(const FichasDePartida & fichas){
	
	srand(time(NULL));
	
	int fil, col, posicion, i = 0;
	bool colocado;
	
	
	//llenamos el tablero con TODOS los botes A , que ocupan 3 casillas
	while(i < fichas.cantBotesA)
	{
		colocado = false;//¿se colocó el bote?
		
		fil = rand() % FILAS; //genero la fila en la que iniciaria la colocacion del bote
		col = rand() % COLUMNAS;//genero la columna en la que iniciaria la colocacion del bote
		posicion = rand() % 4; //genero la posicion en la que se va a colocar el bote (0=up, 1=right, 2=down, 3=left)
		
		switch(posicion){
			case 0: if(sePuedeArriba(fil,2))
										if(tableroPC[fil][col] == 0 and tableroPC[fil-1][col] == 0 and tableroPC[fil-2][col] == 0)//estan los espacios vacios
										{
											tableroPC[fil][col] = 1; tableroPC[fil-1][col] = 1; tableroPC[fil-2][col] = 1;//se colocan los botes
										}
										
								break; //up
								
			case 1: if(sePuedeDerecha(col,2))
									if(tableroPC[fil][col] == 0 and tableroPC[fil][col+1] == 0 and tableroPC[fil][col+2] == 0)//estan los espacios vacios
									{
										tableroPC[fil][col] = 1; tableroPC[fil][col+1] = 1; tableroPC[fil][col+2] = 1;//se colocan los botes
									}
									
							 break; //right
									
									
			case 2: break; //down
			
			
			case 3: break; //left
			
		}//FIN SWITCH
		
		
		tableroPC[fil][col];
		i++;
	}
	
	
	
	
	
}


void cargarTableroJugador();

void iniciarJuego();
