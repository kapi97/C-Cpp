// 3 konstruktory
// bezparametrowy
// trzyparametrowy
// 6 parametrowy 6 double
// settery gettery do punktów
// metoda isTrojkat, isRownoboczny, isRownoramienny, isProstokatny
// obwod i pole powierzchni

// Proszê stworzyæ klasê Trojkat opart¹ na 3 zmiennych typu Punkt (x, y).
// Proszê stworzyæ 3 konstruktory - bezparametrowy, parametrowe z 
// 3 punktami i parametrowy z 6 doublami. Nale¿y równie¿ stworzyæ 
// setery i getery (po punktach) oraz metody isTrojkat(), isRownoboczny(), 
// isRownoramienny(), isProstokatny(). Na koniec nale¿y dodaæ metody pole()
// i obwod() zwracaj¹ce double. Proszê przetestowaæ klasê Trojkat.

#include <iostream>
#include <cmath>
using namespace std;


template <typename T>
struct Punkt
{
	T xx, yy; //wspolrzedne pojedynczego punktu

	/*public: Punkt(double x, double y)
	{
		this->xx = x;
		this->yy = y;
	}*/
};

template <typename T>//T - double, V - void, B - bool
class Trojkat {

	private: 
		Punkt <T>w1, w2, w3; //punkty z wspolrzednymi z "struct Punkt" ((xx i yy)

	public: 
		T a, b, c; //boki trojkata wyliczone z podanych wspolrzednych punktow (z metody "setOdcinki()")

	void setW1(T x, T y) //ustawianie wartosci wspolrzednych (x, y) dla punktow (wierzcholkow) trojkata - konstruktor bezparametrowy
	{
		w1.xx = x;
		w1.yy = y;
	}

	void setW2(T x, T y) 
	{
		w2.xx = x;
		w2.yy = y;
	}

	void setW3(T x, T y)
	{
		w3.xx = x;
		w3.yy = y;
	}

	Punkt <T> getW1() //zwracanie wartosci  //<double>
	{
		return w1;
	}

	Punkt <T> getW2()
	{
		return w2;
	}

	Punkt <T> getW3()
	{
		return w3;
	}

	Trojkat()
	{		
	/*	setW1(1, 1);
		setW2(2, 1);
		setW3(1, 2);*/
		
		//rownoboczny
		setW1(0, 0);
		setW2(2, 0);
		setW3(1, sqrt(3));
		
		setOdcinki();
	}

	Trojkat(Punkt <T> p1, Punkt <T> p2, Punkt <T> p3)
	{
		w1 = p1;
		w2 = p2;
		w3 = p3;
		
		setOdcinki();
	}

	Trojkat(T x1, T y1, T x2, T y2, T x3, T y3)
	{
		w1.xx = x1;
		w1.yy = y1;
		w2.xx = x2;
		w2.yy = y2;
		w3.xx = x3;
		w3.yy = y3;
		
		setOdcinki();
	}

	// metody obliczania dlugosci bokow
	//private:
		T getDlugoscOdcinka(Punkt <T> p1, Punkt <T> p2)
		{
			return sqrt(pow(p1.xx - p2.xx, 2) + pow(p1.yy - p2.yy, 2));
		}

		void setOdcinki() //ustawianie dlugosci bokow
		{
			a = getDlugoscOdcinka(w1, w2);
			b = getDlugoscOdcinka(w2, w3);
			c = getDlugoscOdcinka(w1, w3);
			/*a = sqrt(pow(w1.xx - w2.xx, 2) + pow(w1.yy - w2.yy, 2));
			b = sqrt(pow(w2.xx - w3.xx, 2) + pow(w2.yy - w3.yy, 2));
			c = sqrt(pow(w1.xx - w3.xx, 2) + pow(w1.yy - w3.yy, 2));*/
		}
	//public:
		bool isTrojkat() //zwraca wartosc prawdziwa lub falszywa
		{
			return ((a + b > c) && (a + c > b) && (b + c > a));
			//return (a+b>=c || a+c>=b || b+c>=a);
		}

		bool isRownoboczny()
		{
			return (a == b && a == c && b == c);
			//return (a == b == c);
		}

		bool isRownoramienny()
		{
			return ((a == b) || (b == c) || (a == c));
			//return (a == c && b == c) || (a == c && a == b) || (a == b && b == c);
			//return ((a==b && a+b>c) && (a==c && a+c>b ) && (b==c && b+c>a));
		}

		bool isProstokatny()
		{	
			return  (a * a) + (b * b) == (c*c) ||
					(b * b) + (c * c) == (a*a) || 
					(a * a) + (c * c) == (b*b);
		}
		
		T obwod()
		{
			return (a + b + c);
		}
		
		T pole() //wzor Herona
		{
			T polowa = (0.5)*(a + b + c); //polowa obwodu
			T p = sqrt(polowa * (polowa-(a)) * (polowa-(b)) * (polowa-(c)));
			return p;
		}
};

int main()
{
	Trojkat <double> t1 = Trojkat<double>();
	cout<<"Trojkat I: "<<endl;
	if(t1.isTrojkat())
	{
		cout<<"Taki trojkat istnieje"<<endl;
		if(t1.isRownoboczny()) cout<<"Jest rownoboczny"<<endl; else cout<<"Nie jest rownoboczny"<<endl;
		if(t1.isProstokatny()) cout<<"Jest prostokatny"<<endl; else cout<<"Nie jest prostokatny"<<endl;
		if(t1.isRownoramienny()) cout<<"Jest rownoramienny"<<endl; else cout<<"Nie jest rownoramienny"<<endl;
		if(!t1.isRownoboczny() && !t1.isProstokatny() && !t1.isRownoramienny()) cout<<"Jest roznoboczny"<<endl;
		cout<<"Obwod: "<<t1.obwod()<<endl;
		cout<<"Pole: "<<t1.pole()<<endl;
	}
	else cout<<"Taki trojkat nie istnieje"<<endl;
	cout<<endl;
	
	Punkt <double> p01, p02, p03;
	p01.xx=0; p01.yy=0; p02.xx=5; p02.yy=0; p03.xx=5; p03.yy=5; //wspolrzedne
	//cin>>p01.xx>>p01.yy>>p02.xx>>p02.yy>>p03.xx>>p03.yy;
	Trojkat <double>t2 = Trojkat<double>(p01, p02, p03);
	cout<<"Trojkat II: "<<endl;
	if(t2.isTrojkat())
	{
		cout<<"Taki trojkat istnieje"<<endl; 
		if(t2.isRownoboczny()) cout<<"Jest rownoboczny"<<endl; else cout<<"Nie jest rownoboczny"<<endl;
		if(t2.isProstokatny()) cout<<"Jest prostokatny"<<endl; else cout<<"Nie jest prostokatny"<<endl;
		if(t2.isRownoramienny()) cout<<"Jest rownoramienny"<<endl; else cout<<"Nie jest rownoramienny"<<endl;
		if(!t2.isRownoboczny() && !t2.isProstokatny() && !t2.isRownoramienny()) cout<<"Jest roznoboczny"<<endl;
		cout<<"Obwod: "<<t2.obwod()<<endl;
		cout<<"Pole: "<<t2.pole()<<endl;
	}
	else cout<<"Taki trojkat nie istnieje"<<endl;
	cout<<endl;
	
	Trojkat <double> t3 = Trojkat<double>(0,0,5,0,5,7); //wspolrzedne
	//Trojkat t3; double ax, ay, bx, by, cx, cy; cin>>ax>>ay>>bx>>by>>cx>>cy; t3 = Trojkat(ax, ay, bx, by, cx, cy);
	cout<<"Trojkat III: "<<endl;
	if(t3.isTrojkat())
	{
		cout<<"Taki trojkat istnieje"<<endl;
		if(t3.isRownoboczny()) cout<<"Jest rownoboczny"<<endl; else cout<<"Nie jest rownoboczny"<<endl;
		if(t3.isProstokatny()) cout<<"Jest prostokatny"<<endl; else cout<<"Nie jest prostokatny"<<endl;
		if(t3.isRownoramienny()) cout<<"Jest rownoramienny"<<endl; else cout<<"Nie jest rownoramienny"<<endl;
		if(!t3.isRownoboczny() && !t3.isProstokatny() && !t3.isRownoramienny()) cout<<"Jest roznoboczny"<<endl;
		cout<<"Obwod: "<<t3.obwod()<<endl;
		cout<<"Pole: "<<t3.pole()<<endl;
	}
	else cout<<"Taki trojkat nie istnieje"<<endl;
	cout<<endl;

	return 0;
}

