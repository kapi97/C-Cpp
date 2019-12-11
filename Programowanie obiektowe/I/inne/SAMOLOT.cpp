/*
Prosz� napisa� program, w kt�rym jest klasa o nazwie "samolot". Ma ono jedno pole prywatne ca�kowite,
przechowuj�ce zasi�g. Prosz� wyprowadzi� z tej klasy w spos�b publiczny, klas� "samolot_transport", maj�c�
swoje pole prywatne, przechowuj�ce mas� �adunku. Konstruktory obu klas powinny odpowiednio inicjalizowa�
obiekty warto�ciami podanymi z klawiatury na ��danie programu. Prosz� polimorficznie wywo�a� metod� wypisuj�c�
na ekran zawarto�ci obiekt�w obu klas, z odpowiednim komentarzem.
Pytanie: prosz� opisa� s�ownie (bez pisania odpowiednich fragment�w kodu), kiedy jest absolutnie nieodzowne i
dlaczego, zdefiniowanie konstruktora kopiuj�cego?
*/

#include <iostream>
#include <string>

using namespace std;
 
class Samolot{//protected:
		int zasieg;
	public:
//		Samolot(){zasieg=1;}
		Samolot(int z):zasieg(z){}
		virtual void wypisz(){
			cout<<"Zasieg: "<<zasieg<<endl<<endl;
		}
		int Zasieg(){return zasieg;}//metoda ma dost�p do zmiennej prywatnej
/*		friend istream & operator >>(istream & wejscie, Samolot& obj){
			cout<<"Podaj zasieg: ";
			return wejscie>>obj.zasieg;
		}*/
};

class Samolot_transport : public Samolot{
		int masa;
	public:
//		Samolot_transport(){masa=1;}
		Samolot_transport(int zasieg, int m):Samolot(zasieg){
			masa = m;		
		}
		void wypisz(){
		//	cout<<"Samochod transp zasieg: "<<Zasieg()<<endl;//w przypadku private metoda odwo�uje si� do zmiennej prywatnej
			Samolot::wypisz();//domyslnie
			cout<<"Masa transport: "<<masa<<endl;
				//cout<<"Zasieg transport: "<<Zasieg()<<endl;//private
			//	cout<<"Zasieg transport: "<<zasieg<<endl;//protected
		}
/*		friend istream & operator >>(istream & wejscie, Samolot_transport& obj){
			cout<<"Podaj mase samolotu transp: ";
			return wejscie>>obj.masa;
		}*/
};
/*
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
};*/

int main(){
/*	PIES piesel("Zwariowany nerd", 68, "Szarik");
	piesel.ZWIERZE::opisz();
	
	SSAK mysz("Gryzie", 20);	*/
	int a, b, c;
	cout<<"Samolot: ";
	cin>>a;
	cout<<"Samolot transport: ";
	cin>>b>>c;
	Samolot s1(a);
/*	Samolot s1;
	cin>>s1;
	Samolot_transport s2;
	cin>>s2;*/
	Samolot_transport s2(b, c);

	Samolot * wsk;

	wsk = &s1;
	wsk->wypisz();

	wsk = &s2;	
	wsk->wypisz();	
	
	return 0;
}	

