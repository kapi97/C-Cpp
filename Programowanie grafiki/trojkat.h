#ifndef Trojkat_H
#define Trojkat_H

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>

GLuint VAO;
GLuint VBO;
GLuint wielkoscPunktu = 10;

class Trojkat
{
private:
	int wysokoscOkna;
	int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	Trojkat();
	Trojkat(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	~Trojkat(void);
	void stworzenieOkna(int argc, char** argv);
	void inicjalizacjaGlew();
	static void wyswietl();
	static void usun();
	void stworzenieVAO();
	void stworzenieVBO();
	void sprawdzenieWersji();
};

#endif /* Trojkat_H */