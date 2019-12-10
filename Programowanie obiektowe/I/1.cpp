/*1. Zdefiniowaæ klasê PROSTOPADLOSCIAN reprezentuj¹c¹ bry³ê prostopad³oœcianu.
Klasa powinna zawieraæ odpowiednie sk³adowe (opisuj¹ce bry³y) i nastêpuj¹cy interfejs:
a) konstruktor
b) metodê zwracaj¹c¹ objêtoœæ prostopad³oœcianu
c) metodê pozwalaj¹c¹ przeskalowywaæ prostopad³oœcian (tzn. zwiêkszaæ ich wymiary proporcjonalnie)

2. Napisaæ program, który tworzy dwa prostopad³oœciany o zadanych rozmiarach przez u¿ytkownika.
Nastêpnie program powiêksza prostopad³oœcian o mniejszej objêtoœci w skali 3:1.*/

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
	int p1v, p2v; // objêtoœæ prostopad³oœcianu
	p1v=p1.objetosc(); //3*2*1=6
	p2v=p2.objetosc(); //4*3*2=24
	
	// skalowanie
	if(p1v > p2v)
		p2.skaluj(3);
	else if(p1v < p2v)
		p1.skaluj(3);
	return 0;
}
