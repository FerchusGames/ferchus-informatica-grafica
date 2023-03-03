#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>


using namespace std;

//Variables  para contar el tiempo
int _t = 1, _old_t = 1;
float _dt = 0;

//Other Variables
float slider = 0;
float amplitude = 10;
bool goingLeft = false, goingRight = false;

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
		(sin(slider) * amplitude), 0, (cos(slider) * amplitude), //pos
		0.0f, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f); //up Vector



	_t = glutGet(GLUT_ELAPSED_TIME); //Obteniendo el tiempo y el delta
	_dt = (_t - _old_t) / 1000.0f;
	_old_t = _t;

	if (goingLeft) slider -= _dt * 5;
	if (goingRight) slider += _dt * 5;

	glBegin(GL_QUADS); //unos Cuads chidos

	//glPushMatrix();

	// Left Top Squares

	glColor3f(1.0f, 0.0f, 0.0f);
	glRectangle(-5.0f, 3.0f, 0.0f, 0.5f, 0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glRectangle(-4.0f, 3.0f, 0.0f, 0.5f, 0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glRectangle(-3.0f, 3.0f, 0.0f, 0.5f, 0.5f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glRectangle(-2.0f, 3.0f, 0.0f, 0.5f, 0.5f);

	glEnd();

	// Middle Figure

	glBegin(GL_QUADS);

	glColor3f(0.8f, 0.8f, 0.8f);
	glRectangle(0.0f, 0.0f, 0.0f, 2.5f, 0.5f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.8f, 0.8f, 0.8f);
	glTriangleIsoceles(-0.85f, -0.25f, 0.0f, 0.8f, -0.4f);
	glTriangleIsoceles(0.85f, -0.25f, 0.0f, 0.8f, -0.4f);

	glEnd();

	// Right Figure

	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.0f, 1.0f, 1.0f);

	glVertex3f(2.0f, -0.25f, 0.0f); // First Point

	glVertex3f(2.0f, 1.0f, 0.0f); // Top Point
	glVertex3f(2.8f, 0.75f, 0.0f); // Right Top Point
	glVertex3f(3.2f, -0.25f, 0.0f); // Middle Point
	glVertex3f(2.8f, -1.25f, 0.0f); // Right Bottom Point
	glVertex3f(2.0f, -1.5f, 0.0f); // Bottom Point

	glEnd();

	//glPopMatrix();

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

