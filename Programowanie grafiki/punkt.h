#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>//biblioteka wej�cia-wyj�cia
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
//zmienne globalne
GLuint VAO;//Vertex Array Object (przechowuje id obiektu openGL), przechowuje format danych wierzcho�k�w i bufor�w
GLuint VBO;//Vertex Buffor Object, b�dzie przechowywany identyfikator bufora
GLuint wielkoscPunktu = 10;

class Punkt
{
private:
	int wysokoscOkna;
	int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	Punkt(void);
	Punkt(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	~Punkt(void);
	void stworzenieOkna(int argc, char** argv);
	void inicjalizacjaGlew();
	static void wyswietl();
	static void usun(); //usuwanie bufor�w - czyszczenie
	void stworzenieVAO();
	void stworzenieVBO();
	void sprawdzenieWersji();
};

#endif /* PUNKT_H */
