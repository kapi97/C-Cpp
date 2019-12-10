#ifndef FIGURY_H
#define FIGURY_H

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>

#define _USE_MATH_DEFINES
#include <math.h>//do rysowania ko³a

GLuint VAO;
GLuint VBO;
GLuint wielkoscPunktu = 10;

class Figury
{
private:
	int wysokoscOkna;
	int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	Figury(void);
	Figury(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	~Figury(void);
	void stworzenieOkna(int argc, char** argv);
	void inicjalizacjaGlew();
	static void wyswietl();
	static void usun();
	void stworzenieVAO();
	void stworzenieVBO();
	void sprawdzenieWersji();
};

#endif /* FIGURY_H */