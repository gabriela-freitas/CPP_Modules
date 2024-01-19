
#pragma once
#include <iostream>
#include <stack>
#include <sstream>

class InvalidInputExeception : public std::exception
{
public:
	InvalidInputExeception(const std::string &message);
	~InvalidInputExeception() throw(){};
	const char *what() const throw();

private:
	std::string m_message;
};

double caculateRPNexpression(std::string input);
