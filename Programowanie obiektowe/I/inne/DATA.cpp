/*
Prosz� napisa� program, w kt�rym jest klasa "Data", maj�ca trzy pola prywatne, z kt�rych ka�de przechowuje
liczb� ca�kowit�. Pola te zawieraj� informacj�, odpowiednio o: dniu, miesi�cu i roku. Prosz� przeci��y�
operatory ">>" oraz "<<" tak, �eby mo�na by�o:
a. inicjalizowa� (na ��danie programu) obiekty tej klasy, dan� dat�, podaj�c z klawiatury odpowiednio:
dzie�, miesi�c, rok.
b. wypisa� na ekran zawarto�� danego obiektu, w formacie: rok, miesi�c, dzie�.
Prosz� utworzy� w funkcji "main()", jeden obiekt tej klasy, kt�ry powinien by� zainicjalizowany dzi�ki
odpowiedniemu u�yciu przeci��onego operatora ">>". Nast�pnie, dzi�ki odpowiedniemu u�yciu przeci��onego
operatora "<<", prosz� wypisa� zawarto�� tego obiektu na ekran, z komentarzem:
"Podano dat�: dzie�, miesi�c, rok".
Pytanie: prosz� opisa� s�ownie, iloma sposobami mo�na przeci��y� ww. operatory i dlaczego?
*/

#include<iostream>

using namespace std;

class data{
private:
	private:
		int dzien, miesiac, rok ;
public :
/*	data( int , int , int ) ;
	data(int,int) ;// przeci��anie
	data(int) ;// konstruktora
	data( const char * ) ;*/
	
//	friend std::istream & operator >>(std::istream &, data&);
//	friend std::ostream & operator <<(std::ostream &, data&);
	
	data()
	{
		dzien=0;miesiac=0;rok=0;
	}
	data(int d, int m, int r) //:w(ww);
	{
		dzien=d; miesiac=m; rok=r;
	}
/*	
	int dzien(){
		return dzien;
	}
	int miesiac(){
		return miesiac;
	}
	int rok(){
		return rok;
	}
	*/
void wypisz()
	{
		cout<<"Data: "<<rok<<" "<<miesiac<<" "<<dzien<<endl;
	}

	
	friend istream & operator >> (istream & wejscie, data & obj)
	{
		wejscie>>obj.dzien>>obj.miesiac>>obj.rok;
		return wejscie;
	}
	
	friend ostream & operator << (ostream & wyjscie, data & obj)
	{
		wyjscie<<"Podano date: "<<obj.dzien<<" "<<obj.miesiac<<" "<<obj.rok<<endl;
		return wyjscie;
	}
	
	
};
/*
data::data( int dd, int mm , int mm )
{
dzien = dd ;
miesiac = mm ;
rok = rr ;
}*/


int main(/*int argc, char *argv[]*/)
{

	data d1;
	cin>>d1;
	cout<<d1;
	cout<<endl<<endl;
	d1.wypisz();
	
	data d2(1,2,2000);
	cout<<d2;
	
	return 0;
}
