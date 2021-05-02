#ifndef __GROVER_SDL2_APPLICATION_CONFIG_HPP__
#define __GROVER_SDL2_APPLICATION_CONFIG_HPP__

#include<SDL2/SDL.h>

namespace grover::config
{
	constexpr auto subsystems{
		// SDL_INIT_AUDIO |
		// SDL_INIT_EVENTS |
		// SDL_INIT_GAMECONTROLLER |
		// SDL_INIT_HAPTIC |
		// SDL_INIT_JOYSTICK |
		// SDL_INIT_TIMER |
		SDL_INIT_VIDEO
	};
	constexpr auto version{
		SDL_version{2, 0, 12}
	};
	namespace renderer
	{
		constexpr auto normal{ 0u };
		constexpr auto software{ 1u };
		constexpr auto none{ 2u };
		constexpr auto which{
			normal
		};
		constexpr auto flags{
			SDL_RENDERER_ACCELERATED
		};
	}

	namespace window
	{
		constexpr auto width{ 1280u };
		constexpr auto height{ 720u };
		constexpr auto x{ 0u };
		constexpr auto y{ 0u };
		constexpr auto title{ "Grover" };
		constexpr auto flags{
			0
		};
	}
}

#endif//__GROVER_SDL2_APPLICATION_CONFIG_HPP__
