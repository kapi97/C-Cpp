#include "punkt.h"

Punkt::Punkt(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Punkt::Punkt(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Punkt::~Punkt()
{
	//std::cout << "Destruktor";
}

void Punkt::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	//glewExperimental = GL_TRUE;
	//glutInitContextVersion(3,3);//ustawienie kontekstu; w jakim GL uruchamiamy, 3.3 jest najniższy
	//glutInitContextProfile(GLUT_CORE_PROFILE);//lub glut_core_profile, wersja bez kompatybilności wstecznej
	glutCreateWindow("Punkty");
	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
}

void Punkt::inicjalizacjaGlew()//sprawdza, czy nie zakończyła się błędem
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;//std::cerr - domyślne wyjście dla błędów
		system("pause");
		exit(1);
	}
}

void  Punkt::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);//czyszczenie bufora

	glEnableVertexAttribArray(0);//umożliwia przekazywanie danych z bufora //włącza ogólną tablicę atrybutów wierzchołków, 0 - wierzchołki
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//wiąże nazwany obiekt bufora
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//określa lokalizację i format danych tablicy atrybutów //definiuje tablicę atrybutów wierzchołków
	//identyfikator, ilość elementów, typ danych, normalizacja
	glPointSize(wielkoscPunktu);//glPointSize(10);//średnica zrastrowanych punktów
	glDrawArrays(GL_POINTS, 0, 4);//dopisana ilość rysowanych punktów
	glDisableVertexAttribArray(0);//wyłącza ogólną tablicę atrybutów wierzchołków
	glutSwapBuffers();
}

void Punkt::usun()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void Punkt::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);//odpowiada za stworzenie VAO, pierwszy to ilość
	std::cout << "VAO: " << VAO << std::endl;
	glBindVertexArray(VAO);
}

void Punkt::stworzenieVBO()
{//deklarujemy czteroelem. tablicę na zmienne typu GLfloat i wstawiamy do niej x y z
	//glm::vec3 Wierzcholki[4] = { glm::vec3(-0.5f, 0.0f, 0.0f),glm::vec3(0.0f, 0.5f, 0.0f) ,glm::vec3(0.5f, 0.0f, 0.0f) ,glm::vec3(0.0f, -0.5f, 0.0f) };
	glm::vec3 Wierzcholki[4] = {			//wspolrzedne x, y, z
		glm::vec3(-0.5f, 0.0f, 0.0f),		//Kwadrat - wierzcholki
		glm::vec3(0.0f, 0.5f, 0.0f),
		glm::vec3(0.5f, 0.0f, 0.0f),
		glm::vec3(0.0f, -0.5f, 0.0f)
		//glm::vec3(0.0f, 0.0f, 0.0f) //jeden punkt środkowy
	};// dopisane wierzchołki punktów
	glGenBuffers(1, &VBO);//generuje nam bufor
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//wiąże uchwyt bufora do celu (nazwy) //GL_ARRAY_BUFFER przechowuje dane wierzchołków
	std::cout << "VBO: " << VBO << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);//jakie dane i jakiej wielkości
}//GL_STATIC_DRAW - dane zmieniane raz i są używane wiele razy

void Punkt::sprawdzenieWersji()//po zainicj. glew możemy sprawdzić wersje glew
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

int main(int argc, char** argv)
{
	Punkt punkt(786, 786, 100, 100);

	punkt.stworzenieOkna(argc, argv);
	punkt.inicjalizacjaGlew();
	punkt.sprawdzenieWersji();
	punkt.stworzenieVAO();
	punkt.stworzenieVBO();
	glutDisplayFunc(punkt.wyswietl);
	glutCloseFunc(punkt.usun); //podczas zamykania okna wywołuje się metoda punkt.usun

	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	glClearColor(0.2f, 0.1f, 0.0f, 0.0f);

	glutMainLoop();

	return 0;
}
