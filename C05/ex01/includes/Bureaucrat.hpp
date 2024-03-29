
#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__
#include <iostream>
#include "ex01.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		Bureaucrat();

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& param);
		~Bureaucrat();
		Bureaucrat&	operator= (const Bureaucrat&); // const for safety... not super nesessary
		std::string getName() const;
		int 	getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		bool	signForm(Form& f);
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
std::ostream&	operator<<(std::ostream&, const Bureaucrat&);
#endif

// Putting it all together, the what() function declaration is saying
// that it's a virtual function that returns a pointer to a constant
//  character (string), doesn't modify the object's state, and doesn't
//  throw any exceptions. It's intended to provide a human-readable
// description of the exception when an exception object is caught and
// its what() function is called.
