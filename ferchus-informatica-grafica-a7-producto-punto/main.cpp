#include "main.h"

#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <ctime>

#include "Cube.h"
#include "Vector2.h"

using namespace std;

// Math

const float PI = 3.1416;
const float TAU = PI * 2;

// Variables  para contar el tiempo
float _t = 1, _old_t = 1;
float _deltaTime = 0;

// Other Variables
float _sliderHorizontal = 0;
float _sliderVertical = 0;

float _cameraRotationSpeed = 5;
float _cameraHandleAmplitude = 10;

bool _goingLeft = false, _goingRight = false, _goingDown = false, _goingUp = false;

// Exercise Variables

int _segments = 9;
int _amplitude = 1;

float _alpha = 1;
float _timeToComplete = 10;
float _lineLength = 2;
float _playerSpeed = 2;

Vector2 _spinningVector;
Vector2 _playerVector;

int main(int argc, char* argv[]) 
{
	srand(time(NULL));

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

void Initialization() 
{
	glClearColor(0, 0, 0, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void renderScene(void)
{
	// Limpia los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reinicia las trasnformaciones
	glLoadIdentity();

	if (_goingLeft) _sliderHorizontal -= _deltaTime * _cameraRotationSpeed;
	if (_goingRight) _sliderHorizontal += _deltaTime * _cameraRotationSpeed;
	if (_goingDown) _sliderVertical -= _deltaTime * _playerSpeed;
	if (_goingUp) _sliderVertical += _deltaTime * _playerSpeed;

	gluLookAt(
		sin(static_cast<double>(_sliderHorizontal)) * static_cast<double>(_cameraHandleAmplitude), 0, cos(static_cast<double>(_sliderHorizontal)) * static_cast<double>(_cameraHandleAmplitude), //pos
		0.0f, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f); //up Vector

	_t = glutGet(GLUT_ELAPSED_TIME); //Obteniendo el tiempo y el delta
	_deltaTime = (_t - _old_t) / 1000.0f;
	_old_t = _t;

#pragma region Exercise

	glBegin(GL_LINES); // Spinning Line

		glColor3f(1, 1, 1);
		glVertex2f(0, 0);
		_spinningVector = Vector2(sin(((_t / 1000 / _timeToComplete) * TAU)) * _lineLength, cos(((_t / 1000 / _timeToComplete) * TAU)) * _lineLength);
		glVertex2f(_spinningVector._x, _spinningVector._y);

	glEnd();

	glBegin(GL_LINES); // Player Line

		glColor3f(1, 1, 1);
		glVertex2f(0, 0);
		_playerVector = Vector2(sin(((_sliderVertical) * TAU)) * _lineLength, cos(((_sliderVertical) * TAU)) * _lineLength);
		glVertex2f(_playerVector._x, _playerVector._y);

	glEnd();

	_alpha = (Vector2::DotProduct(_spinningVector.normalized(), _playerVector.normalized()) + 1) / 2;

	glBegin(GL_QUADS); // Square

		glColor4f(1, 0, 0, _alpha);

		glVertex3f(-0.5f, -0.5f, 0);
		glVertex3f(-0.5f, 0.5f, 0);
		glVertex3f(0.5f, 0.5f, 0);
		glVertex3f(0.5f, -0.5f, 0);
	
	glEnd();

#pragma endregion

	glutSwapBuffers(); //intercambia los búferes de la ventana actual si tiene doble búfer.
}

void DrawCircle(int segments, float amplitude)
{
	Color color(255, 0, 0);

	float x = 0;
	float circleStep = (1.0f / segments) * TAU;
	float colorStep = 255 / (segments / 3);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_FAN);

	glColor3ub(255, 255, 255);
	glVertex2f(0.0f, 0.0f);
	
	for (int i = 0; i <= (segments / 3) * 1; i++)
	{
		glColor3ub(color._r, color._g, color._b);

		color._r -= colorStep;
		color._g += colorStep;

		x += circleStep;
		glVertex2f(sin(x) * amplitude, cos(x) * amplitude);
	}

	for (int i = 0; i <= (segments / 3) * 2; i++)
	{
		glColor3ub(color._r, color._g, color._b);

		color._g -= colorStep;
		color._b += colorStep;

		x += circleStep;
		glVertex2f(sin(x) * amplitude, cos(x) * amplitude);
	}

	for (int i = 0; i <= segments; i++)
	{
		glColor3ub(color._r, color._g, color._b);

		color._b -= colorStep;
		color._r += colorStep;

		x += circleStep;
		glVertex2f(sin(x) * amplitude, cos(x) * amplitude);
	}

	glEnd();
}

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
	case GLUT_KEY_UP:
		_goingUp = true;
		break;
	case GLUT_KEY_DOWN:
		_goingDown = true;
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
	case GLUT_KEY_UP:
		_goingUp = false;
		break;
	case GLUT_KEY_DOWN:
		_goingDown = false;
		break;
	}
}
#pragma endregion
