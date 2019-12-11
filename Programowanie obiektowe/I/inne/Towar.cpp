/*
Proszê nie u¿ywaæ makr, zmiennych globalnych ani klasy "string" z biblioteki
standardowej. Rozwi¹zanie ka¿dego zadania powinno byæ na osobnej kartce.

Proszê napisaæ program, w którym jest alokowana dynamicznie pamieæ
dla tablicy znakowej, przechowuj¹cej ³añcuch (nazwê towaru), a bêd¹cej
w czêœci prywatnej klasy "towar". Ponadto, w tej klasie jest pole
prywatne przechowuj¹ce iloœæ obiektów tej klasy (czyli iloœæ towarów).
W funkcji "main()" jest tworzony obiekt tej klasy o nazwie "pierwszy",
inicjalizowany domyœlnie ³añcuchem "jakis towar". Poza tym, proszê
utworzyæ inny obiekt tej klasy, o nazwie "drugi", inicjalizowany
³añcuchem "towar nr 2". Proszê utworzyæ kolejny obiekt tej klasy,
o nazwie "trzeci", a w tej samej linijce, proszê go zainicjalizowaæ
przy pomocy drugiego obiektu tej klasy, instrukcj¹, której fragment
ma postaæ: trzeci = pierwszy. Proszê wypisaæ na ekran, przy pomocy
odpowiedniej metody klasy (np. "drukuj()"), zawartoœci obu obiektów,
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

