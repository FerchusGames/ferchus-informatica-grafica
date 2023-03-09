#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <ctime>
#include "Pyramid.h"
#include "SceneConstants.h"

using namespace std;

//Variables  para contar el tiempo
int _t = 1, _old_t = 1;
float _dt = 0;

// Camera Rotation
float _sliderHorizontal = 0;
float _sliderVertical = 0;
float _cameraRotationSpeed = 3;
float _amplitude = 50;

bool _goingLeft = false, _goingRight = false, _goingUp = false, _goingDown = false;

//Pyramid Parameters

float _speed = 5;
float _rotationSpeed = 120;
const int PYRAMID_AMOUNT = 10000;

void updatePosition(int i);
void checkNewPosition(int i);

Pyramid _pyramidArray[PYRAMID_AMOUNT];

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

void Initialization() // Start
{
	glutFullScreen();
}

void renderScene(void)
{
	// Limpia los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reinicia las trasnformaciones
	glLoadIdentity();

	gluLookAt(
		(sin(_sliderHorizontal) * _amplitude), (sin(_sliderVertical) * _amplitude), ((cos(_sliderVertical) * cos(_sliderHorizontal)) * _amplitude), //pos
		0.0f, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f); //up Vector

	for (int i = 0; i < PYRAMID_AMOUNT; i++)
	{
		glPushMatrix();	

			checkNewPosition(i);
			updatePosition(i);

			glTranslatef(
				_pyramidArray[i]._positionX,
				_pyramidArray[i]._positionY, 
				_pyramidArray[i]._positionZ
			);
			
			glRotatef(
				_pyramidArray[i]._initialRotation + _rotationSpeed * _t / 1000,
				_pyramidArray[i]._rotationX,
				_pyramidArray[i]._rotationY,
				_pyramidArray[i]._rotationZ
			);
			
			glScalef(_pyramidArray[i]._scale, _pyramidArray[i]._scale, _pyramidArray[i]._scale);
			
			_pyramidArray[i].drawPyramid();
		
		glPopMatrix();
	}

	_t = glutGet(GLUT_ELAPSED_TIME); //Obteniendo el tiempo y el delta
	_dt = (_t - _old_t) / 1000.0f;
	_old_t = _t;

	if (_goingLeft) _sliderHorizontal -= _dt * _cameraRotationSpeed;
	if (_goingRight) _sliderHorizontal += _dt * _cameraRotationSpeed;

	if (_goingDown) _sliderVertical -= _dt * _cameraRotationSpeed;
	if (_goingUp) _sliderVertical += _dt * _cameraRotationSpeed;

#pragma region Cube

	glLineWidth(1.0f);
	glPushMatrix();

		glScalef(CUBE_SCALE, CUBE_SCALE, CUBE_SCALE);

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
	glPopMatrix();

#pragma endregion

	glutSwapBuffers(); //intercambia los búferes de la ventana actual si tiene doble búfer.
}

void updatePosition(int i)
{
	_pyramidArray[i]._positionX = _pyramidArray[i]._positionX  + (_dt * _pyramidArray[i]._directionX * _speed);
	_pyramidArray[i]._positionY = _pyramidArray[i]._positionY  + (_dt * _pyramidArray[i]._directionY * _speed);
	_pyramidArray[i]._positionZ = _pyramidArray[i]._positionZ  + (_dt * _pyramidArray[i]._directionZ * _speed);
}

void checkNewPosition(int i)
{
	if (abs(_pyramidArray[i]._positionX + (_dt * _pyramidArray[i]._directionX) * _speed) > (CUBE_HITBOX - (_pyramidArray[i]._scale / 2)))
	{
		_pyramidArray[i]._directionX *= -1;
	}

	if (abs(_pyramidArray[i]._positionY + (_dt * _pyramidArray[i]._directionY) * _speed) > (CUBE_HITBOX - (_pyramidArray[i]._scale / 2)))
	{
		_pyramidArray[i]._directionY *= -1;
	}

	if (abs(_pyramidArray[i]._positionZ + (_dt * _pyramidArray[i]._directionZ) * _speed) > (CUBE_HITBOX - (_pyramidArray[i]._scale / 2)))
	{
		_pyramidArray[i]._directionZ *= -1;
	}
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

int main(int argc, char* argv[]) 
{
	srand(clock());

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

