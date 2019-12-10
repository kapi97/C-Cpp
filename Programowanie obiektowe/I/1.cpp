/*1. Zdefiniowa� klas� PROSTOPADLOSCIAN reprezentuj�c� bry�� prostopad�o�cianu.
Klasa powinna zawiera� odpowiednie sk�adowe (opisuj�ce bry�y) i nast�puj�cy interfejs:
a) konstruktor
b) metod� zwracaj�c� obj�to�� prostopad�o�cianu
c) metod� pozwalaj�c� przeskalowywa� prostopad�o�cian (tzn. zwi�ksza� ich wymiary proporcjonalnie)

2. Napisa� program, kt�ry tworzy dwa prostopad�o�ciany o zadanych rozmiarach przez u�ytkownika.
Nast�pnie program powi�ksza prostopad�o�cian o mniejszej obj�to�ci w skali 3:1.*/

#include<iostream>

class PROSTOPADLOSCIAN{
	int wysokosc, podstawaA, podstawaB;
	public:
		PROSTOPADLOSCIAN (int h, int a, int b){
			wysokosc=h;
			podstawaA=a;
			podstawaB=b;
		}

		int objetosc(){
			return podstawaA * podstawaB * wysokosc;
		}

		void skaluj (int skala){
			wysokosc *= skala;
			podstawaA *= skala;
			podstawaB *= skala;
		}
};

int main(){
	// nowe obiekty
	PROSTOPADLOSCIAN p1(3, 2, 1);
	PROSTOPADLOSCIAN p2(4, 3, 2);
	
	// objetosci
	int p1v, p2v; // obj�to�� prostopad�o�cianu
	p1v=p1.objetosc(); //3*2*1=6
	p2v=p2.objetosc(); //4*3*2=24
	
	// skalowanie
	if(p1v > p2v)
		p2.skaluj(3);
	else if(p1v < p2v)
		p1.skaluj(3);
	return 0;
}
