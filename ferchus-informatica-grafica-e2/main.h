#pragma once

#include "block.h"

#include <Windows.h>
#include <thread>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>

#include "plane.h"
#include "cube.h"
#include "vector2.h"
#include "game_time.h"
#include "paddle.h"
#include "input.h"
#include "ball.h"
#include "block.h"

void change_window_size(int width, int height);

void initialization();

void process_normal_keys(unsigned char key, int x, int y);

void input_down(int key, int x, int y);

void input_up(int key, int x, int y);

void render_scene(void);

int main(int argc, char* argv[]);

void check_box_bounds();

void create_block_list(const vector2& grid_dimensions);

#pragma region Exercise



#pragma endregion