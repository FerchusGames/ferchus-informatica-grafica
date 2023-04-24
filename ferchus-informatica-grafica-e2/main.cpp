#include "main.h"

constexpr float pi = 3.1416f;
constexpr float tau = pi * 2;

float camera_rotation_speed = 5;
float camera_handle_amplitude = 5;

float light_ambient[] = { 0.01f, 0.01f, 0.01f, 1.0f };
float light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
float light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
float light_position[] = { 0.0f, 0.0f, 0.1f, 1.0f };

float x_light = 0;

float block_border = 2.0f;
float block_gap = 0.05f;

vector2 block_grid_dimensions = vector2(5, 2);

vector2 wall_size = vector2(8.0f, 0.2f);
vector2 wall_limit = vector2(3.9f, 3.9f);

std::unique_ptr<paddle> player;
std::unique_ptr<ball> game_ball;
std::vector<std::unique_ptr<block>> block_grid;
plane walls[4];

// Exercise Variables

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

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color::red.to_array()); 
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color::blue.to_array()); 
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color::green.to_array()); 
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 60.0f); //0-128

	player = std::make_unique<paddle>(vector2(0.0f, -3.0f), 2.0f);
	game_ball = std::make_unique<ball>();
	create_block_list(block_grid_dimensions);

	walls[0] = plane(vector2(0, -wall_limit.y), vector2(wall_size.x, wall_size.y), color::blue);
	walls[1] = plane(vector2(0, wall_limit.y), vector2(wall_size.x, wall_size.y), color::blue);
	walls[2] = plane(vector2(-wall_limit.x, 0), vector2(wall_size.y, wall_size.x), color::blue);
	walls[3] = plane(vector2(wall_limit.x, 0), vector2(wall_size.y, wall_size.x), color::blue);

	light_position[2] = 2.0f;
}


void render_scene(void)
{
	game::time::update();

	// Limpia los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reinicia las transformaciones
	glLoadIdentity();

	gluLookAt(
		0, 0, 10, //pos
		0, 0, 0, //target
		0, 1, 0); //up Vector

#pragma region Exercise
	light_position[0] = game_ball->get_position().x;
	light_position[1] = game_ball->get_position().y;

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	for (auto& current_block : block_grid)
	{
		current_block->update();
	}

	game_ball->update();
	player->update();

	check_box_bounds();

	for (int i = 0; i < std::size(walls); i++)
	{
		walls[i].draw();
	}

	if (block::get_count() <= 0)
	{
		std::cout << "You Win" << std::endl;
	}

#pragma endregion

	glutSwapBuffers(); //intercambia los búferes de la ventana actual si tiene doble búfer.
}

#pragma region OpenGLSetupInputAndStuff

void change_window_size(const int width, int height)
{
	std::cout << "resize" << std::endl;
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
		input::set_horizontal_axis(1);
		break;
	case GLUT_KEY_LEFT:
		input::set_horizontal_axis(-1);
		break;
	case GLUT_KEY_UP:
		input::set_vertical_axis(1);
		break;
	case GLUT_KEY_DOWN:
		input::set_vertical_axis(-1);
		break;
	default: ;
	}
}

void input_up(const int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		input::set_horizontal_axis(0);
		break;
	case GLUT_KEY_LEFT:
		input::set_horizontal_axis(0);
		break;
	case GLUT_KEY_UP:
		input::set_vertical_axis(0);
		break;
	case GLUT_KEY_DOWN:
		input::set_vertical_axis(0);
		break;
	default: ;
	}
}
#pragma endregion

float get_border_gap()
{
	return (game_ball->get_scale().x / 2) + (wall_size.y / 2);
}

void check_box_bounds()
{
	if(game_ball->get_next_position().x < -wall_limit.x + get_border_gap()
		|| game_ball->get_next_position().x > wall_limit.x - get_border_gap())
	{
		game_ball->change_direction(true);
	}

	if (game_ball->get_next_position().y < -wall_limit.y + get_border_gap()
		|| game_ball->get_next_position().y > wall_limit.y - + get_border_gap())
	{
		game_ball->change_direction(false);
	}
}

void create_block_list(const vector2& grid_dimensions)
{
	const vector2 block_area = vector2(wall_limit.x * 2, wall_limit.y - block_border);

	const vector2 block_size = vector2(block_area.x / grid_dimensions.x - block_gap, block_area.y / grid_dimensions.y - block_gap);

	const vector2 block_distance = block_size + block_gap;

	const vector2 start_position = vector2(-wall_limit.x + block_size.x / 2 + block_gap / 2, 
	                                       block_border + block_size.y / 2 + block_gap / 2);

	for (int i = 0; i < static_cast<int>(grid_dimensions.x); i++)
	{
		for (int j = 0; j < static_cast<int>(grid_dimensions.y); j++)
		{
			vector2 block_position = vector2(start_position.x + block_distance.x * i + block_gap * i,
				start_position.y + block_distance.y * j + block_gap * j);

			block_grid.emplace_back(std::make_unique<block>(block_position, block_size));
		}
	}
}
