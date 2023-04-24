#include "game_time.h"

#include <GL/freeglut.h>

namespace game
{
	float time::time_ = 0.0f;
	float time::old_time_ = 0.0f;
	float time::delta_time_ = 0.0f;

	void time::update()
	{
		time_ = static_cast<float>(glutGet(GLUT_ELAPSED_TIME)); //Obteniendo el tiempo y el delta
		delta_time_ = (time_ - old_time_) / 1000.0f;
		old_time_ = time_;
	}

	float time::get_delta_time()
	{
		return delta_time_;
	}

	float time::get_time()
	{
		return time_ / 1000.0f;
	}
}
