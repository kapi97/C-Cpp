/*1. Dana jest nast�puj�ca klasa:

class ZWIERZE {
string opis;
public:

ZWIERZE (string n):opis(n) { }

void opisz(){ cout << opis; }

};

a) zdefiniowa� klasy pochodne SSAK i PIES.
Nale�y zachowa� odpowiedni� hierarchhi� dziedziczenia.
Klasy pochodne powinny zawiera� sk�adowe przechowuj�ce dodatkowe elementy opisu obiektu
b) przedefiniowa� w klasach funkcj� "opis", aby wypisywa�a wszystkie dane o obiekcie
c) utworzy� obiekt typu PIES i wywo�a� dla niego lokaln� metod� "opis" i dziedziczon� metod� "opis"
d) napisa� polimorficzny interfejs programu (a wi�c funkcj� main),
kt�y wywo�uje metod� "opis" dla dowolnego obiektu nale�acego do tej hierarchii klas.
Mo�e to by� zrobione przez zdefiniowanie zewn�trznej funkcji polimorficznej.*/

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

