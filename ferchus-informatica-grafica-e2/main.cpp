#include "main.h"

#include <Windows.h>
#include <thread>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>

#include "plane.h"
#include "Cube.h"
#include "vector2.h"

using namespace std;

// Math

constexpr float pi = 3.1416f;
constexpr float tau = pi * 2;

// Variables  para contar el tiempo
float t = 1, old_t = 1;
float delta_time = 0;

// Other Variables
float slider_horizontal = 0;
float slider_vertical = 0;

float camera_rotation_speed = 5;
float camera_handle_amplitude = 5;

float light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
float light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
float light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
float light_position[] = { 0.0f, 0.0f, 0.1f, 1.0f };

float gray[] = { 0.6f, 0.6f, 0.6f, 1.0f };

bool going_left = false, going_right = false, going_down = false, going_up = false;

float x_light = 0;

// Exercise Variables

plane left_plane(180);
plane right_plane(180);

int main(int argc, char* argv[]) 
{
	srand(time(nullptr));

#pragma region OpenGL Start Configuration

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1600, 900); //dimensiones
	glutCreateWindow("TemplateWindow");
	initialization();

	// register callbacks
	glutDisplayFunc(render_scene); //establece el callback de visualización para la ventana actual. 
	glutReshapeFunc(change_window_size); //establece el callback de redimensionado para la ventana actual
	glutIdleFunc(render_scene); //establece el callback global de inactividad.(si no recibe eventos, resize, etc)
	glutKeyboardFunc(process_normal_keys);//las teclas ASCII
	//glutKeyboardUpFunc(process_normal_keys); 
	glutSpecialFunc(input_down); //teclas especiales
	glutSpecialUpFunc(input_up); //teclas especiales al soltarse	

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// entrar GLUT al ciclo de procesamiento de eventos
	glutMainLoop();

#pragma endregion

	return 1;
}

void initialization() 
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	//glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	//Cara, parametro, valor

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, gray); 
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gray); 
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, gray); 
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 60.0f); //0-128
}

void render_scene(void)
{
	// Limpia los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reinicia las transformaciones
	glLoadIdentity();

	if (going_left) slider_horizontal -= delta_time * camera_rotation_speed;
	if (going_right) slider_horizontal += delta_time * camera_rotation_speed;

	gluLookAt(
		sin(static_cast<double>(slider_horizontal)) * static_cast<double>(camera_handle_amplitude), 0, cos(static_cast<double>(slider_horizontal)) * static_cast<double>(camera_handle_amplitude), //pos
		0, 0, 0, //target
		0, 1, 0); //up Vector

	t = static_cast<float>(glutGet(GLUT_ELAPSED_TIME)); //Obteniendo el tiempo y el delta
	delta_time = (t - old_t) / 1000.0f;
	old_t = t;
	
	x_light += delta_time;
#pragma region Exercise
	light_position[0] = sin(x_light);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glPushMatrix();
		glTranslatef(-0.6f, 0, 0);
		left_plane.draw();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.6f, 0, 0);
		right_plane.draw();
	glPopMatrix();
	
#pragma endregion

	glutSwapBuffers(); //intercambia los búferes de la ventana actual si tiene doble búfer.
}

#pragma region OpenGLSetupInputAndStuff

void change_window_size(const int width, int height)
{
	cout << "resize" << endl;
	// Previene una división por cero, cuando la ventana es demasiado corta
	// (no puede haber ventana con 0 de ancho).
	if (height == 0)
		height = 1;
	const double ratio = static_cast<double>(width) * 1 / static_cast<double>(height);

	// Usa la matriz de proyección
	glMatrixMode(GL_PROJECTION);

	// Reinicia Matriz
	glLoadIdentity();

	// Hace que el Viewport use toda la pantalla
	glViewport(0, 0, width, height);

	// da la perspectiva correcta, fov, ratio, nearClip, farClip
	gluPerspective(45, ratio, 0.1, 10000);

	// usa la matriz de modelos the ModelView
	glMatrixMode(GL_MODELVIEW);
}

void process_normal_keys(const unsigned char key, int x, int y)
{
	//cout << (int)key << endl;
	if (key == 27)
		exit(0);
}

void input_down(const int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		going_right = true;
		break;
	case GLUT_KEY_LEFT:
		going_left = true;
		break;
	case GLUT_KEY_UP:
		going_up = true;
		break;
	case GLUT_KEY_DOWN:
		going_down = true;
		break;
	default: ;
	}
}

void input_up(const int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		going_right = false;
		break;
	case GLUT_KEY_LEFT:
		going_left = false;
		break;
	case GLUT_KEY_UP:
		going_up = false;
		break;
	case GLUT_KEY_DOWN:
		going_down = false;
		break;
	default: ;
	}
}
#pragma endregion
