/*PROSZ� NIE U�YWA� MAKR, ZMIENNYCH GLOBALNYCH, ANI KLASY "String". PROSZ� NIE PISA� ZB�DNYCH INSTRUKCJI I DEKLARACJI.  
Prosz� napisa� program, w kt�rym jest klasa o nazwie "liczbaZespolona", kt�rej obiekty reprezentuj� liczby zespolone.
Prosz� przeci��y� konstruktor tej klasy tak, �eby mo�na by�o inicjalizowa� obiekty tej klasy, nie tylko z klawiatury
na ��danie programu, ale r�wnie� domy�lnymi warto�ciami: "1" i "1".
Ponadto prosz� tak zdefiniowa� t� klas�, �eby mo�na by�o realizowa� dodawanie i odejmowanie liczb zespolonych, w funkcji
"main()", np. z1 + z2 i z1 - z2. Po utworzeniu obiekt�w tej klasy i zainicjalizowaniu z klawiatury na ��danie programu,
program powinien obliczy� sum� i r�nic� liczb zespolonych, a nast�pnie wy�wietli� j� na ekranie, w postaci a + i*b,
z komentarzem "suma liczb zespolonych:... + i* ..., wynosi:... + i* ...

Pytanie: prosz� opisa� s�ownie (bez pisania odpowiednich fragment�w kodu) co jest dziedziczone (w spos�b prywatny,
chroniony i publiczny) z klasy bazowej?
*/

#include <iostream>

class liczbaZespolona{
    float re, im;
    friend liczbaZespolona operator+(const liczbaZespolona &, const liczbaZespolona &);
    friend liczbaZespolona operator-(const liczbaZespolona &, const liczbaZespolona &);
    friend std::ostream & operator<<(std::ostream &, const liczbaZespolona &);
    friend std::istream & operator>>(std::istream &, liczbaZespolona &);
public:
    liczbaZespolona();
    liczbaZespolona(float, float);
};

liczbaZespolona::liczbaZespolona(){
    re = im = 1;
}

liczbaZespolona::liczbaZespolona(float re, float im){
    this->re = re;
    this->im = im;
}

liczbaZespolona operator+(const liczbaZespolona & z1, const liczbaZespolona & z2){
    liczbaZespolona result(z1.re+z2.re, z1.im+z2.im);
    return result;
}
liczbaZespolona operator-(const liczbaZespolona & z1, const liczbaZespolona & z2){
    liczbaZespolona result(z1.re-z2.re, z1.im-z2.im);
    return result;
}

std::ostream & operator<<(std::ostream & wyjscie, const liczbaZespolona & obj){
    wyjscie<<"["<<obj.re<<","<<obj.im<<"]";
    return wyjscie;
}
std::istream & operator>>(std::istream & wejscie, liczbaZespolona & obj){
	std::cout<<"Podaj a i b: ";
    wejscie>>obj.re>>obj.im;
    return wejscie;
}

//void wczytajliczbaZespolona(float &, float &);

int main() {
    float a,b;
    std::cout<<"Wczytuje paremetry pierwszego liczbaZespolona."<<std::endl;
    //wczytajliczbaZespolona(a,b);
    liczbaZespolona lz1(a,b);
    std::cin>>lz1;
    std::cout<<"Wczytuje paremetry drugiego liczbaZespolona."<<std::endl;
   // wczytajliczbaZespolona(a,b);
    liczbaZespolona lz2(a,b);
    std::cin>>lz2;
    
    liczbaZespolona lz3 = lz1 + lz2;
    liczbaZespolona lz4 = lz1 - lz2;
    
    std::cout<<"Parametry liczbaZespolona 1: "<<lz1<<std::endl;
    std::cout<<"Parametry liczbaZespolona 2: "<<lz2<<std::endl;
    std::cout<<"Parametry sumy liczbaZespolona: "<<lz3<<std::endl;
    std::cout<<"Parametry roznicy liczbaZespolona: "<<lz4<<std::endl;
    return 0;
}
/*
void wczytajliczbaZespolona(float & a, float & b){
    std::cout<<"Podaj a: ";
    std::cin>>a;
    std::cout<<"Podaj b: ";
    std::cin>>b;
}*/

