#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <ctime>

#include "Cube.h"

using namespace std;

// Variables  para contar el tiempo
int _t = 1, _old_t = 1;
float _deltaTime = 0;

// Other Variables
float _sliderHorizontal = 0;
float _sliderVertical = 0;

float _cameraRotationSpeed = 5;
float _amplitude = 20;

bool _goingLeft = false, _goingRight = false;

// Exercise Variables

const int CUBE_AMOUNT = 3;

float scale = 0.5f;

Cube cubes[3];

Color red, blue, green;
Vector3 vectors[3];

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
	gluPerspective(45.0f, ratio, 0.1f, 10000.0f);

	// usa la matriz de modelos the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void Initialization() {
	cout << "Codigo inicial aqui" << endl;
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
		_goingRight = true;
		break;
	case GLUT_KEY_LEFT:
		_goingLeft = true;
		break;
	}
}

void InputUp(int key, int xx, int yy)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		_goingRight = false;
		break;
	case GLUT_KEY_LEFT:
		_goingLeft = false;
		break;
	}
}
#pragma endregion

void renderScene(void)
{
	// Limpia los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reinicia las trasnformaciones
	glLoadIdentity();

	if (_goingLeft) _sliderHorizontal -= _deltaTime * _cameraRotationSpeed;
	if (_goingRight) _sliderHorizontal += _deltaTime * _cameraRotationSpeed;

	gluLookAt(
		sin(static_cast<double>(_sliderHorizontal)) * static_cast<double>(_amplitude), 5, cos(static_cast<double>(_sliderHorizontal)) * static_cast<double>(_amplitude), //pos
		0.0f, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f); //up Vector

	_t = glutGet(GLUT_ELAPSED_TIME); //Obteniendo el tiempo y el delta
	_deltaTime = (_t - _old_t) / 1000.0f;
	_old_t = _t;

#pragma region Exercise


	for (int i = 0; i < CUBE_AMOUNT; i++)
	{
		cubes[i].Draw();

		glBegin(GL_LINES);

		glVertex3f(0, 0, 0);
		glVertex3f(vectors[i]._x, vectors[i]._y, vectors[i]._z);

		glEnd();
	}

#pragma endregion

	glutSwapBuffers(); //intercambia los búferes de la ventana actual si tiene doble búfer.
}

int main(int argc, char* argv[]) 
{
	srand(time(NULL));

	red = red.red();
	blue = blue.blue();
	green = green.green();

	cubes[0].SetColor(red);
	cubes[1].SetColor(green);
	cubes[2].SetColor(blue);

	for (int i = 0; i < CUBE_AMOUNT - 1; i++) // Player input
	{
		cout << "vectors[" << i << "]" << endl;
		cout << "Ingresa el valor x: ";
		cin >> vectors[i]._x;
		cout << "Ingresa el valor y: ";
		cin >> vectors[i]._y;
		cout << "Ingresa el valor z: ";
		cin >> vectors[i]._z;
		cout << endl;
	}

	vectors[2]._x = 1 * ((vectors[0]._y * vectors[1]._z) - (vectors[0]._z * vectors[1]._y));
	vectors[2]._y = -1 * ((vectors[0]._x * vectors[1]._z) - (vectors[0]._z * vectors[1]._x));
	vectors[2]._z = 1 * ((vectors[0]._x * vectors[1]._y) - (vectors[0]._y * vectors[1]._x));

	for (int i = 0; i < CUBE_AMOUNT; i++) // Set values
	{
		cubes[i].SetScale(scale);
		cubes[i].SetPosition(vectors[i]);
	}

#pragma region OpenGL Start Configuration

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

#pragma endregion

	return 1;
}

