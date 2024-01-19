
#include "RPN.hpp"

InvalidInputExeception::InvalidInputExeception(const std::string &message) : m_message(message) {}

const char *InvalidInputExeception::what() const throw()
{
	return m_message.c_str();
}

static double operation(double a, double b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '/':
		if (b == 0)
			throw(InvalidInputExeception("Invalid divide by 0"));
		return a / b;
	case '*':
		return a * b;
	default:
		std::stringstream ss;
		ss << "Invalid token: " << op;
		throw InvalidInputExeception(ss.str());
		break;
	}
}

double caculateRPNexpression(std::string input)
{
	std::stack<double> stack;

	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if (isspace(*it))
			continue;
		if (isdigit(*it))
		{
			stack.push(*it - '0');
			continue;
		}
		if (stack.size() < 2)
			throw InvalidInputExeception("Invalid equation");
		double b = stack.top();
		stack.pop();
		double a = stack.top();
		stack.pop();
		stack.push(operation(a, b, *it));
	}
	if (stack.size() != 1)
		throw InvalidInputExeception("Invalid equation");
	return (stack.top());
}