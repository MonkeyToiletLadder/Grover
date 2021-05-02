/*
*	Grover is a tile editor made with C++ and SDL2
*	TODO: Create a GUI
*	TODO: Create SDL2 window
*	TODO: Think of features
*	TODO: Think of modularity
*
*
*
*/
#include"init.hpp"
#include"window.hpp"
#include<SDL2/SDL.h>
#include<iostream>

int main()
{
	using grover::Result;
	using grover::Handle;
	using grover::Window;

	Handle handle;
	auto result = grover::init();
	switch(result->get_errorcode())
	{
	case grover::OK:
		handle = Result<Handle>::into_data(result);
		break;
	case grover::FAILED_INIT:
		std::cout << result->get_errormessage() << '\n';
		return 1;
	case grover::FAILED_MINIMUM_VERSION:
		std::cout << result->get_errormessage() << '\n';
		return 1;
	}

	Window window;
	result = grover::CreateWindow(
		grover::config::window::title
	);
	switch(result->get_errorcode())
	{
	case grover::OK:
		window = Result<Window>::into_data(result);
		break;
	case grover::FAILED_WINDOW_CREATION:
		std::cout << result->get_errormessage() << '\n';
		return 1;
	}
	return 0;
}
