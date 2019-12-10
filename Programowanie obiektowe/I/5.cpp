/*1. Uzupe³niæ klasê o nastêpuj¹ce metody:
a) konstruktor inicjalizacyjny
b) metodê zwracaj¹c¹ wartoœæ sk³adowej
c) operator <<, *

2. Utworzyæ dwie klasy jako klasy pochodne po klasie WAR:
a) klasa WAGA zawieraj¹ca pole przechowuj¹ce jednostkê (np. kg)
b) klasa MIARA zawieraj¹ca pole przechowuj¹ce jednostkê (np. cm)

Obie klasy powinny mieæ zdefiniowany konstruktor oraz metodê wypisz, 
która bêdzie wypisywaæ na ekran przechowywan¹ wartoœæ oraz jednostkê (np. 10 cm). 
Metoda powinna byæ tak zdefiniowana, aby mog³a byæ wywo³ana polimorficznie 
(w tym celu nale¿y odpowiednio zmodyfikowaæ klasê WAR).

3. Napisaæ program, który pokazuje:
a) dzia³anie operatora << dla klasy WAR
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
/*	void podaj_jednostka(string jed) //jesli nie podamy jednostki przy wywo³ywaniu konstruktora
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
