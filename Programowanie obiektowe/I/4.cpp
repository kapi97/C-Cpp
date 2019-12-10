/*1. Dana jest nastêpuj¹ca klasa:

class ZWIERZE {
string opis;
public:

ZWIERZE (string n):opis(n) { }

void opisz(){ cout << opis; }

};

a) zdefiniowaæ klasy pochodne SSAK i PIES.
Nale¿y zachowaæ odpowiedni¹ hierarchhiê dziedziczenia.
Klasy pochodne powinny zawieraæ sk³adowe przechowuj¹ce dodatkowe elementy opisu obiektu
b) przedefiniowaæ w klasach funkcjê "opis", aby wypisywa³a wszystkie dane o obiekcie
c) utworzyæ obiekt typu PIES i wywo³aæ dla niego lokaln¹ metodê "opis" i dziedziczon¹ metodê "opis"
d) napisaæ polimorficzny interfejs programu (a wiêc funkcjê main),
któy wywo³uje metodê "opis" dla dowolnego obiektu nale¿acego do tej hierarchii klas.
Mo¿e to byæ zrobione przez zdefiniowanie zewnêtrznej funkcji polimorficznej.*/

#include <iostream>
#include <string>

using namespace std;
 
class ZWIERZE{
		string opis;
	public:
		ZWIERZE(string n):opis(n){}
		virtual void opisz(){
			cout<<opis<<endl<<endl;
		}
};

class SSAK : public ZWIERZE{
		int dniCiazy;
	public:
		SSAK(string opis, int dni):ZWIERZE(opis){
			dniCiazy = dni;		
		}
		virtual void opisz(){
			cout<<"Ciaza trwa "<<dniCiazy<<" dni."<<endl;
			ZWIERZE::opisz();
		}
};

class PIES : public SSAK{
		string imie;
	public:
		PIES(string opis, int dni, string noweImie): SSAK(opis, dni){
			imie = noweImie;
		}
		void opisz(){
			cout<<"Imie "<<imie<<endl;
			SSAK::opisz();
		}
};

int main(){
	PIES piesel("Zwariowany nerd", 68, "Szarik");
	piesel.ZWIERZE::opisz();
	
	SSAK mysz("Gryzie", 20);	

	ZWIERZE * zwierz;

	zwierz = &mysz;
	zwierz->opisz();

	zwierz = &piesel;	
	zwierz->opisz();	
	
	return 0;
}	

