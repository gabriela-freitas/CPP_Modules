#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator= (const ShrubberyCreationForm&); // const for safety... not super nesessary
		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};
std::ostream&	operator<<(std::ostream&, const ShrubberyCreationForm&);
#endif
