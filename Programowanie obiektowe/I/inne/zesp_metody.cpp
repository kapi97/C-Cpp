#include <iostream>
class zespolone{
	private:
		float re, im;
	public:
		zespolone(float, float);
		zespolone operator+(zespolone);
		zespolone operator-(zespolone);
		void wypisanie();
};

zespolone::zespolone(float newR, float newU){
	re = newR;
	im = newU;
}

void zespolone::wypisanie(){
	std::cout<<re<<" + "<<im<<"*i"<<std::endl;
}

zespolone zespolone::operator+ (zespolone z0){
	float re2 = re + z0.re;
	float im2 = im + z0.im;
	return zespolone(re2, im2);
} 

zespolone zespolone::operator- (zespolone z0){
	float re2 = re - z0.re;
	float im2 = im - z0.im;
	return zespolone(re2, im2);
}

int main(){
	float x,y;
	std::cout<<"Podaj czesc rzeczywista liczby1: ";
	std::cin>>x;
	std::cout<<"Podaj czesc urojona liczby1: ";
	std::cin>>y;
	zespolone liczba1(x,y);
	
	std::cout<<"podaj czesc urojona liczby2: ";
	std::cin>>x;
	std::cout<<"Podaj czesc rzeczywista liczby2: ";
	std::cin>>y;
	zespolone liczba2(x,y);

	std::cout<<"liczba1: ";
	liczba1.wypisanie();
	std::cout<<"liczba2: ";
	liczba2.wypisanie();
	
	zespolone liczba3 = liczba1 + liczba2;
	std::cout<<"Wynik dodawania: ";
	liczba3.wypisanie();
	
	zespolone liczba4 = liczba1 - liczba2;
	std::cout<<"Wynik odejmowania: ";
	(liczba1-liczba2).wypisanie();
	return 0;
}





