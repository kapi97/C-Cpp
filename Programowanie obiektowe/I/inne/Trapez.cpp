/*
Prosz� nie u�ywa� makr, zmiennych globalnych ani klasy "string" z biblioteki standardowej.
Rozwi�zanie ka�dego zadania powinno by� na osobnej kartce.

Prosz� napisa� program, w kt�rym jest klasa o nazwie "trapez" - jej obiekty reprezentuj�
trapezy na p�aszczy�nie. Klasa ta ma pole prywatne "podstawa", przechowuje ono d�ugo��
podstawy trapezu (liczba zmiennopozycyjna podw�jnej precyzji). Prosz� wyprowadzi� z niej,
w spos�b publiczny, klas� "trapezRownRam", kt�ra ma swoje w�asne pola: "rami�" i "k�t"
(liczby zmiennopozycyjne podw�jnej precyzji) takiego wektora. Ponadto, odpowiednia metoda
klasy pochodnej zwraca pole powierzchni trapezu r�wnoramiennego: S=(a-b*cos(n))*b*cos(n),
gdzie "a" - d�ugo�� podstawy, "b" - d�ugo�� ramienia trapezu, "n" - k�t pomi�dzy ramieniem
a podstaw� trapezu, w��czanie biblioteki "cmath" mo�na pomin��. Program powinien dla trapezu
r�wnoramiennego wy�wietli� jego pole powierzchni z odpowienim komentarzem. Inicjalizacja
obiekt�w tej klasy nast�puje z klawiatury, na ��danie programu. Ka�da z klas ma sw�j w�asny
konstruktor.
Prosz� utworzy� w funkcji "main()", po jednym obiekcie: dla klasy bazowej i pochodnej.
Odpowiednia metoda o nazwie "wypisz()" powinna by� wywo�ana polimorficznie, wypisuj�c na
ekran ca�� zawarto�� obiektu pierwszego, a potem zawarto�� drugiego, z odpowiednim komentarzem.
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
