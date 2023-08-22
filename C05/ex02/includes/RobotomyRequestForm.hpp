#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm&);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator= (const RobotomyRequestForm&); // const for safety... not super nesessary
		std::string	getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};
std::ostream&	operator<<(std::ostream&, const RobotomyRequestForm&);
#endif
