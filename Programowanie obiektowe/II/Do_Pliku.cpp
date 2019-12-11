#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <list>
#include <cstdio>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){


ofstream f("Plik.txt");

if(f.good()){
    //f << wartosc_kata << "| " << wartosc_radianach << "| " << sinata << "| " << cosinus << "| ";
    for(int i = 0; i<=180 ; i++){
        cout << setprecision(8) << i << "\t|" << (i * 3.14 / 180) << "\t|" << sin((i * 3.14 / 180)) << "\t|" << cos((i * 3.14 / 180)) << "\t|" <<endl;
        f << setprecision(8) << i << "\t|" << (i * 3.14 / 180) << "\t|" << sin((i * 3.14 / 180)) << "\t|" << cos((i * 3.14 / 180)) << "\t|" <<endl;
    }
    f.close();
}

/*
int nr;
cout<< "Podaj kat: ";
cin>> nr;

fstream f("Plik.txt",ios::in);
string dane;

for(int c=0; c<=nr;c++){
    getline(f, dane);
}

cout<< "kat " << "\t|" << "Rad " << "\t|" << "SIN " << "\t|" << "COS " << "\t|" <<endl;
cout<<dane <<endl;

f.close();
*/

return 0;
}
//cout<< "Podaj wartoœæ k¹ta: ";
    //cin>> wartosc_kata;
    //if(wartosc_kata<0 || wartosc_kata > 360){
      //  f.close();
        //flag = true;
    //}
    //cout<< "wartosc_kata " << "|" << "Radian " << "|" << "SIN " << "|" << "COS " << "|" <<endl;
    //cout<< wartosc_kata << "|\t" << (wartosc_radianach * 3.14 / 180) << "| \t" << sin((wartosc_radianach * 3.14 / 180)) << "|\t" << cos((wartosc_radianach * 3.14 / 180)) << "|\t" <<endl;
    //f << wartosc_kata << "|\t" << (wartosc_radianach * 3.14 / 180) << "| \t" << sin((wartosc_radianach * 3.14 / 180)) << "|\t" << cos((wartosc_radianach * 3.14 / 180)) << "|\t" <<endl;
