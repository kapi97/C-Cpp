/*Proszê napisaæ program, w którym jest alokowana dynamicznie pamiêæ
dla tablicy 20-elementowej przechowuj¹cej tytu³ filmu (bêd¹cy napisem
w stylu jêzyka C), a bêd¹cej polem klasy "ksi¹¿ka". Ponadto w tej klasie
jest pole przechowuj¹ce iloœæ obiektów tej klasy (iloœæ ksi¹¿ek). W funkcji
"main()" jest tworzony obiekt tej klasy o nazwie "pierwsza", odpowiednio
inicjalizowany (niekoniecznie z klawiatury). Dla tego obiektu program
powinien wypisaæ zawartoœæ obiektu z odpowiednim komentarzem. Proszê
utworzyæ kolejny obiekt tej klasy o nazwie "druga", a nastêpnie
zainicjalizowaæ go przy pomocy pierwszego obiektu tej klasy instrukcj¹
"ksiazka pierwsza = druga" (chyba ksiazka druga = pierwsza).
Proszê wypisaæ na ekran zawartoœæ obiektu "druga".
Pytanie: proszê wymieniæ cztery operatory (dwa arytmetyczne i dwa
niearytmetyczne), które mo¿na przeci¹¿aæ w jêzyku C++.
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

