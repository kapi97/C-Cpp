/*PROSZÊ NIE U¯YWAÆ MAKR, ZMIENNYCH GLOBALNYCH, ANI KLASY "String". PROSZÊ NIE PISAÆ ZBÊDNYCH INSTRUKCJI I DEKLARACJI.  
Proszê napisaæ program, w którym jest klasa o nazwie "liczbaZespolona", której obiekty reprezentuj¹ liczby zespolone.
Proszê przeci¹¿yæ konstruktor tej klasy tak, ¿eby mo¿na by³o inicjalizowaæ obiekty tej klasy, nie tylko z klawiatury
na ¿¹danie programu, ale równie¿ domyœlnymi wartoœciami: "1" i "1".
Ponadto proszê tak zdefiniowaæ tê klasê, ¿eby mo¿na by³o realizowaæ dodawanie i odejmowanie liczb zespolonych, w funkcji
"main()", np. z1 + z2 i z1 - z2. Po utworzeniu obiektów tej klasy i zainicjalizowaniu z klawiatury na ¿¹danie programu,
program powinien obliczyæ sumê i ró¿nicê liczb zespolonych, a nastêpnie wyœwietliæ j¹ na ekranie, w postaci a + i*b,
z komentarzem "suma liczb zespolonych:... + i* ..., wynosi:... + i* ...

Pytanie: proszê opisaæ s³ownie (bez pisania odpowiednich fragmentów kodu) co jest dziedziczone (w sposób prywatny,
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

