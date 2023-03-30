#include "main.h"

#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <ctime>

#include "Plane.h"
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
float _cameraHandleAmplitude = 5;

float _lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
float _lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
float _lightEspecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
float _lightPosition[] = { 0.0f, 0.0f, 0.1f, 1.0f };

float _gray[] = { 0.6f, 0.6f, 0.6f, 1.0f };

bool _goingLeft = false, _goingRight = false, _goingDown = false, _goingUp = false;

float _xLight = 0;

// Exercise Variables

Plane _leftPlane(180);
Plane _rightPlane(180);

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
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, _lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, _lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, _lightEspecular);
	
	glLightfv(GL_LIGHT0, GL_POSITION, _lightPosition);

	//glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	//Cara, parametro, valor

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, _gray); 
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, _gray); 
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, _gray); 
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 60.0f); //0-128
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
		sin(static_cast<double>(_sliderHorizontal)) * static_cast<double>(_cameraHandleAmplitude), 0, cos(static_cast<double>(_sliderHorizontal)) * static_cast<double>(_cameraHandleAmplitude), //pos
		0.0f, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f); //up Vector

	_t = glutGet(GLUT_ELAPSED_TIME); //Obteniendo el tiempo y el delta
	_deltaTime = (_t - _old_t) / 1000.0f;
	_old_t = _t;
	
	_xLight += _deltaTime;
#pragma region Exercise
	_lightPosition[0] = sin(_xLight);
	glLightfv(GL_LIGHT0, GL_POSITION, _lightPosition);
	glPushMatrix();
		glTranslatef(-0.6f, 0, 0);
		_leftPlane.Draw();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.6f, 0, 0);
		_rightPlane.Draw();
	glPopMatrix();
	
#pragma endregion

	glutSwapBuffers(); //intercambia los búferes de la ventana actual si tiene doble búfer.
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
