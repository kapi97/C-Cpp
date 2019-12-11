/*Prosz� napisa� program, w kt�rym jest szablon klas o nazwie "wektor2".
Obiekt tych klas reprezentuj� wektory w przestrzeni dwuwymiarowej.
Program powinien realizowa� dodawanie wektor�w (bez przeci��ania operator�w)
dla trzech typ�w sk�adowych: typu ca�kowitego, zmiennopozycyjnego i
zmiennopozycyjnego podw�jnej precyzji. Prosz� w funkcji "main()" utworzy�
po jednym obiekcie ka�dej z tych klas oraz zainicjalizowa� go z klawiatury
na ��danie programu. Wyniki dzia�a� na wektorach powinny by� wy�wietlane na ekran,
po wykonaniu dodawania dw�ch wektor�w.
Pytanie: prosz� opisa� s�ownie (bez pisania odpowiednich fragment�w kodu), kiedy
i dlaczego jest absolutnie nieodzowne deklarowanie destruktora jako wirtualnego?*/

#include<iostream>

template<class T>//doda� np. T1, T2, T3
class wektor2
{
	private:
		//int a, float b, double c;
		T a, b, c;
		//T1 a=1; T2 b=2.0; T3 c=3;
		
	public:
		/*T wektor2(T aa, T bb, T cc){
			a=aa; b=bb; c=cc;
		}*/
		//void ukryj(T);
		T uzupelnij();
		T zwroc();
		/*T1 zwrocint();
		T2 zwrocfloat();
		T3 zwrocdouble();*/
};
/*
template<class T>
void wektor2<T>::ukryj(T aa)
{
a = aa;

}*/

template<class T>
T wektor2<T>::uzupelnij( )
{std::cin>>a;std::cin>>b;/*std::cin>>c;*/}

template<class T>
T wektor2<T>::zwroc( )
{std::cout<<a<<", "<<b<</*", "<<c<<*/std::endl;
std::cout<<"SUMA: ";
std::cout<<a+b /*+c*/<<std::endl;
return a+b /*+c*/;}
/*template<class T1>
T1 wektor2<T1>::zwrocint( )
{return a+b+c;}

template<class T2>
T2 wektor2<T2>::zwrocfloat( )
{return a+b+c;}

template<class T3>
T3 wektor2<T3>::zwrocdouble( )
{return a+b+c;}*/

int main( )
{
	wektor2<int> obiektInt;
	wektor2<float> obiektFloat;
	wektor2<double> obiektDouble;
	std::cout<<"INT"<<std::endl;
	obiektInt.uzupelnij();
	obiektInt.zwroc();
	std::cout<<"FLOAT"<<std::endl;
	obiektFloat.uzupelnij();
	obiektFloat.zwroc();
	std::cout<<"DOUBLE"<<std::endl;
	obiektDouble.uzupelnij();
	obiektDouble.zwroc();
	
	return 0;
}

