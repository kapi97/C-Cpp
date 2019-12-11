#include<iostream>
using namespace std;

class WAGA
{
	private:
		double wartosc;
		//string jednostka;//w tym przypadku dziala bez const
		const string jednostka;
		//const string jednostka="kg";
	public:
		WAGA():wartosc(1), jednostka("kg")
		{
		}
		
		//WAGA(double w):WAGA(jednostka)//jednostka(wartosc+1)
		WAGA(double w, string j):wartosc(w), jednostka(j)
		{	
		konwersja();
		}
void konwersja()
{
	cout<<"Konwersja jednostek:"<<endl;
	if (jednostka=="dkg"){
	wartosc*=0.1;
//	jednostka="kg";//nie dziala z const

//	cout<<wartosc<<" "<<jednostka<<endl;
	  cout<<wartosc<<" kg"<<endl;
	}
	else if (jednostka=="g"){
	wartosc*=0.01;
//	jednostka="kg";//nie dziala z const

//	cout<<wartosc<<" "<<jednostka<<endl;
	  cout<<wartosc<<" kg"<<endl;
	}
	cout<<endl;	
}
		/*void*/double wypisz() const
		{
			//cout<<wartosc<<" "<<jednostka<<endl;//wypisuje niezmieniona jednostke
			cout<<wartosc<<" kg"<<endl;
			return wartosc;
		}
		//////////////
/*		double wartosc() const
		{
			return wartosc;
		}*/
		//////////////
		void zmien(double zm)//double mn=0.5 lub double mn
		{
			wartosc*=zm;//lub mn
			//cout<<wartosc<<" "<<jednostka<<endl;//wypisuje niezmieniona jednostke
			cout<<wartosc<<" kg"<<endl;
		}
		friend bool operator == (const WAGA & w1, const WAGA & w2)
		{
			return w1.wartosc==w2.wartosc;//return w1.jednostka==w2.jednostka;//tez zadziala
			//return w1.wypisz()==w2.wypisz();
		}
		friend bool operator > (const WAGA & w1, const WAGA & w2)
		{
			return w1.wartosc>w2.wartosc;//return w1.jednostka>w2.jednostka;//tez zadziala
			//return w1.wypisz()>w2.wypisz();
		}
};

void porownaj(WAGA & w1, WAGA & w2)
{
	if (w1==w2)
	cout<<"Sa rowne"<<endl;
	else if (w1>w2){
		cout<<"Wiekszy jest pierwszy o parametrach: "<<endl;
		w1.wypisz();
	}
	else{
		cout<<"Wiekszy jest drugi o parametrach: "<<endl;
		w2.wypisz();
	}	
}

int main()
{	
	double war;
	string jed;
	cout<<"Podaj wartosc: ";
	cin>>war;
	cout<<"Podaj jednostke (g, dkg, kg): ";
	cin>>jed;
	cout<<endl;
	//cin>>war>>jed //albo tak
	
/*const*/WAGA m1;//nie dziala porownanie z "const"
	//WAGA m1(1, "kg");
	WAGA m2(war, jed);
	
	cout<<"Wypisz masy:"<<endl;
	//return m1.wartosc();
	//lub
	//return m1.wypisz(); //do odczytu wartosci z obiektu stalego "const WAGA m1"
	m1.wypisz();
	m2.wypisz();
	cout<<endl;
	double zm=0.5;
	cout<<"Zmienione masy: "<<endl;
	m1.zmien(zm);//lub (0.5)
	m2.zmien(zm);//lub (0.5)
	cout<<endl;
	
	porownaj(m1,m2);
	
	return 0;
}	
