#pragma once

#include <iostream>
#include <exception>


class StackOverFlowException : public std::exception
{
private:
	const char* error;
	// TODO: possibly add stack trace
public:
	StackOverFlowException(const char* _error);
	~StackOverFlowException();
	virtual const char* what() const throw()
	{
		std::string ret;
		ret = "StackOverFlowException: ";
		ret += error;
		return ret.c_str();
	}
};

