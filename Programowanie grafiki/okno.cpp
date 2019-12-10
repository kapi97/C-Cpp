#include "okno.h" //dołączenie pliku nagłówkowego

Okno::Okno(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Okno::Okno(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{//ustawianie parametrów okna - wysokość, szerokość, położenie x i y
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Okno::~Okno(void)
{
	std::cout << "Destruktor";
	//system("pause");
}

void Okno::stworzenieOkna(int argc, char** argv) //metoda stworzenia okna
{
	glutInit(&argc, argv);//inicjalizacja biblioteki GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//double-umożliwia podwójne buforowanie; rgba-tryb kolorów:red, green, blue, alpha(przezroczystość)
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);//wielkość okna
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);//pozycja
	glutCreateWindow("Okno");
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION); //automatyczne wywołanie destruktora, wcześniej program nie wychodził z tej pętli
	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);//to samo, co powyżej
}

void  Okno::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);//czyści bufory do wcześniej ustawionych wartości
	glutSwapBuffers();//zamienia bufory miejscami; korzystając z glut_double mamy dwa bufory
}

int main(int argc, char** argv)
{
	Okno okno(786, 1024, 100, 100);
	okno.stworzenieOkna(argc, argv);
	glutDisplayFunc(okno.wyswietl);
	glClearColor(1.0f, 0.8f, 0.9f, 0.0f);//ustawienie koloru różowego
	glutMainLoop();//pętla glut, która nasłuchuje, czy nastąpiło jakieś wydarzenie, jeśli tak, to ponownie zostanie wywołana metoda okno::wyswietl
//utrzymuje obraz
	//system("pause");//służy do ręcznego wywołania destruktora
	return 0;
}