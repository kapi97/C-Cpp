/*
Prosze napisac program, w ktorym jest klasa "samochod".
Prosze wyprowadzic (tutaj: dziedziczenie publiczne), z tej
klasy, klase "samochod_dostawczy". Klasa "samochod" ma
10-elementowa tablice znakowa, alokowana niedynamicznie,
przechowujaca marke samochodu (zwykly ciag znakow).

przynajmniej dwie metody: konstruktor i "void wypisz()",
konstruktor pobiera tablic� znakow� oraz inicjalizuje jej
zawarto�ci� (niekoniecznie napis w stylu j�zyka C) tablic�
b�d�c� sk�adow� tej klasy: metoda "void wypisz()", wypisuje
na ekran zawarto�� obiektu tej klasy.

Klasa "samochod_dostawczy" ma swoja wlasna specyficzna
skladowa o nazwie "masa_towaru" (typ "int").
W funkcji "main( )" prosze utworzyc po jednym z kazdej
z tych klas i zainicjalizowac kazdy z nich z klawiatury, na
zadanie programu ORAZ prosze wywolac polimorficznie,
metoda wypisujaca cale zawartosci obu obiektow,
z odpowiednim komentarzem.

Pytanie: prosz� s�ownie napisa�, kiedy klasa "samochod"
by�aby klas� abstrakcyjn� i jakie by�yby tego konsekwencje,
przy kompilowaniu kodu �r�d�owego programu (oraz dlaczego),
kt�ry Pa�stwu w�a�nie napisali zgodnie z tre�ci� tego zadania.
*/

#include <iostream>
#include <cstring>

class samochod{
	protected:
		char marka[10];
	public:
		samochod();
	friend std::istream & operator >>(std::istream &, samochod&);
	virtual void wypisz();
};

class samochod_dostawczy : public samochod {
	int masa_towaru;
	public:
	samochod_dostawczy();
	friend std::istream & operator >> (std::istream &, samochod_dostawczy &);
	void wypisz();
};

samochod::samochod(){
	std::strcpy(marka, "Nieznana");
} 

void samochod::wypisz(){
	std::cout<<"Marka samochodu: "<<marka<<std::endl;
}

std::istream & operator >> (std::istream & input, samochod & obj){
	std::cout<<"Wpisz marke: "<<std::endl;
	input>>obj.marka;
	return input;
}

samochod_dostawczy::samochod_dostawczy() : samochod(){
	masa_towaru = 200;
}

void samochod_dostawczy::wypisz(){
	std::cout<<"Samochod dostawczy marki: "<<marka<<std::endl;
	std::cout<<"Masa towaru: "<<masa_towaru<<std::endl;
}

std::istream & operator >> (std::istream & input, samochod_dostawczy & obj){
	std::cout<<"Podaj marke samochodu dostawczego: "<<std::endl;
	input>>obj.marka;
	
	std::cout<<"Podaj mase samochodu dostawczego: "<<std::endl;
	input>>obj.masa_towaru;
	return input;
}

int main(){
	samochod obiekt1;
	samochod_dostawczy obiekt2;

	std::cin>>obiekt1;
	std::cin>>obiekt2;

	samochod *wsk = &obiekt1;
	wsk->wypisz();

	wsk = &obiekt2;
	wsk->wypisz();	

	return 0;}

