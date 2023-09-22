
#ifndef __AFORM_HPP__
# define __AFORM_HPP__
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;
	public:
		virtual void	execute(Bureaucrat const & executor) const = 0;
		void			checkRequirements(Bureaucrat const & executor) const;
		AForm();
		AForm(std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm&);
		~AForm();
		AForm&			operator= (const AForm&);
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
				return "Exception: Grade is too high";
			}
		};
		class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException() throw() { }

			virtual const char* what() const throw() {
				return "Exception: Grade is too low";
			}
		};
		class FormNotSignedException : public std::exception {
		public:
			FormNotSignedException() throw() { }

			virtual const char* what() const throw() {
				return "Exception: The form you tried to execute is not signed";
			}
		};
};
std::ostream&	operator<<(std::ostream&, const AForm&);
#endif
