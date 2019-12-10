/*1. Zdefiniowa� klas� WEKTOR reprezentujac� wektor na p�aszczy�nie (ma dwie sk�adowe x, y)
Dla klasy WEKTOR zdefiniowa� nastepuj�cy interfejs:
a) konstruktor z parametrami
b) operator >> pobieraj�cy sk�adowe wektora
c) operator == por�wnuj�cy dwa obiekty typu wektor pod wzgl�dem ich d�ugo�ci
d) metoda wypisuj�ca sk�adowe wektora

2. Napisa� program, w kt�rym u�ytkownik tworzy dwa wektory o sk�adowych (0,0).
Nast�pnie korzystaj�c z operatora >> wprowadza nowe warto�ci sk�adowych tego wektora. 
Nast�pnie program por�wnuje dwa wektory pod wzgl�dem d�ugo�ci i wypisuje na ekranie sk�adowe wektora d�u�szego.*/

#include <iostream>
#include <math.h>

using namespace std;

class Wektor{
	private:
		double x,y;
		double getLength() const;//chyba nawet do public
	public:
		Wektor();
		Wektor(double, double);
		friend istream & operator>>(istream &, Wektor &);
		friend bool operator==(const Wektor &, const Wektor &);
		friend bool operator>(const Wektor &, const Wektor &);
		void wypisz() const;
};

double Wektor::getLength() const{
	return sqrt(pow(x,2) + pow(y,2));
}

Wektor::Wektor(){
	x = 0.0;
	y = 0.0;
}

Wektor::Wektor(double newX, double newY){
	x = newX;
	y = newY;
}

istream & operator>>(istream & input, Wektor & obj){
	cout<<"Podaj X: ";
	input>>obj.x;
	cout<<"Podaj Y: ";
	input>>obj.y;
	return input;
}

bool operator==(const Wektor & first, const Wektor & second){
	return first.getLength() == second.getLength();
}

bool operator>(const Wektor & first, const Wektor & second){
	return first.getLength() > second.getLength();
}

void Wektor::wypisz() const{
	cout<<"Wypisuje X: "<<x<<", Y: "<<y<<endl;
}

void porownajWektory(const Wektor &, const Wektor &);


int main(){
	Wektor one, two;
	cout<<"Podaj wspolrzedne wektora pierwszego."<<endl;
	cin>>one;
	cout<<"Podaj wspolrzedne wektora drugiego."<<endl;
	cin>>two;
	
	porownajWektory(one, two);	
}

void porownajWektory(const Wektor & one, const Wektor & two){
	if (one == two)
		cout<<"Wektory sa rowne."<<endl;
	else if (one > two){
		cout<<"Dluzszy jest wektor pierwszy o parametrach:"<<endl;
		one.wypisz();
	}
	else{
		cout<<"Dluzszy jest wektor drugi o parametrach:"<<endl;
		two.wypisz();
	}
}



