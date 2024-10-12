#include <windows.h>
#include <iostream>
using namespace std;



void gotoxy(short x,short y) {
	
	COORD cp = {x,y};
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
	
}



void transiciones(){
	system("cls");
	short X=57,Y=20;
	
	for(int i = 0; i < 15; i++){
		Sleep(300);
		gotoxy(66,22);
		if(i % 3 == 0)
			cout << "cargando.  ";
		else if(i%3 == 1)
			cout << "cargando.. ";
		else if(i%3 == 2)
			cout << "cargando...";
		
		gotoxy(X,Y);
		cout << "||";
		X+=2;
	}
}
