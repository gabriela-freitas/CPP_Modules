
#ifndef __FORM_HPP__
# define __FORM_HPP__
#include <iostream>
#include "ex01.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExecute);
		Form(const Form&);
		~Form();
		Form&			operator= (const Form&);
		int				getGradeSign() const ;
		int				getGradeExecute() const ;
		bool			getIsSigned() const ;
		std::string		getName() const ;
		void			beSigned(Bureaucrat &b);

		// Excepion classes
		class GradeTooHighException : public std::exception {
		public:
			GradeTooHighException() throw() { }

			virtual const char* what() const throw() {
				return "Grade is too high";
			}
		};
		class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException() throw() { }

			virtual const char* what() const throw() {
				return "Grade is too low";
			}
		};
};
std::ostream&	operator<<(std::ostream&, const Form&);
#endif
