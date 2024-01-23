#include "InvalidInputExeception.hpp"

InvalidInputExeception::InvalidInputExeception(const std::string &message) : m_message(message) {}

InvalidInputExeception::InvalidInputExeception(const InvalidInputExeception &){};
InvalidInputExeception::~InvalidInputExeception() throw(){};

const char *InvalidInputExeception::what() const throw()
{
	return m_message.c_str();
}