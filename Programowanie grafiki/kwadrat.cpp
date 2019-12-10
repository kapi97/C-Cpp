#include "kwadrat.h"


Kwadrat::Kwadrat()
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Kwadrat::Kwadrat(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Kwadrat::~Kwadrat()
{
	//std::cout << "Destruktor";
}

void Kwadrat::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	//glewExperimental = GL_TRUE;
	//glutInitContextVersion(3,3);
	//glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Kwadrat");
}

void Kwadrat::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		system("pause");
		exit(1);
	}
}

void  Kwadrat::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glPointSize(wielkoscPunktu);

	//glDrawArrays(GL_TRIANGLES, 0, 4); //co rysuje, pierwszy element tablicy, ile punktów rysuje (ilość wierzchołków)
	//wychodzi trójkąt prostokątny

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);	//Kwadrat	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);//Trójkąt
	//glDrawArrays(GL_TRIANGLE_FAN, 0, 4);  //glDrawArrays(GL_TRIANGLE_FAN, 0, 3);//Trójkąt
											
	glDisableVertexAttribArray(0);
	glutSwapBuffers();
}

void Kwadrat::usun()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void Kwadrat::stworzenieVAO()
{

	glGenVertexArrays(1, &VAO);
	std::cout << "VAO: " << VAO << std::endl;
	glBindVertexArray(VAO);
}

void Kwadrat::stworzenieVBO()
{
	glm::vec3 Wierzcholki[4] = {			//wspolrzedne x, y, z
		glm::vec3(-0.5f, -0.5f, 0.0f),		//Kwadrat - wierzcholki
		glm::vec3(-0.5f, 0.5f, 0.0f),
		glm::vec3(0.5f, -0.5f, 0.0f),
		glm::vec3(0.5f, 0.5f, 0.0f)
	};
	/*glm::vec3 wierzcholek1 = glm::vec3(0.5f, 0.5f, 0.0f);
	glm::vec3 wierzcholek2 = glm::vec3(-0.5f, 0.5f, 0.0f);
	glm::vec3 wierzcholek3 = glm::vec3(-0.5f, -0.5f, 0.0f);
	glm::vec3 wierzcholek4 = glm::vec3(0.5f, -0.5f, 0.0f);
	glm::vec3 Wierzcholki[4] = { wierzcholek1, wierzcholek2, wierzcholek3, wierzcholek4 };
	*/
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	std::cout << "VBO: " << VBO << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

void Kwadrat::sprawdzenieWersji()
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}



int main(int argc, char** argv)
{

	Kwadrat kw(786, 786, 100, 100);

	kw.stworzenieOkna(argc, argv);
	kw.inicjalizacjaGlew();
	kw.sprawdzenieWersji();
	kw.stworzenieVAO();
	kw.stworzenieVBO();
	glutDisplayFunc(kw.wyswietl);
	glutCloseFunc(kw.usun);

	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
	//glClearColor(0.2f, 0.1f, 0.0f, 0.0f);
	glutMainLoop();

	return 0;
}