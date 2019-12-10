/*1. Uzupe�ni� klas� o nast�puj�ce metody:
a) konstruktor inicjalizacyjny
b) metod� zwracaj�c� warto�� sk�adowej
c) operator <<, *

2. Utworzy� dwie klasy jako klasy pochodne po klasie WAR:
a) klasa WAGA zawieraj�ca pole przechowuj�ce jednostk� (np. kg)
b) klasa MIARA zawieraj�ca pole przechowuj�ce jednostk� (np. cm)

Obie klasy powinny mie� zdefiniowany konstruktor oraz metod� wypisz, 
kt�ra b�dzie wypisywa� na ekran przechowywan� warto�� oraz jednostk� (np. 10 cm). 
Metoda powinna by� tak zdefiniowana, aby mog�a by� wywo�ana polimorficznie 
(w tym celu nale�y odpowiednio zmodyfikowa� klas� WAR).

3. Napisa� program, kt�ry pokazuje:
a) dzia�anie operatora << dla klasy WAR
b) pokazuje mechanizm polimorfizmu dla klas WAGA i MIARA*/

#include<iostream>

using namespace std;

class WAR{
private:
	double w;
public:
	WAR()
	{
		w=0;
	}
	WAR(double ww) //:w(ww);
	{
		w=ww;
	}

	/*virtual*/ double zwroc_wartosc() //virtual moze byc chyba tylko jeden
	{
		return w;
	}//dziala bez tej funkcji
	
	virtual void wypisz()
	{
		cout<<w<<endl;
	}

	friend ostream & operator << (ostream & wyjscie, WAR & obj)
	{
		wyjscie<<obj.w<<endl;
		return wyjscie;
	}
	
		friend istream & operator >> (istream & wejscie, WAR & obj)//niepotrzebne do zadania
	{
		wejscie>>obj.w;
		return wejscie;
	}
	
	friend WAR operator * (const WAR & w1, const WAR & w2)//dziala tez bez const
	{
		return WAR(w1.w * w2.w);
	}
	
};

class WAGA : public WAR
{
private:
	string jednostka; 
public:
	WAGA(double ww, string j):WAR(ww)//dziedziczymy skladowa - pole prywatne z klasy WAR
	{
		//w=ww; //dzialaloby, gdyby pole "w" w klasie WAR bylo protected, a nie private
		jednostka=j;
	}
/*	void podaj_jednostka(string jed) //jesli nie podamy jednostki przy wywo�ywaniu konstruktora
	{
		cout<<"Podaj jednostke masy (np. kg): "<<endl;
		cin>>jednostka;
		cout<<jednostka<<endl;
	}*/
	void wypisz()
	{
		WAR::wypisz();
		cout<<jednostka<<endl;
	}
	//void zwroc_wartosc():
};

class MIARA : public WAR
{
private:
	string jednostka; 
public:
	MIARA(double wm, string j):WAR(wm)
	{
		jednostka=j;
	}
/*	void podaj_jednostka(string jed)
	{
		cout<<"Podaj jednostke miary (np. cm): "<<endl;
		cin>>jednostka;
		cout<<jednostka<<endl;
	}*/
	void wypisz()
	{
		WAR::wypisz();
		cout<<jednostka<<endl;
	}
	//void zwroc_wartosc():
};

int main()
{
/*	WAR wartosc(5);
	wartosc.wypisz();*/
	WAGA masa(10, "kg");
	MIARA miara(20, "cm");
	
	WAR wynik = masa * miara;
	cout<<wynik.zwroc_wartosc()<<endl<<endl;
	
/*	//ostream i istream - przeciazanie
	WAR punkt1(50);
	cout<<punkt1<<endl;
	cin>>punkt1;
	cout<<punkt1<<endl;*/	
	WAR * wsk;
	
	wsk=&masa;
	wsk->wypisz();
	
	wsk=&miara;
	wsk->wypisz();
	
	return 0;
}
