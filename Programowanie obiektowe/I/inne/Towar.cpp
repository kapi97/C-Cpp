/*
Prosz� nie u�ywa� makr, zmiennych globalnych ani klasy "string" z biblioteki
standardowej. Rozwi�zanie ka�dego zadania powinno by� na osobnej kartce.

Prosz� napisa� program, w kt�rym jest alokowana dynamicznie pamie�
dla tablicy znakowej, przechowuj�cej �a�cuch (nazw� towaru), a b�d�cej
w cz�ci prywatnej klasy "towar". Ponadto, w tej klasie jest pole
prywatne przechowuj�ce ilo�� obiekt�w tej klasy (czyli ilo�� towar�w).
W funkcji "main()" jest tworzony obiekt tej klasy o nazwie "pierwszy",
inicjalizowany domy�lnie �a�cuchem "jakis towar". Poza tym, prosz�
utworzy� inny obiekt tej klasy, o nazwie "drugi", inicjalizowany
�a�cuchem "towar nr 2". Prosz� utworzy� kolejny obiekt tej klasy,
o nazwie "trzeci", a w tej samej linijce, prosz� go zainicjalizowa�
przy pomocy drugiego obiektu tej klasy, instrukcj�, kt�rej fragment
ma posta�: trzeci = pierwszy. Prosz� wypisa� na ekran, przy pomocy
odpowiedniej metody klasy (np. "drukuj()"), zawarto�ci obu obiekt�w,
z odpowiednim komentarzem.
*/

#include <iostream>
#include <cstring>
#include <cassert>
class towar{
	char *nazwa;
	//int rok;
	static int ilosc;
	public:
		towar();
		towar(/*int,*/ const char *tablica);
		~towar();
		towar(const towar &);
	//	void operator=(const towar&);
		void drukuj();
};
int towar::ilosc = 0;

towar::towar(){
	nazwa = new char [strlen("domyslny")+1];
	assert(nazwa);
	strcpy(nazwa,"jakis towar");//lub "domyslny"
		ilosc++;
		std::cout<<"Konstruktor bezargumentowy\t";
		drukuj();
}
towar::towar(/*int a,*/ const char *tablica){
	//rok = a;
	nazwa = new char [strlen(tablica)+1];
	assert(nazwa);
	strcpy(nazwa,tablica);
		ilosc++;
		std::cout<<"Konstruktor\t"<<std::endl;
		drukuj();
}

towar::towar(const towar & obj){
		ilosc++;
	nazwa = new char [strlen(obj.nazwa)+1];
	assert(nazwa);
	strcpy(nazwa, obj.nazwa);
	//rok = obj.rok;
	std::cout<<"Konstruktor kopiujacy\t"<<std::endl;
	drukuj();
}

/*
void towar::operator=(const towar &obj){
	delete [] nazwa;
	//rok = obj.rok;
	ilosc=obj.ilosc;
	nazwa = new char [strlen(obj.nazwa)+1];
	strcpy(nazwa, obj.nazwa);
}*/

towar::~towar(){
	ilosc--;
	std::cout<<"Destruktor\t"<<std::endl;
	drukuj();
delete [] nazwa;
}

void towar::drukuj(){
	std::cout<<"Nazwa: "<<nazwa<<"\n"<<std::endl;
	//std::cout<<"Rok: "<<rok<<"\n"<<std::endl;
	std::cout<<"Ilosc obiektow:"<<ilosc<<"\n"<<std::endl;
}
int main(){
	//char tablica1[] = "jakis towar";
	//towar pierwszy(tablica1);
	
	towar pierwszy;
	
	char tablica2[] = "towar nr 2";
	towar drugi(tablica2);
	
	towar trzeci = pierwszy;
	
	//towar.wypisz();
	std::cout<<"\n\n"<<std::endl;
	//towar.wypisz();
	
return 0;
}

