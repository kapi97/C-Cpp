/*1. Dana jest nastêpuj¹ca klasa:

class NAPIS {
const int l;
char *s;
public:

NAPIS (int k) {l = k; s=new char[k];}

};

a) Czy poprawnie zadeklarowano t¹ klasê? Je¿eli nie to wskazaæ b³¹d i poprawiæ
b) Zdefiniowaæ konstruktor kopiuj¹cy dla tej klasy
c) Zdefiniowaæ operator strumienia >>
d) Zdefiniowaæ operator indeksowania
e) Zdefiniowaæ destruktor

2. Napisaæ program, w którym tworzony jest obiekt klasy NAPIS przechowuj¹cy tekst "ABCD".
Nastêpnie wyprowadziæ ten tekst na standardowe wyjœcie.
Stworzyæ kopiê obiektu i w kopii zamieniæ w tekœcie literê C na X.*/

//a) Nie 
// po 1) nie mo¿emy zmieniaæ wartoœci zmiennej l (jest const), b³¹d kompilacji
// po 2) aby upewniæ siê, ¿e dynamiczna alokacja pamiêci zakoñczy³a siê sukcesem nale¿y to sprawdziæ,
// 	funkcj¹ assert z biblioteki cassert.

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
