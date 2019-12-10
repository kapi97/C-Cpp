#include<iostream>

using namespace std;

class WARTOSC{
private:
	double w;
public:
	WARTOSC()//konstruktor bezparametrowy, s�u�y do wywo�ania obiektu x
	{
		w=0;
	}
	WARTOSC(double a)//konstruktor parametrowy, s�u�y do wywo�ania obiektu c
	{
		w=a;
	}
	/* WARTOSC (double a) : w(a){} //konstruktor inicjalizacyjny*/
	
	//1 a)
	double zwroc_wartosc()
	{
		return w;
	}
	
	virtual void wypisz()//do polimorfizmu
	{
		cout<<w<<endl;
	}

	/*friend ostream & operator << (ostream & wyjscie, WAR & obj)
	{
		wyjscie<<obj.w<<endl;
		return wyjscie;
	}*/
	
	//1 b)
	//friend ma dost�p do zmiennej prywatnej "double w"
	friend istream & operator >> (istream & wejscie, WARTOSC & obj)
	{
		cout<<"Podaj wartosc: ";
		wejscie>>obj.w;
		return wejscie;
	}
	
	friend WARTOSC operator + (const WARTOSC & w1, const WARTOSC & w2)//dzia�a te� bez const
	{
		return WARTOSC(w1.w + w2.w);
	}
	
	//druga grupa
	friend bool operator < (const WARTOSC & w1, const WARTOSC & w2)//podobnie z "==" (r�wno��)
	{
		//return w1.zwroc_wartosc() < w2.zwroc_wartosc(); //�LE
		return w1.w < w2.w;
	}
};

class WAGA : public WARTOSC
{
private:
	const string jednostka; 
public:
	//3 a)
	WAGA(double w_w, string j):WARTOSC(w_w)/*w_w - dziedziczymy sk�adow� - pole prywatne z klasy WARTOSC*/
	,jednostka(j)
	{
		//w=w_w; //dzia�a�oby, gdyby pole "w" w klasie WARTOSC by�o protected, a nie private
		
		//jednostka=j;//je�eli sk�adowa jest sta�a (const string jednostka) nie mo�emy tak zapisa�, tylko w spos�b powy�ej: jednostka(j)
	}
	//3 b)
	void wypisz()
	{
		WARTOSC::wypisz();
		cout<<jednostka<<endl;
	}
	
	/*void podaj_jednostka(string jed) //je�li nie podamy jednostki przy wywo�ywaniu konstruktora
	{
		cout<<"Podaj jednostke masy (np. kg): "<<endl;
		cin>>jednostka;
		cout<<jednostka<<endl;
	}*/
};

class MIARA : public WARTOSC
{
private:
	const string jednostka; 
public:
	//3 a)
	MIARA(double w_m, string j) : WARTOSC(w_m), jednostka(j)
	{
		//jednostka=j;//podobnie, jak powy�ej
	}
	//3 b)
	void wypisz()
	{
		WARTOSC::wypisz();
		cout<<jednostka<<endl;
	}
	
	/*void podaj_jednostka(string jed)
	{
		cout<<"Podaj jednostke miary (np. cm): "<<endl;
		cin>>jednostka;
		cout<<jednostka<<endl;
	}*/
};

void funkcja_polimorficzna(WARTOSC & w)
{
	w.wypisz();
}

int main()
{
	//2 a)
	/*const*/ WARTOSC c(0.5);//wywo�uje konstruktor parametrowy
	WARTOSC x;//wywo�uje konstruktor bezparametrowy
	//2 b)
	c.wypisz();//nie dzia�a z "const" - nie wiem, jak to si� robi z "const"
	//2 c)
	cin>>x; //wywo�a si� friend istream...
	//2 d)
	WARTOSC suma = c + x;
	cout<<"Suma: "<<suma.zwroc_wartosc()<<endl<<endl;
	
	//druga grupa
	if (c < x)
	cout<<"X jest wieksze: "<<x.zwroc_wartosc()<<endl<<endl;

	WAGA masa(10, "kg");
	MIARA miara(20, "cm");
	
//	WARTOSC wynik = masa * miara;
//	cout<<wynik.zwroc_wartosc()<<endl<<endl;
	
/*	//ostream i istream - przeci��anie operator�w wej�cia i wyj�cia
	WARTOSC punkt1(50);
	cout<<punkt1<<endl;
	cin>>punkt1;
	cout<<punkt1<<endl;*/
	
	//3 c)
	cout<<"POLIMORFIZM - I sposob"<<endl;	
	WARTOSC * wsk;
	
	wsk=&masa;
	wsk->wypisz();
	
	wsk=&miara;
	wsk->wypisz();
	
	cout<<"POLIMORFIZM - II sposob"<<endl;
	funkcja_polimorficzna(masa);
	funkcja_polimorficzna(miara);
	
	return 0;
}
