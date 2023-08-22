#include "ShrubberyCreationForm.hpp"

#define tree "\n\
	oxoxoo    ooxoo\n\
  ooxoxo oo  oxoxooo\n\
 oooo xxoxoo ooo ooox\n\
 oxo o oxoxo  xoxxoxo\n\
  oxo xooxoooo o ooo\n\
    ooo\\oo\\  /o/o\n\
        \\  \\\\/ /\n\
         |   /\n\
         |  |\n\
         | D|\n\
         |  |\n\
         |  |\n\
  ______/____\\____"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 25, 5),
	_target("Default")
{
	std::cout << "Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 25, 5),
	_target(target)
{
	std::cout << _target + " " +this->getName() + " Created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& param):
	AForm("ShrubberyCreationForm", 25, 5),
	_target(param.getTarget())
{
	std::cout << _target + " " +this->getName() + " Created as copy" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm" << " destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& param) {
	if (this != &param)
		this->_target = param.getTarget();
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const ShrubberyCreationForm& param) {
	std::cout << param.getName() + + " " + param.getTarget() + ", ";
	if (param.getIsSigned())
		std::cout << "is signed";
	else
		std::cout << "is not signed";
	std::cout << " | Grade to execute: " << param.getGradeExecute();
	std::cout << " | Grade to sign: " << param.getGradeSign() << std::endl;
	return (s);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

// TODO: Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it
// You have to check that the form is signed and that the grade of the
// bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkRequirements(executor);
    std::string fileName = _target + "_shrubbery.txt";  // Use the appropriate extension
    std::fstream file(fileName.c_str(), std::ios::out); // Open for writing
	if (file.is_open())
	{
		file << tree << std::endl;
		file.close();
	}
	else
		std::cerr << "Error creating the file." << std::endl;
}

