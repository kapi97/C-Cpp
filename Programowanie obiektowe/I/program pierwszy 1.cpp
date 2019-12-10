/*
Proszę napisać program, w którym jest klasa "dane", mająca w
części prywatnej: składową przechowującą ilość obiektów,
i tablicę znakową, alokowaną dynamicznie, oraz inicjalizowaną
napisem (łańcuchem). Odpowiednia metoda klasy powinna
umożliwiać wypisanie na ekran zawartości tej tablicy i liczby
obiektów tej klasy. Proszę utworzyć we funkcji „main( )”, dwa
obiekty tej klasy, pierwszy z nich, powinien być
zainicjalizowany, zawartością lokalnej tablicy we funkcji
„main( )”. Natomiast, do drugiego, po jego utworzeniu (w
następnej linijce – nie w tej, w której został utworzony),
powinien być przypisany pierwszy obiekt. Następnie, proszę
wypisać zawartości obu obiektów na ekran oraz ilość
utworzonych obiektów tej klasy, z odpowiednim komentarzem.
*/

#include <iostream>
#include <cstring>
#include <cassert>

class Dane{
	static int ilosc;
	char * zawartosc;
	public:
	void wypisz();
	Dane();
	Dane(const char * tab);
	Dane(Dane &);	
	~Dane();
	void operator=(const Dane&);
};

int Dane::ilosc = 0;

Dane::Dane(){
	ilosc++;
	zawartosc = new char [strlen("Pusto") + 1];
	assert(zawartosc);
	std::strcpy(zawartosc, "Pusto");
	std::cout<<"Konstruktor dla: "<<zawartosc<<", Ilosc: "<<ilosc<<std::endl;
}

Dane::Dane(const char * tab){
	ilosc++;
	zawartosc = new char [strlen(tab) + 1];
	assert(zawartosc);
	std::strcpy(zawartosc, tab);
	std::cout<<"Konstruktor dla: "<<zawartosc<<", Ilosc: "<<ilosc<<std::endl;
}

Dane::Dane(Dane & obj){
	ilosc++;
	zawartosc = new char [strlen(obj.zawartosc) + 1];
	assert(zawartosc);
	std::strcpy(zawartosc, obj.zawartosc);
	std::cout<<"Konstruktor kopiujacy dla: "<<zawartosc<<", Ilosc: "<<ilosc<<std::endl;
}

Dane::~Dane(){
	ilosc--;
	std::cout<<"Destruktor dla: "<<zawartosc<<", Ilosc: "<<ilosc<<std::endl;
	delete [] zawartosc;
}

void Dane::operator=(const Dane & obj){
	ilosc = obj.ilosc;
	zawartosc = new char [strlen(obj.zawartosc) + 1];
	assert(zawartosc);
	strcpy(zawartosc, obj.zawartosc);
}

void Dane::wypisz(){
	std::cout<<"Ilosc obiektow: "<<ilosc<<std::endl;
	std::cout<<"Zawartosc: "<<zawartosc<<std::endl;
}

int main(){
	char tab [] = "# OBIEKT 1 #";
	Dane dane1(tab);
	dane1.wypisz();

	Dane dane2("# OBIEKT 2 #");
	dane2.wypisz();
	dane2 = dane1;

	dane2.wypisz();
	return 0;
} 
