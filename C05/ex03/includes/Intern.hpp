
#ifndef __INTERN_HPP__
# define __INTERN_HPP__
#include <iostream>

class Aform;

class Intern {
	public:
		Intern();
		Intern(const Intern&);
		~Intern();
		Intern&	operator= (const Intern&); // const for safety... not super nesessary
		AForm*	makeForm(std::string formName, std::string target);
};

#endif
