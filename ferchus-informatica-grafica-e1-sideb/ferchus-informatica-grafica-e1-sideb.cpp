#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <ctime>

#include "Cube.h"

using namespace std;

//Variables  para contar el tiempo
int _t = 1, _old_t = 1;
float _deltaTime = 0;

const int COLUMNS = 3;
const int ROWS = 3;

float _spaceBetweenCubes = 1.2;

Cube _cubeGrid[COLUMNS][ROWS];

//Other Variables
float _sliderHorizontal = 0;
float _sliderVertical = 0;

float _cameraRotationSpeed = 5;
float _amplitude = 2.2;

bool _goingLeft = false, _goingRight = false;

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

void renderScene(void)
{
	// Limpia los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reinicia las trasnformaciones
	glLoadIdentity();

	if (_goingLeft) _sliderHorizontal -= _deltaTime * _cameraRotationSpeed;
	if (_goingRight) _sliderHorizontal += _deltaTime * _cameraRotationSpeed;

	gluLookAt(
		sin(_sliderHorizontal) * _amplitude, 0, cos(_sliderHorizontal) * _amplitude, //pos
		0.0f, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f); //up Vector

	_t = glutGet(GLUT_ELAPSED_TIME); //Obteniendo el tiempo y el delta
	_deltaTime = (_t - _old_t) / 1000.0f;
	_old_t = _t;

	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			_cubeGrid[i][j].MoveBackAndForth(_deltaTime);
			_cubeGrid[i][j].Draw();
		}
	}

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

int main(int argc, char* argv[]) 
{
	srand(time(NULL));

	_amplitude = (COLUMNS > ROWS ? COLUMNS : ROWS) * _amplitude;

	Cube cubeGrid[COLUMNS][ROWS];

	Vector3 startingPoint((_spaceBetweenCubes / -2) * (COLUMNS - 1), (_spaceBetweenCubes / -2) * (ROWS - 1), 0);

	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			_cubeGrid[i][j] = cubeGrid[i][j];
			Vector3 newPosition(startingPoint._x + _spaceBetweenCubes * i, startingPoint._y + _spaceBetweenCubes * j, 0);
			_cubeGrid[i][j].SetPosition(newPosition);
		}
	}

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

