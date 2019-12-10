#include "trojkat.h"

Trojkat::Trojkat()
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Trojkat::Trojkat(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Trojkat::~Trojkat()
{
	//std::cout << "Destruktor" << std::endl;
}

void Trojkat::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	//glutInitContextVersion(3, 3);
	//glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Trojkat");
}

void Trojkat::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		system("pause");
		exit(1);
	}
}


void  Trojkat::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//
	glFrontFace(GL_CW);//definiowanie przednich i tylnich wielokątów; będzie traktowane jako zwrócone przodem //domyślnie ustawione było na glFrontFace(GL_CCW);
	glCullFace(GL_FRONT);//lub glCullFace(GL_BACK); //określa, czy można wybierać przednie czy tylne wielokąty
	glEnable(GL_CULL_FACE);//włącza wybieranie przednich wielokątów
	//bez tych 3 też wyświetla się trójkąt
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glPointSize(wielkoscPunktu);

	glDrawArrays(GL_TRIANGLES, 0, 3);//Trójkąt

	glDisableVertexAttribArray(0); 

	glutSwapBuffers();
}

void Trojkat::usun()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void Trojkat::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	std::cout << "VAO: " << VAO << std::endl;
	glBindVertexArray(VAO);
}

void Trojkat::stworzenieVBO()
{
	glm::vec3 wierzcholek1 = glm::vec3(0.0f, 0.5f, 0.0f);
	glm::vec3 wierzcholek2 = glm::vec3(-0.5f, -0.5f, 0.0f);
	glm::vec3 wierzcholek3 = glm::vec3(0.5f, -0.5f, 0.0f);
	glm::vec3 Wierzcholki[3] = { wierzcholek1, wierzcholek2, wierzcholek3 };

	int n = 3;
	float a = 0;

	for (int i = 0; i < n; i++) {
		a = 0.5 * Wierzcholki[i][0] * Wierzcholki[(i + 1) % n][1] - Wierzcholki[(i + 1) % n][0] * Wierzcholki[i][1];
	}//Wierzcholki[i][0] = X, Wierzcholki[i][1] = Y

	if (a > 0) {
		std::cout << "Trojkat zwrocony przodem." << std::endl;
	}
	else if (a < 0) {
		std::cout << "Trojkat zwrocony tylem." << std::endl;
	}

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	std::cout << "VBO: " << VBO << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW); 
}

void Trojkat::sprawdzenieWersji()
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}


int main(int argc, char** argv)
{
	Trojkat Trojkat(786, 786, 100, 100);

	Trojkat.stworzenieOkna(argc, argv);
	Trojkat.inicjalizacjaGlew();
	Trojkat.sprawdzenieWersji();
	Trojkat.stworzenieVAO();
	Trojkat.stworzenieVBO();
	glutDisplayFunc(Trojkat.wyswietl);
	glutCloseFunc(Trojkat.usun);

	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glClearColor(0.2f, 0.1f, 0.0f, 0.0f);
	glutMainLoop();

	//system("pause");
	return 0;
}
