#include <iostream>
#include <cmath>

using namespace std;

class Punkt
{
	private:
		double x, y;
	public:
		Punkt()
		{
			x=0;
			y=0;
		}
		
		Punkt(double a, double b)
		{
			x=a;
			y=b;
		}
		
		void przesun(double a, double b)
		{
			x+=a;
			y+=b;
			wypisz();
		}
		
		void wypisz()
		{
			cout<<"("<<x<<", "<<y<<")"<<endl;
		}
		//sluza do operacji w funkcji "double odleglosc" - maja "dostep" do prywatnych skladowych
		double X(){return x;}
		double Y(){return y;}
		
		/*double odleglosc(Punkt &p1, Punkt &p2)//zadziala tez bez &
		{
			double d= sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));//^2
			cout<<"Odleglosc miedzy punktami: "<<d<<endl;
			return d;
		}*/
};
	//lepszy sposob
	double odleglosc (Punkt &aa, Punkt &bb)//zadziala tez bez &
	{
		double d = (aa.X()-bb.X())*(aa.X()-bb.X())+(aa.Y()-bb.Y())*(aa.Y()-bb.Y());
		//lub inny zapis
		//double d = (aa.Punkt::X()-bb.Punkt::X())*(aa.Punkt::X()-bb.Punkt::X())+(aa.Punkt::Y()-bb.Punkt::Y())*(aa.Punkt::Y()-bb.Punkt::Y());
		cout<<"Odleglosc miedzy punktami: "<<sqrt(d)<<endl;
		return sqrt(d);
	}
		
int main()
{
	int a, b;
	
	cout<<"Podaj wspolrzedne punktu 1: "<<endl;
	cin>>a>>b;
	Punkt p1(a, b);
	cout<<"Wspolrzedne punktu 1: ";
	p1.wypisz();

	cout<<"Przesuniete wspolrzedne punktu 1: ";
	p1.przesun(a,b);
	//p1.wypisz();//w tym przypadku jest w metodzie przesun
	cout<<endl;
	
		cout<<"Podaj wspolrzedne punktu 2: "<<endl;
		cin>>a>>b;
		Punkt p2(a, b);
		cout<<"Wspolrzedne punktu 2: ";
		p2.wypisz();
		
		cout<<"Przesuniete wspolrzedne punktu 2: ";
		p2.przesun(a,b);
		//p2.wypisz();//w tym przypadku jest w metodzie przesun
		cout<<endl;
		
//	p1.odleglosc(p1, p2); //p1. --> gdy "double odleglosc" jest w klasie
	odleglosc(p1, p2);//gdy jest poza klasa - lepszy sposob
	cout<<endl;

	return 0;
}
