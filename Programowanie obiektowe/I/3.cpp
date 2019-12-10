/*1. Dana jest nast�puj�ca klasa:

class NAPIS {
const int l;
char *s;
public:

NAPIS (int k) {l = k; s=new char[k];}

};

a) Czy poprawnie zadeklarowano t� klas�? Je�eli nie to wskaza� b��d i poprawi�
b) Zdefiniowa� konstruktor kopiuj�cy dla tej klasy
c) Zdefiniowa� operator strumienia >>
d) Zdefiniowa� operator indeksowania
e) Zdefiniowa� destruktor

2. Napisa� program, w kt�rym tworzony jest obiekt klasy NAPIS przechowuj�cy tekst "ABCD".
Nast�pnie wyprowadzi� ten tekst na standardowe wyj�cie.
Stworzy� kopi� obiektu i w kopii zamieni� w tek�cie liter� C na X.*/

//a) Nie 
// po 1) nie mo�emy zmienia� warto�ci zmiennej l (jest const), b��d kompilacji
// po 2) aby upewni� si�,��e dynamiczna alokacja pami�ci zako�czy�a si� sukcesem nale�y to sprawdzi�,
// 	funkcj� assert z biblioteki cassert.

#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class NAPIS{
		int l;
		char *s;	
	public:
		friend istream & operator >> (istream &, NAPIS &);
		friend ostream & operator << (ostream &, NAPIS &);
		char & operator[](int);
		NAPIS();
		NAPIS(int k){
			l=k; 
			s=new char[k];
			assert(s);
		}
		NAPIS(NAPIS &);
		~NAPIS();		
};

NAPIS::NAPIS(){
	l = -1;
}

NAPIS::NAPIS(NAPIS & obj){
	l = obj.l;
	s = new char [strlen(obj.s)+1];
	assert(s);
	strcpy(s, obj.s);
}

NAPIS::~NAPIS(){
	delete [] s;
}

istream & operator>>(istream & input, NAPIS & obj){
	cout<<"Podaj napis: ";
	input>>obj.s;
	return input;
}

ostream & operator<<(ostream & output, NAPIS & obj){
	output<<obj.s;
	return output;
}

char & NAPIS::operator[](int index){
	return s[index];
}

int main(){
	NAPIS napis1(4);
	cin>>napis1;
	cout<<napis1<<endl;
	NAPIS napis2 = napis1;
	napis2[2] = 'X';
	cout<<"napis2: "<<napis2<<endl;
	return 0;	
}
