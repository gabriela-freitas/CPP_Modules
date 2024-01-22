#pragma once

#include <iostream>

class InvalidInputExeception : public std::exception
{
public:
    InvalidInputExeception(const std::string &message);
    InvalidInputExeception(const InvalidInputExeception &){};
    ~InvalidInputExeception() throw(){};
    const char *what() const throw();

private:
    InvalidInputExeception(){};
    std::string m_message;
};