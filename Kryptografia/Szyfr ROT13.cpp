#include<iostream>
using namespace std;
string szyfrowanie(string szyfrogram);
string deszyfrowanie(string szyfrogram);

int main()
{
	cout<<"Podaj tekst:\n";
	string p, c; //p-tekst jawny, c-kryptogram
	getline(cin,p);
	c=szyfrowanie(p);
	cout<<c<<"\n";
	p=deszyfrowanie(c);
	cout<<p;
	return 0;
}

string szyfrowanie(string szyfrogram) //funkcja szyfruj¹ca  
{
	cout<<"\nSzyfrowanie\n";
	int przesun = 13; //zmienna przesuwaj¹ca o 13 miejsc
	for(int i=0; i<szyfrogram[i]; i++)
	{
		if(szyfrogram[i]>=97 && szyfrogram[i]<=122-przesun || szyfrogram[i]>=65 && szyfrogram[i]<=90-przesun) //sprawdzanie czy przechodzi zakres ma³ych oraz du¿ych liter alfabetu "do przodu" z tabeli ASCII
		szyfrogram[i]+=przesun; //przesuniêcie o podan¹ wczeœniej liczbê w prawo, aby zaszyfrowaæ
		else if (szyfrogram[i]==32){} //pomijanie spacji w szyfrowaniu
		else{szyfrogram[i]+=przesun-26;} //dla skrajnych wartoœci (np. xyz) przesuwa na pocz¹tek alfabetu (np. abc)
	}	
	return szyfrogram;
}

string deszyfrowanie(string szyfrogram) //funkcja deszyfruj¹ca
{
	cout<<"\nDeszyfrowanie\n";
	int przesun = 13; //zmienna przesuwaj¹ca o 13 miejsc
	for(int i=0; i<szyfrogram[i]; i++)
	{
		if(szyfrogram[i]>=97+przesun && szyfrogram[i]<=122 || szyfrogram[i]>=65+przesun && szyfrogram[i]<=90) //sprawdzanie czy przechodzi zakres ma³ych oraz du¿ych liter alfabetu "do ty³u" z tabeli ASCII  
		szyfrogram[i]-=przesun; //przesuniêcie o podan¹ wczeœniej liczbê w lewo, aby deszyfrowaæ
		else if (szyfrogram[i]==32){} //pomijanie spacji w szyfrowaniu
		else{szyfrogram[i]-=przesun-26;} //dla skrajnych wartoœci (np. abc) przesuwa na koniec alfabetu (np. xyz)
	}
	return szyfrogram;
}
