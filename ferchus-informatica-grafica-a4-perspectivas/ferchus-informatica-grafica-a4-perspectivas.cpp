#include <Windows.h>
#include <thread>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#define 	GLFW_KEY_1  49
#define 	GLFW_KEY_2  50
#define 	GLFW_KEY_3	51
#define 	GLFW_KEY_P_UPPERCASE	80
#define 	GLFW_KEY_P_LOWERCASE	112

using namespace std;

//Variables  para contar el tiempo
float t = 1, old_t = 1;
float dt = 0;
float rotationSpeed = 10;

int cameraDistanceMultiplier = 1;

bool isInPerspective = true;

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
	glBegin(GL_QUADS);
		float halfWidth = width / 2;
		float halfHeight = height / 2;

		glVertex3f(xPosition - halfWidth, yPosition - halfHeight, zPosition);
		glVertex3f(xPosition - halfWidth, yPosition + halfHeight, zPosition);
		glVertex3f(xPosition + halfWidth, yPosition + halfHeight, zPosition);
		glVertex3f(xPosition + halfWidth, yPosition - halfHeight, zPosition);
	glEnd();
}

void glTriangleIsoceles(float baseXPosition, float baseYPosition, float baseZPosition, float width, float height)
{
	glBegin(GL_TRIANGLES);
	float halfWidth = width / 2;

	glVertex3f(baseXPosition - halfWidth, baseYPosition, baseZPosition);
	glVertex3f(baseXPosition + halfWidth, baseYPosition, baseZPosition);
	glVertex3f(baseXPosition, baseYPosition + height, baseZPosition);
	glEnd();
}

void renderScene(void)
{
	// Limpia los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	// Reinicia las trasnformaciones
	glLoadIdentity();

	if (isInPerspective)
	{
		gluPerspective(45.0f, 1600 * 1.0 / 900, 0.1f, 100.0f);
	}

	else
	{
		int halfWidth = 8 * cameraDistanceMultiplier;

		int halfHeight = 4.5 * cameraDistanceMultiplier;

		glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight,//left,right,bottom,top
			1.0f, 1000.0f);
	}

	int cameraPos = 10 * cameraDistanceMultiplier;

	gluLookAt(
		0, 0, cameraPos, //pos
		0.0f, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f); //up Vector

	t = glutGet(GLUT_ELAPSED_TIME); //Obteniendo el tiempo y el delta
	dt = (t - old_t) / 1000.0f;
	old_t = t;
	
	glPushMatrix();

		glRotatef(rotationSpeed * t / 1000, 1, 1, 0);

		// Cúspide = (0, 2, -1)

		
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glBegin(GL_QUADS);

			// Green Square

			glColor3f(0, 1, 0);

			glVertex3f(-1, -1, 4);
			glVertex3f(1, -1, 4);
			glVertex3f(1, 1, 4);
			glVertex3f(-1, 1, 4);

			// Blue Square

			glColor3f(0, 0, 1);

			glVertex3f(-1, -1, -4);
			glVertex3f(1, -1, -4);
			glVertex3f(1, 1, -4);
			glVertex3f(-1, 1, -4);

			// Yellow Rectangle

			glColor3f(1, 1, 0);

			glVertex3f(-1, 1, 4);
			glVertex3f(1, 1, 4);
			glVertex3f(1, 1, -4);
			glVertex3f(-1, 1, -4);

			// Purple Rectangle

			glColor3f(1, 0, 1);

			glVertex3f(-1, -1, 4);
			glVertex3f(1, -1, 4);
			glVertex3f(1, -1, -4);
			glVertex3f(-1, -1, -4);

			// Orange Rectangle

			glColor3f(1, 0.5f, 0);

			glVertex3f(-1, 1, 4);
			glVertex3f(-1, -1, 4);
			glVertex3f(-1, -1, -4);
			glVertex3f(-1, 1, -4);

			// Red Rectangle

			glColor3f(1, 0, 0);

			glVertex3f(1, 1, 4);
			glVertex3f(1, -1, 4);
			glVertex3f(1, -1, -4);
			glVertex3f(1, 1, -4);


		glEnd();

	glPopMatrix();

	
	glutSwapBuffers(); //intercambia los búferes de la ventana actual si tiene doble búfer.
}

void processNormalKeys(unsigned char key, int x, int y)
{
	//cout << (int)key << endl;
	if (key == 27)
		exit(0);

	switch (key) // Positions
	{
		case GLFW_KEY_1:
			cameraDistanceMultiplier = 5;
			break;

		case GLFW_KEY_2:
			cameraDistanceMultiplier = 2;
			break;

		case GLFW_KEY_3:
			cameraDistanceMultiplier = 1;
			break;
	}

	if (key == GLFW_KEY_P_UPPERCASE)
	{
		isInPerspective = !isInPerspective;
	}

	if (key == GLFW_KEY_P_LOWERCASE)
	{
		isInPerspective = !isInPerspective;
	}
}

void InputDown(int key, int xx, int yy)
{
	switch (key)
	{
	case GLUT_KEY_UP://GLUT_KEY_UP:		
		break;
	}
}

void InputUp(int key, int xx, int yy)
{

	switch (key) {
	case GLUT_KEY_UP:
		break;
	}
}
#pragma endregion

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1600, 900); //dimensiones
	glutCreateWindow("TemplateWindow");
	glutFullScreen();
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

