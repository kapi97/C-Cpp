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
	
	//wywo�anie funkcji
	szyfr=szyfrowanie(tekst, klucz);
	cout<<"Zaszyfrowany tekst: "<<szyfr<<endl;
	tekst=szyfrowanie(szyfr, klucz);
	cout<<"Odszyfrowany tekst: "<<tekst<<endl;
	system("pause");
	return 0;
}

string szyfrowanie(string tekst, string klucz) //funkcja szyfruj�ca/deszyfruj�ca
//pobieramy tekst do szyfrowania jako zmienn� "tekst" i klucz jako zmienn� "klucz"
{
	for(int i=0; tekst[i]; i++)
	{
		//wyr�wnanie d�ugo�ci klucza
		if(klucz[i]<tekst[i]) //lub if(klucz.length()<tekst.length())
		{
			klucz+=klucz; //gdy d�ugo�� klucza jest kr�tsza od d�ugo�ci tekstu, znaki z klucza powielaj� si�, wyr�wnuj�c do d�ugo�ci tekstu
		}

		//sprawdzanie czy przechodzi zakres du�ych liter alfabetu z tabeli ASCII
		if(tekst[i]>=65 && tekst[i]<=90)
		{
			tekst[i]=klucz[i]-tekst[i]+65; //przypisanie do tablicy zaszyfrowanego tekstu
			
			if(tekst[i]<65)
			{
				tekst[i]=tekst[i]+90-65+1; //prawid�owe wy�wietlanie znak�w tekstu, gdy wychodz� poza zakres du�ych liter z tabeli ASCII, np. 58-64
			}
		}
		
		//sprawdzanie czy przechodzi zakres ma�ych liter alfabetu z tabeli ASCII
		else if(tekst[i]>=97 && tekst[i]<=122)
		{
			tekst[i]=klucz[i]-tekst[i]+97; //przypisanie do tablicy zaszyfrowanego tekstu
			
			if(tekst[i]<97)
			{
				tekst[i]=tekst[i]+122-97+1; //prawid�owe wy�wietlanie znak�w tekstu, gdy wychodz� poza zakres ma�ych liter z tabeli ASCII, np. 91-96
			}
		}
	}
	return tekst;
}
