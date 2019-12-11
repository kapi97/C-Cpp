/*Stwórz wektor int'ów oraz pêtle, która bêdzie go wype³nia³a 
liczbami wpisywanymi z klawiatury ale tak aby po ka¿dym wstawieniu 
wektor by³ posortowany. (nie wolno u¿ywaæ funkcji sortuj¹cej). 
Wprowadzenie 0 powoduje zakoñczenie dzia³ania pêtli. 
Po zakoñczeniu dzia³ania pêtli proszê podaæ sumê i œredni¹ 
arytmetyczn¹ liczb z wektora.*/

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
