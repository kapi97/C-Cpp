#include <iostream>
#include <cstdlib>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

string otp_szyfruj(string tekst,string klucz)
{
    for(int i=0;i<tekst.length();i++)
    {
    	if(tekst[i] >= 65 && tekst[i] <= 90 && klucz[i] >= 65 && klucz[i] <= 90) {
    		//duza litera klucz, tekst duza
    		tekst[i]=((tekst[i]-65)+(klucz[i]-65))%26+65;	
		} else if (tekst[i] >= 97 && tekst[i] <= 122 && klucz[i] >= 97 && klucz[i] <= 122) {
			//mala litera klucz, tekst mala
			tekst[i]=((tekst[i]-97)+(klucz[i]-97))%26+97;    	
		} else if (tekst[i] >= 97 && tekst[i] <= 122 && klucz[i] >= 65 && klucz[i] <= 90) {
			//mala litera tekst, duza litera klucz
			tekst[i]=((tekst[i]-97) + (klucz[i]-65))%26 + 97;
		} else if (tekst[i] >= 65 && tekst[i] <= 90 && klucz[i] >= 97 && klucz[i] <= 122) {
			//duza litera tekst, mala litera klucz
			tekst[i]=((tekst[i]-65) + (klucz[i]-97))%26 + 65;
		}
    }
    
    return tekst;
}

string otp_deszyfruj(string tekst,string klucz)
{
    for(int i=0;i<tekst.length();i++)
    {
    	if(tekst[i] >= 65 && tekst[i] <= 90 && klucz[i] >= 65 && klucz[i] <= 90) {
    		//duza litera klucz, tekst duza
    		tekst[i]=(((tekst[i]-65))-(klucz[i]-65)+26)%26 + 65;      	
		} else if (tekst[i] >= 97 && tekst[i] <= 122 && klucz[i] >= 97 && klucz[i] <= 122) {
			//mala litera klucz, tekst mala
			tekst[i]=(((tekst[i]-97))-(klucz[i]-97)+26)%26 + 97;      	
		} else if (tekst[i] >= 97 && tekst[i] <= 122 && klucz[i] >= 65 && klucz[i] <= 90) {
			//mala litera tekst, duza litera klucz
			tekst[i]=(((tekst[i]- 97)-(klucz[i]-65)+26))%26 + 97;
		} else if (tekst[i] >= 65 && tekst[i] <= 90 && klucz[i] >= 97 && klucz[i] <= 122) {
			//duza litera tekst, mala litera klucz
			tekst[i]=((tekst[i]-65)-(klucz[i]-97)+26)%26 + 65;
		}
    }
    
    return tekst;
}

int main() {
	srand( time( NULL ) );
	string tekst;
	string klucz;
	string klucz_string;
	
	cout << "Podaj slowo do zaszyfrowania" << endl;
	cin >> tekst;
	cout << "Podane slowo: " << tekst << endl;
	
	//Generowanie losowych liter z zakresu alfbateru Ascii(65-90, 97-122 za pomoc¹ funkcji rand
	for(int i = 0; i<tekst.length(); i++) {
		int random = rand()%122;
		
		while(!(random >= 65 && random <= 90 || random >= 97 && random <= 122)) {
			random = rand()%122;
		} 
		
		klucz[i] = 0;
		klucz[i] = klucz[i] + random;
		klucz_string += klucz[i];
	}
	
	cout << "Wygenerowany klucz: " << klucz_string << endl;
	
	string szyfr = otp_szyfruj(tekst, klucz_string);
	cout << "Wygenerowany szyfr: " << otp_szyfruj(tekst, klucz_string) << endl;
	cout << "Tekst po deszyfracji: " << otp_deszyfruj(szyfr, klucz_string) << endl;
	
	return 0;
}
