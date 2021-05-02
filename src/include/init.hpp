#ifndef __GROVER_SDL2_INIT_HPP__
#define __GROVER_SDL2_INIT_HPP__

#include"error.hpp"
#include"config.hpp"
#include<SDL2/SDL.h>
#include<string>
#include<memory>

// Renderer renderer{ nullptr };
// if(config::renderer::which == config::renderer::normal)
// {
// 	renderer = SDL_CreateRenderer(
// 		window,
// 		-1,
// 		config::renderer::flags
// 	);
// }
// if(!renderer)
// {
// 	std::string errormessage = SDL_GetError();
// 	return std::make_unique<Result<int>>(Result{
// 		Error{ grover::FAILED_RENDERER_CREATION, errormessage.length() > 0 ? errormessage : "Grover faild to create renderer." },
// 		-1
// 	});
// }

namespace grover
{
	class Handle
	{
	public:
		Handle() {}
		~Handle()
		{
			SDL_Quit();
		}
	};

	std::unique_ptr<BaseResult> init()
	{
		if(SDL_Init(config::subsystems) < 0)
		{
			std::string errormessage = SDL_GetError();
			return std::make_unique<Result<int>>(Result{
				Error{ grover::FAILED_INIT, errormessage.length() > 0 ? errormessage : "Grover failed to init SDL2." },
				-1
			});
		}
		SDL_version compiled;
		SDL_version linked;
		SDL_VERSION(&compiled);
		SDL_GetVersion(&linked);
		if(
			(int)linked.major < config::version.major ||
			(((int)linked.major <= config::version.major) && ((int)linked.minor < config::version.minor)) ||
			(((int)linked.major <= config::version.major) && ((int)linked.minor <= config::version.minor) && ((int)linked.patch < config::version.patch))
		)
		{
			std::string errormessage = SDL_GetError();
			return std::make_unique<Result<int>>(Result{
				Error{ grover::FAILED_MINIMUM_VERSION, errormessage.length() > 0 ? errormessage : "Grover failed minimum version requirement."  },
				-1
			});
		}
		return std::make_unique<Result<Handle>>(Result{
			Error{ grover::OK },
			Handle()
		});
	}
}

#endif//__GROVER_SDL2_INIT_HPP__
