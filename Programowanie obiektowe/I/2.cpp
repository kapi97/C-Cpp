/*1. Zdefiniowaæ klasê WEKTOR reprezentujac¹ wektor na p³aszczyŸnie (ma dwie sk³adowe x, y)
Dla klasy WEKTOR zdefiniowaæ nastepuj¹cy interfejs:
a) konstruktor z parametrami
b) operator >> pobieraj¹cy sk³adowe wektora
c) operator == porównuj¹cy dwa obiekty typu wektor pod wzglêdem ich d³ugoœci
d) metoda wypisuj¹ca sk³adowe wektora

2. Napisaæ program, w którym u¿ytkownik tworzy dwa wektory o sk³adowych (0,0).
Nastêpnie korzystaj¹c z operatora >> wprowadza nowe wartoœci sk³adowych tego wektora. 
Nastêpnie program porównuje dwa wektory pod wzglêdem d³ugoœci i wypisuje na ekranie sk³adowe wektora d³u¿szego.*/

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



