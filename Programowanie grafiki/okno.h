#ifndef OKNO_H //stra¿nik nag³ówka
#define OKNO_H

#include <iostream>
#include <GL/freeglut.h> //do³¹czenie biblioteki - biblioteka odpowiedzialna za okno

class Okno
{
private:
	int wysokoscOkna;
	int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	Okno(void);
	Okno(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	~Okno(void);
	void stworzenieOkna(int argc, char** argv);
	static void wyswietl();
};

#endif /* OKNO_H */
//ten zapis zapobiega przypadkowemu ponownemu zdefiniowaniu rzeczy