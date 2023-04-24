#pragma once

#define delta_time game::time::get_delta_time()

namespace game
{
	class time
	{
	public:
		virtual ~time() = 0;

		static void update();
		static float get_delta_time();
		static float get_time();

	private:
		static float time_;
		static float old_time_;
		static float delta_time_;
	};
}

