#include "InvalidInputExeception.hpp"

InvalidInputExeception::InvalidInputExeception(const std::string &message) : m_message(message) {}

const char *InvalidInputExeception::what() const throw()
{
	return m_message.c_str();
}