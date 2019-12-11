#include <iostream>
class zespolone{
	private:
		float re, im;
		friend zespolone operator+(zespolone z0, zespolone z1);
		friend zespolone operator-(zespolone z0, zespolone z1);

		// 1) ZAPRZYJAZNIENIE Z OPERATORAMI ZEWNETRZNYMI WE/WY
		friend std::ostream& operator<<(std::ostream& wy, zespolone z1);
		friend std::istream& operator>>(std::istream& we, zespolone& z1);
		// ...
	public:
		/* 2) OPERATORY WEWNETRZNE WE/WY
		zespolone operator+(zespolone);
		zespolone operator-(zespolone);
		*/
		zespolone();
		zespolone(float, float);
};

zespolone::zespolone(){
	float re = im = 0;
}

zespolone::zespolone(float newR, float newU){
	re = newR;
	im = newU;
}

zespolone operator+ (zespolone z0, zespolone z1){
	float re2 = z0.re + z1.re;
	float im2 = z0.im + z1.im;
	return zespolone(re2, im2);
} 

zespolone operator- (zespolone z0, zespolone z1){
	float re2 = z0.re - z1.re;
	float im2 = z0.im - z1.im;
	return zespolone(re2, im2);
}


/* 2) OPERATORY WEWNETRZNE WE/WY
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

*/

// 1) OPERATORY ZEWNETRZNE WE/WY
std::ostream& operator<<(std::ostream& wy, zespolone z1){
	wy<<z1.re<<" + " << z1.im << "*i";
	return wy;
}

std::istream& operator>>(std::istream& we, zespolone& z1){
	std::cout<<"re: ";
	we>>z1.re;
	std::cout<<"im: ";
	we>>z1.im;
	return we;
}
//...

int main(){
	std::cout<<"Wprowadz liczbe zespolona nr.1:"<<std::endl;
	zespolone liczba1;
	std::cin>>liczba1;

	std::cout<<"Wprowadz liczbe zespolona nr.2:"<<std::endl;
	zespolone liczba2;
	std::cin>>liczba2;
	
	std::cout<<"Liczba pierwsza: "<<liczba1<<std::endl;
	std::cout<<"Liczba druga: "<<liczba2<<std::endl;

	zespolone liczba3 = liczba1 + liczba2;
	std::cout<<"Wynik dodawania: ";
	std::cout<<liczba3<<std::endl;
	
	std::cout<<"Wynik odejmowania: ";
	std::cout<<liczba1 - liczba2<<std::endl;
	return 0;
}





