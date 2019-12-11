/*Prosz� napisa� program, w kt�rym jest alokowana dynamicznie pami��
dla tablicy 20-elementowej przechowuj�cej tytu� filmu (b�d�cy napisem
w stylu j�zyka C), a b�d�cej polem klasy "ksi��ka". Ponadto w tej klasie
jest pole przechowuj�ce ilo�� obiekt�w tej klasy (ilo�� ksi��ek). W funkcji
"main()" jest tworzony obiekt tej klasy o nazwie "pierwsza", odpowiednio
inicjalizowany (niekoniecznie z klawiatury). Dla tego obiektu program
powinien wypisa� zawarto�� obiektu z odpowiednim komentarzem. Prosz�
utworzy� kolejny obiekt tej klasy o nazwie "druga", a nast�pnie
zainicjalizowa� go przy pomocy pierwszego obiektu tej klasy instrukcj�
"ksiazka pierwsza = druga" (chyba ksiazka druga = pierwsza).
Prosz� wypisa� na ekran zawarto�� obiektu "druga".
Pytanie: prosz� wymieni� cztery operatory (dwa arytmetyczne i dwa
niearytmetyczne), kt�re mo�na przeci��a� w j�zyku C++.
*/

#include <iostream>
#include <cstring>
#include <cassert>
class ksiazka{
	char *tytul;
	//int rok;
	static int ilosc;
	public:
		ksiazka();
		ksiazka(/*int,*/ const char *tablica);
		~ksiazka();
		ksiazka(const ksiazka &);
	//	void operator=(const film&);
		void wypisz();
};
int ksiazka::ilosc = 0;

ksiazka::ksiazka(){
	tytul = new char [strlen("domyslny")+1];
	assert(tytul);
	strcpy(tytul,"domyslny");
		ilosc++;
		std::cout<<"Konstruktor bezargumentowy\t";
		wypisz();
}
ksiazka::ksiazka(/*int a,*/ const char *tablica){
//	rok = a;
	tytul = new char [strlen(tablica)+1];
	assert(tytul);
	strcpy(tytul,tablica);
		ilosc++;
		std::cout<<"Konstruktor\t"<<std::endl;
		wypisz();
}

ksiazka::ksiazka(const ksiazka & obj){
		ilosc++;
	tytul = new char [strlen(obj.tytul)+1];
	assert(tytul);
	strcpy(tytul, obj.tytul);
	//rok = obj.rok;
	std::cout<<"Konstruktor kopiujacy\t"<<std::endl;
	wypisz();
}

ksiazka::~ksiazka(){
	ilosc--;
	std::cout<<"Destruktor\t"<<std::endl;
	wypisz();
delete [] tytul;
}
/*
void film::operator=(const film &obj){
	delete [] zawartosc;
	rok = obj.rok;
	ilosc=obj.ilosc;
	zawartosc = new char [strlen(obj.zawartosc)+1];
	strcpy(zawartosc, obj.zawartosc);
}*/
void ksiazka::wypisz(){
	std::cout<<"Nazwa: "<<tytul<<"\n"<<std::endl;
	//std::cout<<"Rok: "<<rok<<"\n"<<std::endl;
	std::cout<<"Ilosc obiektow:"<<ilosc<<"\n"<<std::endl;
}
int main(){
	char tablica[20] = "Avatar";
	ksiazka pierwsza(/*1999,*/ tablica);
	ksiazka druga = pierwsza;
	
	//film1.wypisz();
	std::cout<<"\n\n"<<std::endl;
	//film2.wypisz();
	
return 0;
}

