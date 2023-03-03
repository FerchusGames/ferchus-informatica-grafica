#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include "Pyramid.h"

using namespace std;

//Variables  para contar el tiempo
int _t = 1, _old_t = 1;
float _dt = 0;

//Other Variables
float sliderHorizontal = 0;
float sliderVertical = 0;
float amplitude = 5;
float rotationSpeed = 1;

bool goingLeft = false, goingRight = false, goingUp = false, goingDown = false;

#pragma region OpenGLSetupInputAndStuff

void changeWindowSize(int w, int h)
{
	cout << "redim" << endl;
	// Previene una división por cero, cuando la ventana es demasiado corta
	// (no puede haber ventana con 0 de ancho).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Usa la matriz de proyección
	glMatrixMode(GL_PROJECTION);

	// Reinicia Matriz
	glLoadIdentity();

	// Hace que el Viewport use toda la pantalla
	glViewport(0, 0, w, h);

	// da la perspectiva correcta, fov, ratio, nearClip, farClip
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// usa la matriz de modelos the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void Initialization() {
	cout << "Codigo inicial aqui" << endl;
}

void glRectangle(float xPosition, float yPosition, float zPosition, float width, float height)
{
	float halfWidth = width / 2;
	float halfHeight = height / 2;

	glVertex3f(xPosition - halfWidth, yPosition - halfHeight, zPosition);
	glVertex3f(xPosition - halfWidth, yPosition + halfHeight, zPosition);
	glVertex3f(xPosition + halfWidth, yPosition + halfHeight, zPosition);
	glVertex3f(xPosition + halfWidth, yPosition - halfHeight, zPosition);
}

void glTriangleIsoceles(float baseXPosition, float baseYPosition, float baseZPosition, float width, float height)
{
	float halfWidth = width / 2;

	glVertex3f(baseXPosition - halfWidth, baseYPosition, baseZPosition);
	glVertex3f(baseXPosition + halfWidth, baseYPosition, baseZPosition);
	glVertex3f(baseXPosition, baseYPosition + height, baseZPosition);
}

void renderScene(void)
{
	// Limpia los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reinicia las trasnformaciones
	glLoadIdentity();

	gluLookAt(
		(sin(sliderHorizontal) * amplitude), (sin(sliderVertical) * amplitude), ((cos(sliderVertical) * cos(sliderHorizontal)) * amplitude), //pos
		0.0f, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f); //up Vector

	system("cls");

	cout << "sliderHorizontal = " << sliderHorizontal << endl;
	cout << "Sin(sliderHorizontal) = " << sin(sliderHorizontal) << endl;
	cout << "Cos(sliderHorizontal) = " << cos(sliderHorizontal) << endl << endl;

	cout << "sliderVertical = " << sliderVertical << endl;
	cout << "Sin(sliderVertical) = " << sin(sliderVertical) << endl;
	cout << "Cos(sliderVertical) = " << cos(sliderVertical) << endl << endl;

	_t = glutGet(GLUT_ELAPSED_TIME); //Obteniendo el tiempo y el delta
	_dt = (_t - _old_t) / 1000.0f;
	_old_t = _t;

	if (goingLeft) sliderHorizontal -= _dt * rotationSpeed;
	if (goingRight) sliderHorizontal += _dt * rotationSpeed;

	if (goingDown) sliderVertical -= _dt * rotationSpeed;
	if (goingUp) sliderVertical += _dt * rotationSpeed;

#pragma region Cube

	glLineWidth(1.0f);

	glBegin(GL_LINE_STRIP); // Purple Top

		glColor3f(1, 0, 1);

		glVertex3f(-1, 1, 1);
		glVertex3f(1, 1, 1);
		glVertex3f(1, 1, -1);
		glVertex3f(-1, 1, -1);
		glVertex3f(-1, 1, 1);

	glEnd();

	glBegin(GL_LINE_STRIP); // Green Front

		glColor3f(0, 1, 0);

		glVertex3f(-1, 1, 1);
		glVertex3f(-1, -1, 1);
		glVertex3f(1, -1, 1);
		glVertex3f(1, 1, 1);
	
	glEnd();

	glBegin(GL_LINE_STRIP); // Red Left

		glColor3f(1, 0, 0);

		glVertex3f(-1, -1, 1);
		glVertex3f(-1, -1, -1);
		glVertex3f(-1, 1, -1);

	glEnd();

	glBegin(GL_LINE_STRIP); // Yellow Right

		glColor3f(1, 1, 0);

		glVertex3f(1, -1, 1);
		glVertex3f(1, -1, -1);
		glVertex3f(1, 1, -1);

	glEnd();

	glBegin(GL_LINE_STRIP); // Last Line

		glColor3f(1, 0, 0);

		glVertex3f(-1, -1, -1);
		glVertex3f(0, -1, -1);

		glColor3f(1, 1, 0);

		glVertex3f(1, -1, -1);

	glEnd();

	glBegin(GL_QUADS); // Base

		glColor3f(0.5f, 0.5f, 0.5f);

		glVertex3f(-1, -1, 1);
		glVertex3f(1, -1, 1);
		glVertex3f(1, -1, -1);
		glVertex3f(-1, -1, -1);

	glEnd();

#pragma endregion



	glutSwapBuffers(); //intercambia los búferes de la ventana actual si tiene doble búfer.
}

void processNormalKeys(unsigned char key, int x, int y)
{
	//cout << (int)key << endl;
	if (key == 27)
		exit(0);
}

void InputDown(int key, int xx, int yy)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		goingRight = true;
		break;
	case GLUT_KEY_LEFT:
		goingLeft = true;
		break;
	case GLUT_KEY_UP:
		goingUp = true;
		break;
	case GLUT_KEY_DOWN:
		goingDown = true;
		break;
	}
}

void InputUp(int key, int xx, int yy)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		goingRight = false;
		break;
	case GLUT_KEY_LEFT:
		goingLeft = false;
		break;
	case GLUT_KEY_UP:
		goingUp = false;
		break;
	case GLUT_KEY_DOWN:
		goingDown = false;
		break;
	}
}
#pragma endregion

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1600, 900); //dimensiones
	glutCreateWindow("TemplateWindow");
	Initialization();

	// register callbacks
	glutDisplayFunc(renderScene); //establece el callback de visualización para la ventana actual. 
	glutReshapeFunc(changeWindowSize); //establece el callback de redimensionado para la ventana actual
	glutIdleFunc(renderScene); //establece el callback global de inactividad.(si no recibe eventos, resize, etc)
	glutKeyboardFunc(processNormalKeys);//las teclas ASCII
	//glutKeyboardUpFunc(processNormalKeys); 
	glutSpecialFunc(InputDown); //teclas especiales
	glutSpecialUpFunc(InputUp); //teclas especiales al soltarse	

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// entrar GLUT al ciclo de procesamiento de eventos
	glutMainLoop();

	return 1;
}

