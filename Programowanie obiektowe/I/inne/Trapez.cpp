/*
Proszê nie u¿ywaæ makr, zmiennych globalnych ani klasy "string" z biblioteki standardowej.
Rozwi¹zanie ka¿dego zadania powinno byæ na osobnej kartce.

Proszê napisaæ program, w którym jest klasa o nazwie "trapez" - jej obiekty reprezentuj¹
trapezy na p³aszczyŸnie. Klasa ta ma pole prywatne "podstawa", przechowuje ono d³ugoœæ
podstawy trapezu (liczba zmiennopozycyjna podwójnej precyzji). Proszê wyprowadziæ z niej,
w sposób publiczny, klasê "trapezRownRam", która ma swoje w³asne pola: "ramiê" i "k¹t"
(liczby zmiennopozycyjne podwójnej precyzji) takiego wektora. Ponadto, odpowiednia metoda
klasy pochodnej zwraca pole powierzchni trapezu równoramiennego: S=(a-b*cos(n))*b*cos(n),
gdzie "a" - d³ugoœæ podstawy, "b" - d³ugoœæ ramienia trapezu, "n" - k¹t pomiêdzy ramieniem
a podstaw¹ trapezu, w³¹czanie biblioteki "cmath" mo¿na pomin¹æ. Program powinien dla trapezu
równoramiennego wyœwietliæ jego pole powierzchni z odpowienim komentarzem. Inicjalizacja
obiektów tej klasy nastêpuje z klawiatury, na ¿¹danie programu. Ka¿da z klas ma swój w³asny
konstruktor.
Proszê utworzyæ w funkcji "main()", po jednym obiekcie: dla klasy bazowej i pochodnej.
Odpowiednia metoda o nazwie "wypisz()" powinna byæ wywo³ana polimorficznie, wypisuj¹c na
ekran ca³¹ zawartoœæ obiektu pierwszego, a potem zawartoœæ drugiego, z odpowiednim komentarzem.
*/
#include<iostream>
#include<cmath>
using namespace std;

class Trapez{
	private:
		double podstawa;
	public:
		//Trapez(double p):podstawa(p){};
		//lub
		Trapez(double p) {podstawa=p;}
		
		/*Trapez()
		{
			cout<<"Podaj podstawe ";
			cin>>podstawa;
		}*/
		//lub
		/*void podaj(){
		cout<<"Podaj podstawe ";
			cin>>podstawa;}*/
		
		double Podstawa(){return podstawa;}
		
		virtual void wypisz()
		{
			cout<<"Podstawa: "<<podstawa<<endl;
		}
};

class TrapezRownRam : public Trapez{
	private:
		double ramie, kat;
	public:
		TrapezRownRam(double p, double r, double k) : Trapez(p){
			ramie=r;
			kat=k;
		}
		/*TrapezRownRam()
		{
			cout<<"Podaj ramie i kat ";
			cin>>ramie>>kat;
		}*/
		/*lub
		/void podaj(){
		cout<<"Podaj ramie i kat ";
			cin>>ramie>>kat;}*/
		double Pole()
		{
			double s=(Podstawa()-ramie*cos(kat))*ramie*cos(kat);//metoda Podstawa() ma dostep do zmiennej prywatnej "double podstawa"
			cout<<"Pole trapezu rownoramiennego: "<<s<<endl<<endl;
			return s;
		}
		void wypisz()
		{
			Trapez::wypisz();
			cout<<"Ramie: "<<ramie<<endl;
			cout<<"Kat: "<<kat<<endl;
		}
};

int main(){
	Trapez t1 (2);
//	Trapez t1;//bez podanych wartosci przy obiektach
	//lub
//	t1.podaj();//bez podanych wartosci przy obiektach
	TrapezRownRam t2 (3,4,5);
//	TrapezRownRam t2;
	//lub
//	t2.podaj();
	
	t2.Pole();
	
	Trapez * wsk;
	wsk=&t1;
	cout<<"Trapez"<<endl;
	wsk->wypisz();
	cout<<endl;
	
	wsk=&t2;
	cout<<"Trapez rownoramienny"<<endl;
	wsk->wypisz();
	
	return 0;
}
