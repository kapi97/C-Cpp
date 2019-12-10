#include <iostream>
using namespace std;
string szyfrowanie(string tekst, string klucz);

int main()
{
	string tekst, klucz, szyfr;
	
	//wprowadzenie tekstu i klucza
	cout<<"Podaj tekst: ";
	getline(cin, tekst); //pobranie tekstu z klawiatury
	cout<<"Podaj klucz: ";
	getline(cin, klucz); //lub cin>>klucz;
	
	//wywo³anie funkcji
	szyfr=szyfrowanie(tekst, klucz);
	cout<<"Zaszyfrowany tekst: "<<szyfr<<endl;
	tekst=szyfrowanie(szyfr, klucz);
	cout<<"Odszyfrowany tekst: "<<tekst<<endl;
	system("pause");
	return 0;
}

string szyfrowanie(string tekst, string klucz) //funkcja szyfruj¹ca/deszyfruj¹ca
//pobieramy tekst do szyfrowania jako zmienn¹ "tekst" i klucz jako zmienn¹ "klucz"
{
	for(int i=0; tekst[i]; i++)
	{
		//wyrównanie d³ugoœci klucza
		if(klucz[i]<tekst[i]) //lub if(klucz.length()<tekst.length())
		{
			klucz+=klucz; //gdy d³ugoœæ klucza jest krótsza od d³ugoœci tekstu, znaki z klucza powielaj¹ siê, wyrównuj¹c do d³ugoœci tekstu
		}

		//sprawdzanie czy przechodzi zakres du¿ych liter alfabetu z tabeli ASCII
		if(tekst[i]>=65 && tekst[i]<=90)
		{
			tekst[i]=klucz[i]-tekst[i]+65; //przypisanie do tablicy zaszyfrowanego tekstu
			
			if(tekst[i]<65)
			{
				tekst[i]=tekst[i]+90-65+1; //prawid³owe wyœwietlanie znaków tekstu, gdy wychodz¹ poza zakres du¿ych liter z tabeli ASCII, np. 58-64
			}
		}
		
		//sprawdzanie czy przechodzi zakres ma³ych liter alfabetu z tabeli ASCII
		else if(tekst[i]>=97 && tekst[i]<=122)
		{
			tekst[i]=klucz[i]-tekst[i]+97; //przypisanie do tablicy zaszyfrowanego tekstu
			
			if(tekst[i]<97)
			{
				tekst[i]=tekst[i]+122-97+1; //prawid³owe wyœwietlanie znaków tekstu, gdy wychodz¹ poza zakres ma³ych liter z tabeli ASCII, np. 91-96
			}
		}
	}
	return tekst;
}
