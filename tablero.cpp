#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "config.h"

#define FILAS 10
#define COLUMNAS 10

using namespace std;


struct FichasDePartida{
	int cantBotesA;
	int cantBotesB;
	int cantBotesC;
};


int tableroPC[FILAS][COLUMNAS] = {0};//0 vacio, 1 bote de 3 casillas, 2 bote de 4 casillas, 3 bote de 5 casillas
char tableroPC_pantalla[FILAS][COLUMNAS] = {'?'};

int tableroJugador[FILAS][COLUMNAS] = {0};//0 vacio, 1 bote de 3 casillas, 2 bote de 4 casillas, 3 bote de 5 casillas
char tableroJugador_pantalla[FILAS][COLUMNAS] = {'?'};



void hackearTableroJugador(){
	short X,Y;
	
	gotoxy(20,1);
	cout << "TABLERO JUGADOR";
		
	Y = 1; X = 63;
	for(int i = 0; i < COLUMNAS; i++){
		gotoxy(X,Y);
		cout << i << " ";
		X+=3;
	}
	
	Y = 3; X = 60;
	for(int i = 0; i < FILAS; i++){
		gotoxy(X,Y);
		cout << (char)(i + 'A') << " ";
		Y+=2;
	}
	
	
	Y = 1;
	for(int fil = 0; fil < FILAS; fil++){
		Y+=2; X = 60;
		
		for(int col = 0; col < COLUMNAS; col++){
			gotoxy(X+=3,Y);
			
			cout << tableroJugador[fil][col] << " ";
			
		}
			cout << endl;
	}
	
}//FIN DE hackearTableroJugador()

	
void hackearTableroPC(){
	
	for(int fil = 0; fil < FILAS; fil++){
		
		for(int col = 0; col < COLUMNAS; col++)
			cout << tableroPC[fil][col] << " ";
		
			cout << endl;
	}

}



bool estaDisponibleJugador(const int cantMovimientos, const int fil, const int col,const char direccion){
	int i = 0;
	
	switch(direccion){
		
	case 'U': while(i < cantMovimientos){
		if(tableroJugador[fil-i][col] != 0)
			return false;
		i++;
	}break;//UP
	
	case 'D': while(i < cantMovimientos){
		if(tableroJugador[fil+i][col] != 0)
			return false;
		i++;
	}break; //DOWN
	
	case 'R': while(i < cantMovimientos){
		if(tableroJugador[fil][col+i] != 0)
			return false;
		i++;
	}break; //RIGHT
	
	case 'L': while(i < cantMovimientos){
		if(tableroJugador[fil][col-i] != 0)
			return false;
		i++;
	}break; //LEFT
	
	}
	
	return true;
}

//'U' UP, 'R' RIGHT, 'D' DOWN, 'L' LEFT
bool estaDisponible(const int cantMovimientos, const int fil, const int col,const char direccion){
	
	int i = 0;
	
	switch(direccion){
		
	case 'U': while(i < cantMovimientos){
										if(tableroPC[fil-i][col] != 0)
											return false;
										i++;
						}break;//UP
	
	case 'D': while(i < cantMovimientos){
								if(tableroPC[fil+i][col] != 0)
									return false;
								i++;
						}break; //DOWN
	
	case 'R': while(i < cantMovimientos){
								if(tableroPC[fil][col+i] != 0)
									return false;
								i++;
						}break; //RIGHT
	
	case 'L': while(i < cantMovimientos){
									if(tableroPC[fil][col-i] != 0)
											return false;
									i++;
						}break; //LEFT
	
	}
	
	return true;
}
	

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
	
	
	
	//llenamos el tablero con TODOS los botes A , que ocupan 3 casillas
	while(i < fichas.cantBotesA)
	{
		
		
		fil = rand() % FILAS; //genero la fila en la que iniciaria la colocacion del bote
		col = rand() % COLUMNAS;//genero la columna en la que iniciaria la colocacion del bote
		posicion = rand() % 4; //genero la posicion en la que se va a colocar el bote (0=up, 1=right, 2=down, 3=left)
		
		switch(posicion){
			case 0: if( sePuedeArriba(fil,2) and estaDisponible(2,fil,col,'U') ) //estan los espacios vacios
										{
											tableroPC[fil][col] = 1; tableroPC[fil-1][col] = 1; tableroPC[fil-2][col] = 1;//se colocan los botes
											i++;
										}
										
								break; //up
								
			
			case 1: if(sePuedeDerecha(col,2) and estaDisponible(2,fil,col,'R'))//estan los espacios vacios
									{
										tableroPC[fil][col] = 1; tableroPC[fil][col+1] = 1; tableroPC[fil][col+2] = 1;//se colocan los botes
										i++;
									}
									
							 break; //right
									
									
			case 2: if(sePuedeAbajo(fil,2) and estaDisponible(2,fil,col,'D'))
								{
										tableroPC[fil][col] = 1; tableroPC[fil+1][col] = 1; tableroPC[fil+2][col] = 1;//se colocan los botes
										i++;
								}
			
								break; //down
			
			
			case 3: if(sePuedeIzquierda(col,2) and estaDisponible(2,fil,col,'L'))
								{
										tableroPC[fil][col] = 1; tableroPC[fil][col-1] = 1; tableroPC[fil][col-2] = 1;//se colocan los botes
										i++;
								}
								
								break; //left
			
			
		}//FIN SWITCH
		
		
		//tableroPC[fil][col];
		
	}//FIN WHILE
	
	
	
	
	i = 0;//llenamos el tablero con TODOS los botes B , que ocupan 4 casillas
	while(i < fichas.cantBotesB)
	{
		
		
		fil = rand() % FILAS; //genero la fila en la que iniciaria la colocacion del bote
		col = rand() % COLUMNAS;//genero la columna en la que iniciaria la colocacion del bote
		posicion = rand() % 4; //genero la posicion en la que se va a colocar el bote (0=up, 1=right, 2=down, 3=left)
		
		switch(posicion){
		case 0: if( sePuedeArriba(fil,3) and estaDisponible(3,fil,col,'U') ) //estan los espacios vacios
		{
			tableroPC[fil][col] = 2; tableroPC[fil-1][col] = 2; tableroPC[fil-2][col] = 2;
			tableroPC[fil-3][col] = 2; //se colocan los botes
			i++;
		}
		
		break; //up
		
		
		case 1: if(sePuedeDerecha(col,3) and estaDisponible(3,fil,col,'R'))//estan los espacios vacios
		{
			tableroPC[fil][col] = 2; tableroPC[fil][col+1] = 2; tableroPC[fil][col+2] = 2;
			tableroPC[fil][col+3] = 2; //se colocan los botes
			i++;
		}
		
		break; //right
		
		
		case 2: if(sePuedeAbajo(fil,3) and estaDisponible(3,fil,col,'D'))
		{
			tableroPC[fil][col] = 2; tableroPC[fil+1][col] = 2; tableroPC[fil+2][col] = 2;
			tableroPC[fil+3][col] = 2; //se colocan los botes
			i++;
		}
		
		break; //down
		
		
		case 3: if(sePuedeIzquierda(col,3) and estaDisponible(3,fil,col,'L'))
		{
			tableroPC[fil][col] = 2; tableroPC[fil][col-1] = 2; tableroPC[fil][col-2] = 2;
			tableroPC[fil][col-3] = 2; //se colocan los botes
			i++;
		}
		
		break; //left
		
		
		}//FIN SWITCH
		
		
		//tableroPC[fil][col];
		
	}//FIN WHILE
	
	
	
	
	
	i = 0;//llenamos el tablero con TODOS los botes C , que ocupan 5 casillas
	while(i < fichas.cantBotesC)
	{
		
		
		fil = rand() % FILAS; //genero la fila en la que iniciaria la colocacion del bote
		col = rand() % COLUMNAS;//genero la columna en la que iniciaria la colocacion del bote
		posicion = rand() % 4; //genero la posicion en la que se va a colocar el bote (0=up, 1=right, 2=down, 3=left)
		
		switch(posicion){
		case 0: if( sePuedeArriba(fil,4) and estaDisponible(4,fil,col,'U') ) //estan los espacios vacios
		{
			tableroPC[fil][col] = 3; tableroPC[fil-1][col] = 3; tableroPC[fil-2][col] = 3;
			tableroPC[fil-3][col] = 3;  tableroPC[fil-4][col] = 3;//se colocan los botes
			i++;
		}
		
		break; //up
		
		
		case 1: if(sePuedeDerecha(col,4) and estaDisponible(4,fil,col,'R'))//estan los espacios vacios
		{
			tableroPC[fil][col] = 3; tableroPC[fil][col+1] = 3; tableroPC[fil][col+2] = 3;
			tableroPC[fil][col+3] = 3; tableroPC[fil][col+4] = 3;//se colocan los botes
			i++;
		}
		
		break; //right
		
		
		case 2: if(sePuedeAbajo(fil,4) and estaDisponible(4,fil,col,'D'))
		{
			tableroPC[fil][col] = 3; tableroPC[fil+1][col] = 3; tableroPC[fil+2][col] = 3;
			tableroPC[fil+3][col] = 3; tableroPC[fil+4][col] = 3; //se colocan los botes
			i++;
		}
		
		break; //down
		
		
		case 3: if(sePuedeIzquierda(col,4) and estaDisponible(4,fil,col,'L'))
		{
			tableroPC[fil][col] = 3; tableroPC[fil][col-1] = 3; tableroPC[fil][col-2] = 3;
			tableroPC[fil][col-3] = 3; tableroPC[fil][col-4] = 3; //se colocan los botes
			i++;
		}
		
		break; //left
		
		
		}//FIN SWITCH
		
		
		//tableroPC[fil][col];
		
	}//FIN WHILE
	
	
	//YA SE COLOCARON LOS 3 tipos de botes
	
	
	
}//FIN generarTableroPC();


void cargarTableroJugador(const FichasDePartida & fichas){
	
	char filachar;
	int col, fil, posicion, i = 0;
	
	
	
	//llenamos el tablero con TODOS los botes A , que ocupan 3 casillas
	while(i < fichas.cantBotesA)
	{
		system("cls");
		hackearTableroJugador();
		
		
		cout << "Introduzca donde poner su barco tipo A, en el formato FILACOLUMNA: ";
		cin >> filachar >> col;
		fil = filachar - 'A';
		
		cout << "Introduzca la posición en la que se introducirá el bote [0=up, 1=right, 2=down, 3=left]: ";
		cin >> posicion; //genero la posicion en la que se va a colocar el bote (0=up, 1=right, 2=down, 3=left)
		
		switch(posicion){
		case 0: if( sePuedeArriba(fil,2) and estaDisponibleJugador(2,fil,col,'U') ) //estan los espacios vacios
		{
			tableroJugador[fil][col] = 1; tableroJugador[fil-1][col] = 1; tableroJugador[fil-2][col] = 1;//se colocan los botes
			i++;
		}
		
		break; //up
		
		
		case 1: if(sePuedeDerecha(col,2) and estaDisponibleJugador(2,fil,col,'R'))//estan los espacios vacios
		{
			tableroJugador[fil][col] = 1; tableroJugador[fil][col+1] = 1; tableroJugador[fil][col+2] = 1;//se colocan los botes
			i++;
		}
		
		break; //right
		
		
		case 2: if(sePuedeAbajo(fil,2) and estaDisponibleJugador(2,fil,col,'D'))
		{
			tableroJugador[fil][col] = 1; tableroJugador[fil+1][col] = 1; tableroJugador[fil+2][col] = 1;//se colocan los botes
			i++;
		}
		
		break; //down
		
		
		case 3: if(sePuedeIzquierda(col,2) and estaDisponibleJugador(2,fil,col,'L'))
		{
			tableroJugador[fil][col] = 1; tableroJugador[fil][col-1] = 1; tableroJugador[fil][col-2] = 1;//se colocan los botes
			i++;
		}
		
		break; //left
		
		default: cout << "Posicion incorrecta, intente nuevamente. [0=up, 1=right, 2=down, 3=left]" << endl; break;
		
		}//FIN SWITCH
		
		
		//tableroPC[fil][col];
		
	}//FIN WHILE
	
	
	
	
	
	i = 0;
	//llenamos el tablero con TODOS los botes B , que ocupan 4 casillas
	while(i < fichas.cantBotesB)
	{
		system("cls");
		hackearTableroJugador();
		
		cout << "Introduzca donde poner su barco tipo B, en el formato FILACOLUMNA: ";
		cin >> filachar >> col;
		fil = filachar - 'A';
		
		cout << "Introduzca la posición en la que se introducirá el bote [0=up, 1=right, 2=down, 3=left]: ";
		cin >> posicion; //genero la posicion en la que se va a colocar el bote (0=up, 1=right, 2=down, 3=left)
		
		switch(posicion){
		case 0: if( sePuedeArriba(fil,3) and estaDisponibleJugador(3,fil,col,'U') ) //estan los espacios vacios
		{
			tableroJugador[fil][col] = 2; tableroJugador[fil-1][col] = 2; tableroJugador[fil-2][col] = 2;//se colocan los botes
			tableroJugador[fil-3][col] = 2;//se colocan los botes
			i++;
		}
		
		break; //up
		
		
		case 1: if(sePuedeDerecha(col,3) and estaDisponibleJugador(3,fil,col,'R'))//estan los espacios vacios
		{
			tableroJugador[fil][col] = 2; tableroJugador[fil][col+1] = 2; tableroJugador[fil][col+2] = 2;//se colocan los botes
			tableroJugador[fil][col+3] = 2;//se colocan los botes
			i++;
		}
		
		break; //right
		
		
		case 2: if(sePuedeAbajo(fil,3) and estaDisponibleJugador(3,fil,col,'D'))
		{
			tableroJugador[fil][col] = 2; tableroJugador[fil+1][col] = 2; tableroJugador[fil+2][col] = 2;//se colocan los botes
			tableroJugador[fil+3][col] = 2;//se colocan los botes
			i++;
		}
		
		break; //down
		
		
		case 3: if(sePuedeIzquierda(col,3) and estaDisponibleJugador(3,fil,col,'L'))
		{
			tableroJugador[fil][col] = 2; tableroJugador[fil][col-1] = 2; tableroJugador[fil][col-2] = 2;//se colocan los botes
			tableroJugador[fil][col-3] = 2;//se colocan los botes
			i++;
		}
		
		break; //left
		
		default: cout << "Posicion incorrecta, intente nuevamente. [0=up, 1=right, 2=down, 3=left]" << endl; break;
		
		}//FIN SWITCH
		
		
		//tableroPC[fil][col];
		
	}//FIN WHILE
	
	
	
	
	i = 0;
	//llenamos el tablero con TODOS los botes C , que ocupan 5 casillas
	while(i < fichas.cantBotesC)
	{
		system("cls");
		hackearTableroJugador();
		
	
		cout << "Introduzca donde poner su barco tipo C, en el formato FILACOLUMNA: ";
		cin >> filachar >> col;
		fil = filachar - 'A';
		
		cout << "Introduzca la posición en la que se introducirá el bote [0=up, 1=right, 2=down, 3=left]: ";
		cin >> posicion; //genero la posicion en la que se va a colocar el bote (0=up, 1=right, 2=down, 3=left)
		
		switch(posicion){
		case 0: if( sePuedeArriba(fil,4) and estaDisponibleJugador(4,fil,col,'U') ) //estan los espacios vacios
		{
			tableroJugador[fil][col] = 3; tableroJugador[fil-1][col] = 3; tableroJugador[fil-2][col] = 3;//se colocan los botes
			tableroJugador[fil-3][col] = 3; tableroJugador[fil-4][col] = 3;//se colocan los botes
			i++;
		}
		
		break; //up
		
		
		case 1: if(sePuedeDerecha(col,4) and estaDisponibleJugador(4,fil,col,'R'))//estan los espacios vacios
		{
			tableroJugador[fil][col] = 3; tableroJugador[fil][col+1] = 3; tableroJugador[fil][col+2] = 3;//se colocan los botes
			tableroJugador[fil][col+3] = 3; tableroJugador[fil][col+4] = 3;//se colocan los botes
			i++;
		}
		
		break; //right
		
		
		case 2: if(sePuedeAbajo(fil,4) and estaDisponibleJugador(4,fil,col,'D'))
		{
			tableroJugador[fil][col] = 3; tableroJugador[fil+1][col] = 3; tableroJugador[fil+2][col] = 3;//se colocan los botes
			tableroJugador[fil+3][col] = 3; tableroJugador[fil+4][col] = 3;//se colocan los botes
			i++;
		}
		
		break; //down
		
		
		case 3: if(sePuedeIzquierda(col,4) and estaDisponibleJugador(4,fil,col,'L'))
		{
			tableroJugador[fil][col] = 3; tableroJugador[fil][col-1] = 3; tableroJugador[fil][col-2] = 3;//se colocan los botes
			tableroJugador[fil][col-3] = 3; tableroJugador[fil][col-4] = 3;//se colocan los botes
			i++;
		}
		
		break; //left
		
		default: cout << "Posicion incorrecta, intente nuevamente. [0=up, 1=right, 2=down, 3=left]" << endl; break;
		
		}//FIN SWITCH
		
		
		//tableroPC[fil][col];
		
	}//FIN WHILE
	
	
	
	//YA ESTAN TODOS LOS BOTES CARGADOS
	
	
}

void iniciarJuego();
