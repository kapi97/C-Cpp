#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class TABLICA{
	private:
		char *p;
	public:
	
	TABLICA()
	{ 
		p = new char[strlen("domyslny")+1];
		assert(p);
		strcpy(p,"domyslny");
		cout<<"Konstruktor (bezparametrowy) domyslny"<<endl<<endl;
	}
		
	TABLICA(/*const*/char * tab)
	{ 
		p = new char[strlen(tab)+1];
		assert(p);
		strcpy(p,tab);
		cout<<"Konstruktor"<<endl<<endl;
	}
	
	TABLICA(/*const*/ TABLICA & kopia)
	{
		p = new char[strlen(kopia.p)+1];
		assert(p);
		strcpy(p, kopia.p);
		cout<<"Konstruktor kopiujacy"<<endl<<endl;
	}
	
	TABLICA & operator=(/*const*/ TABLICA & kopia)
	//lub
	//void operator=(/*const*/ TABLICA & kopia)
	{
		p = new char[strlen(kopia.p)+1];
		assert(p);
		strcpy(p, kopia.p);
		cout<<"Operator przypisania"<<endl<<endl;
	}
	
	~TABLICA()
	{
		delete [] p;
		cout<<"Destruktor"<<endl;
	}
};

int main()
{
	char tab[] = "Avatar";
	
	TABLICA t0;
	TABLICA t1(tab);
	TABLICA t2 = t1;
	
	return 0;
}
