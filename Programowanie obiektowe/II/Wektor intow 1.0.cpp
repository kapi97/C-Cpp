/*Stwórz wektor int'ów oraz pêtle, która bêdzie go wype³nia³a 
liczbami wpisywanymi z klawiatury ale tak aby po ka¿dym wstawieniu 
wektor by³ posortowany. (nie wolno u¿ywaæ funkcji sortuj¹cej). 
Wprowadzenie 0 powoduje zakoñczenie dzia³ania pêtli. 
Po zakoñczeniu dzia³ania pêtli proszê podaæ sumê i œredni¹ 
arytmetyczn¹ liczb z wektora.*/

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

	for(int i=0; i<n; i++)
		for(int j=1; j<n-i; j++) //pêtla wewnêtrzna
			if(tab[j-1]>tab[j])
			//zamiana miejscami
			swap(tab[j-1], tab[j]);
    
	cout << '\n';
    //odczyt
    for(int i=0; i<tab.size(); i++)
        cout<<tab[i]<<endl;
    
	return 0;
}
