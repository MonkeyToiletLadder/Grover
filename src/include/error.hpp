#ifndef __GROVER_ERROR_HPP__
#define __GROVER_ERROR_HPP__

#include<SDL2/SDL.h>
#include<string>
#include<memory>

#define GET_RESULT_DATA(T, X) dynamic_cast<grover::Result<T>*>(X)->get_data()

namespace grover
{
	constexpr auto OK{ 0u };
	constexpr auto FAILED_INIT{ 1u };
	constexpr auto FAILED_WINDOW_CREATION{ 2u };
	constexpr auto FAILED_MINIMUM_VERSION{ 3u };
	constexpr auto FAILED_RENDERER_CREATION{ 4u };

	struct Error
	{
		unsigned int code;
		std::string message;
		Error(unsigned int code, std::string message = "")
		{
			this->code = code;
			this->message = message;
		}
		Error(const Error& error)
		{
			code = error.code;
			message = error.message;
		}
	};

	class BaseResult
	{
		Error error;
	public:
		virtual ~BaseResult(){}
		BaseResult(Error error) : error{ error }
		{

		}
		unsigned int get_errorcode() const
		{
			return error.code;
		}
		std::string get_errormessage() const
		{
			return error.message;
		}
		operator int() const
		{
			return get_errorcode();
		}
	};
	template<typename T>
	class Result : public BaseResult
	{
		T data;
	public:
		Result(Error error, T data) : BaseResult{ error }
		{

		}
		T get_data()
		{
			return data;
		}
		static T into_data(std::unique_ptr<BaseResult>& result)
		{
			return dynamic_cast<Result<T>*>(result.get())->get_data();
		}
	};
}

#endif//__GROVER_ERROR_HPP__
