
#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm&);
		~PresidentialPardonForm();
		PresidentialPardonForm&	operator= (const PresidentialPardonForm&); // const for safety... not super nesessary
		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};
std::ostream&	operator<<(std::ostream&, const PresidentialPardonForm&);
#endif
