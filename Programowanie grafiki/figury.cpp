#include "figury.h"

Figury::Figury()
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Figury::Figury(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Figury::~Figury()
{
	//std::cout << "Destruktor" << std::endl;
}

void Figury::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	//glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Figury");
}

void Figury::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		system("pause");
		exit(1);
	}
}

void  Figury::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glPointSize(wielkoscPunktu);


	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);			//prostok¹t

	glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);			//kwadrat

	glDrawArrays(GL_TRIANGLES, 8, 3);				//trójk¹t

	glDrawArrays(GL_TRIANGLE_FAN, 11, 100);			//ko³o

	glDisableVertexAttribArray(0);
	glutSwapBuffers();
}

void Figury::usun()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void Figury::stworzenieVAO()
{

	glGenVertexArrays(1, &VAO);
	std::cout << "VAO: " << VAO << std::endl;
	glBindVertexArray(VAO);
}

void Figury::stworzenieVBO()
{
	glm::vec3 Wierzcholki[111] = { //wspó³rzêdne x, y, z //miejsca: 11 na trójk¹t, kwadrat i prostok¹t + 100 na ko³o

		glm::vec3(0.75f, 0.5f, 0.0f),		//prostok¹t
		glm::vec3(0.75f, 0.9f, 0.0f),
		glm::vec3(-0.75f, 0.5f, 0.0f),
		glm::vec3(-0.75f, 0.9f, 0.0f),

		glm::vec3(-0.75f, -0.7f, 0.0f),		//kwadrat
		glm::vec3(-0.75f, -0.45f, 0.0f),
		glm::vec3(-0.5f, -0.7f, 0.0f),
		glm::vec3(-0.5f, -0.45f, 0.0f),

		glm::vec3(-0.6f, 0.2f, 0.0f),		//trójk¹t
		glm::vec3(-0.85f, -0.2f, 0.0f),
		glm::vec3(-0.35f, -0.2f, 0.0f),

		glm::vec3(0.0f, 0.0f, 0.0f) 		//ko³o - œrodek
	};
	//sta³a matematyczna PI
	GLfloat podwojonePI = M_PI * 2.0f;//rysuje górn¹ i doln¹ po³owê ko³a, bez 2.0f rysuje górn¹ czêœæ
	float promien = 0.25;
	for (int i = 11; i < 111; i++) {//ko³o zaczyna siê od 11 elementu (GL_TRIANGLE_FAN, 11, 100), potrzebnych jest ok. 100 miejsc na ko³o, ³¹cznie jest 111 wierzcho³ków
		Wierzcholki[i][0] += promien * cos(i * podwojonePI / 100);//X
		Wierzcholki[i][1] += promien * sin(i * podwojonePI / 100);//Y
		//dzielone przez liczbê wierzcho³ków/boków, przedzia³ ko³a od ok. 30 i do ok. 100; bez plusa te¿ dzia³a; cos-sin lub sin-cos
	}//Wierzcholki[i][0] = X, Wierzcholki[i][1] = Y


	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	std::cout << "VBO: " << VBO << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

void Figury::sprawdzenieWersji()
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}


int main(int argc, char** argv)
{
	Figury fig(600, 600, 450, 50);

	fig.stworzenieOkna(argc, argv);
	fig.inicjalizacjaGlew();
	fig.sprawdzenieWersji();
	fig.stworzenieVAO();
	fig.stworzenieVBO();
	glutDisplayFunc(fig.wyswietl);
	glutCloseFunc(fig.usun);

	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
	//glClearColor(0.2f, 0.1f, 0.0f, 0.0f);
	glutMainLoop();

	return 0;
}
