/*Stw�rz wektor int'�w oraz p�tle, kt�ra b�dzie go wype�nia�a 
liczbami wpisywanymi z klawiatury ale tak aby po ka�dym wstawieniu 
wektor by� posortowany. (nie wolno u�ywa� funkcji sortuj�cej). 
Wprowadzenie 0 powoduje zako�czenie dzia�ania p�tli. 
Po zako�czeniu dzia�ania p�tli prosz� poda� sum� i �redni� 
arytmetyczn� liczb z wektora.*/

#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
    vector <int> tab;
    cout<<endl;
    
	while(n!=0){
	//if(n!=0){
    //zapis
    int x=0;
    for(int i=0; i<n; i++)
    {	
        tab.push_back(x);
        cin>>tab[i];
        //x = x + 2; 
        //sort( tab.begin(), tab.end() );
    }
    
    //sort( tab.begin(), tab.end() );

	for(int i=0; i<n; i++){
		for(int j=1; j<n-i; j++){ //p�tla wewn�trzna
			if(tab[j-1]>tab[j]){
			//zamiana miejscami
			swap(tab[j-1], tab[j]);}}}
    
	cout << '\n';
    //odczyt
    for(int i=0; i<tab.size(); i++){
        cout<<tab[i]<<endl;}
    
	break;}
	//else system("PAUSE");

	cout<<endl;
	
	if(n>0){

	float suma = 0;
	for(int i = 0; i < n ; i++)
    {
        suma = suma + tab[i];
    }
    cout<<"Suma: "<<suma<<endl;
    
	float srednia = suma/n;
    cout<<"Srednia: "<<srednia;
    
	}else cout<<"Nieprawidlowa wartosc zmiennej n."<<endl;
	
	return 0;
}
