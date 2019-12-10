#include<iostream>
using namespace std;
string szyfr(string szyfrogram);

int main()
{
	cout<<"Podaj tekst: ";
	string p, c; //p-tekst jawny, c-kryptogram
	getline(cin, p);
	c=szyfr(p);
	cout<<"Zaszyfrowany tekst: "<<c<<endl;
	p=szyfr(c);
	cout<<"Odszyfrowany tekst: "<<p<<endl;
	system("pause");
	return 0;
}

string szyfr(string szyfrogram)
{
	for(int i=0; szyfrogram[i]; i++)
	{
		if(szyfrogram[i]>=65 && szyfrogram[i]<=90) //sprawdzanie czy przechodzi zakres du¿ych liter alfabetu z tabeli ASCII
		{
			szyfrogram[i]=(90-(szyfrogram[i]-65)); //zamiana du¿ych liter le¿¹cych po drugiej stronie alfabetu w takiej samej odleg³oœci od koñca/pocz¹tku
		}
		//nrZaszyfrowanego = (max-(x-min)); np. max=90 dla 'Z', min=65 dla 'A', x->tekst jawny (np. 86 dla 'V'), nrZaszyfrowanego->tekst zaszyfrowany (np. 69 dla 'E')
		//np. nrZaszyfrowanego = (90-(86-65))=90-21=69 (za ka¿dym razem pobierana jest jedna litera tekstu)

		else if(szyfrogram[i]>=97 && szyfrogram[i]<=122) //sprawdzanie czy przechodzi zakres ma³ych liter alfabetu z tabeli ASCII
		{
			szyfrogram[i]=(122-(szyfrogram[i]-97)); //zamiana ma³ych liter le¿¹cych po drugiej stronie alfabetu w takiej samej odleg³oœci od koñca/pocz¹tku
		}
		//nrZaszyfrowanego = (max-(x-min)); np. max=122 dla 'z', min=97 dla 'a', x->tekst jawny (np. 118 dla 'v'), nrZaszyfrowanego->tekst zaszyfrowany (np. 101 dla 'e')
		//np. nrZaszyfrowanego = (122-(118-97))=122-21=101 (za ka¿dym razem pobierana jest jedna litera tekstu)

		else if(szyfrogram[i]>=48 && szyfrogram[i]<=57) //sprawdzanie czy przechodzi zakres cyfr z tabeli ASCII
		{
			szyfrogram[i]=(57-(szyfrogram[i]-48)); //zamiana cyfr le¿¹cych po drugiej stronie w takiej samej odleg³oœci od koñca/pocz¹tku
		}
		//nrZaszyfrowanego = (max-(x-min)); np. max=57 dla '9', min=48 dla '0', x->tekst jawny (np. 49 dla '1'), nrZaszyfrowanego->tekst zaszyfrowany (np. 56 dla '8')
		//np. nrZaszyfrowanego = (57-(49-48))=57-1=56 (za ka¿dym razem pobierana jest jedna cyfra tekstu)
	}
	return szyfrogram;
}
