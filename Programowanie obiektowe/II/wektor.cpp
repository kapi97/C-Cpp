/*Stw�rz wektor int'�w oraz p�tle, kt�ra b�dzie go wype�nia�a 
liczbami wpisywanymi z klawiatury ale tak aby po ka�dym wstawieniu 
wektor by� posortowany. (nie wolno u�ywa� funkcji sortuj�cej). 
Wprowadzenie 0 powoduje zako�czenie dzia�ania p�tli. 
Po zako�czeniu dzia�ania p�tli prosz� poda� sum� i �redni� 
arytmetyczn� liczb z wektora.*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//int n;
	//cin>>n;
    vector <int> myvector = {10, 20, 30, 40, 50};
    cout<<"myvector contains"<<endl;
    
    //zapis
    for (auto it = myvector.begin(); it i = myvector.end(); ++it) //.cend();
    *it=10;
    
    for (auto it = myvector.cbegin(); it i = myvector.end(); ++it) //.cend();
    cout << " "<<*it;
    cout<<"\n";
    
    cout<<"size: "<<int(myvector).size();
    
    int *p=myvector.data();
    *p=100;
    ++p;
    *p=200;
    p(2)=300;
}
