#ifndef __GROVER_SDL2_WINDOW_HPP__
#define __GROVER_SDL2_WINDOW_HPP__

#include"error.hpp"
#include"config.hpp"
#include<SDL2/SDL.h>
#include<string>
#include<memory>
#include<utility>

namespace grover
{
	class Window
	{
		SDL_Window* raw{};
	public:
		Window() {}
		Window(
			const char* title,
			int x = config::window::x,
			int y = config::window::y,
			int width = config::window::width,
			int height = config::window::height,
			int flags = config::window::flags
		)
		{
			raw = SDL_CreateWindow(
				title,
				x,
				y,
				width,
				height,
				flags
			);
		}
		bool is_valid() const
		{
			return raw != nullptr;
		}
	};
	template<typename... Args>
	std::unique_ptr<BaseResult> CreateWindow(Args... args)
	{
		auto window = Window(std::forward<Args>(args)...);
		if(!window.is_valid())
		{
			std::string errormessage = SDL_GetError();
			return std::make_unique<Result<int>>(Result{
				Error{ grover::FAILED_WINDOW_CREATION, errormessage.length() > 0 ? errormessage : "Grover faild to create window." },
				-1
			});
		}
		return std::make_unique<Result<Window>>(Result{
			Error{ grover::OK, "" },
			window
		});
	}
}

#endif
