/*
Proszê napisaæ program, w którym jest klasa "Data", maj¹ca trzy pola prywatne, z których ka¿de przechowuje
liczbê ca³kowit¹. Pola te zawieraj¹ informacjê, odpowiednio o: dniu, miesi¹cu i roku. Proszê przeci¹¿yæ
operatory ">>" oraz "<<" tak, ¿eby mo¿na by³o:
a. inicjalizowaæ (na ¿¹danie programu) obiekty tej klasy, dan¹ dat¹, podaj¹c z klawiatury odpowiednio:
dzieñ, miesi¹c, rok.
b. wypisaæ na ekran zawartoœæ danego obiektu, w formacie: rok, miesi¹c, dzieñ.
Proszê utworzyæ w funkcji "main()", jeden obiekt tej klasy, który powinien byæ zainicjalizowany dziêki
odpowiedniemu u¿yciu przeci¹¿onego operatora ">>". Nastêpnie, dziêki odpowiedniemu u¿yciu przeci¹¿onego
operatora "<<", proszê wypisaæ zawartoœæ tego obiektu na ekran, z komentarzem:
"Podano datê: dzieñ, miesi¹c, rok".
Pytanie: proszê opisaæ s³ownie, iloma sposobami mo¿na przeci¹¿yæ ww. operatory i dlaczego?
*/

#include<iostream>

using namespace std;

class data{
private:
	private:
		int dzien, miesiac, rok ;
public :
/*	data( int , int , int ) ;
	data(int,int) ;// przeci¹¿anie
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
