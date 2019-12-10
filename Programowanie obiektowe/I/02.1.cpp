#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class TABLICA{
	private:
		int *p;
	public:
	
	TABLICA()
	{ 
		p = 0;
		cout<<"Konstruktor (bezparametrowy) domyslny"<<endl<<endl;
	}
		
	TABLICA(/*const*/int * tab)
	{ 
		p = tab;
		cout<<"Konstruktor"<<endl<<endl;
	}
	
	TABLICA(/*const*/ TABLICA & kopia)
	{
		p = kopia.p;
		cout<<"Konstruktor kopiujacy"<<endl<<endl;
	}
	
	TABLICA & operator=(/*const*/ TABLICA & kopia)
	//lub
	//void operator=(/*const*/ TABLICA & kopia)
	{
		p = kopia.p;
		assert(p);
		cout<<"Operator przypisania"<<endl<<endl;
	}
	
	~TABLICA()
	{
		cout<<"Destruktor"<<endl;
	}
};

int main()
{
	int * liczba=0;
	
	TABLICA t0;
	TABLICA t1 (liczba);
	TABLICA t2 = t1;
	
	return 0;
}
