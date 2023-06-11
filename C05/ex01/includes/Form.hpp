
#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <iostream>
#include "ex01.hpp"
#include "Bureaucrat.hpp"

class Form {

	public:
		Form();
		Form(const std::string _name, const int _gradeExecute, const int _gradeSign);
		Form()
		Form(const Form&);
		~Form();
		Form&	operator= (const Form&); 
		std::string getName() const;
		int getGradeExecute() const;
		int getGradeSign() const;
		bool getIsSigned() const;
		
		class myException
		{
			public:
				virtual void message() const {
						std::cout << RED << "Exception: myException" << ENDC << std::endl;
				}
				virtual ~myException() {}
		};

		class GradeTooHighException: public myException
		{
			public:
				void message() const;
		};

		class GradeTooLowException: public myException
		{
			public:
				void message() const;
		};
		void beSigned(const Bureaucrat &b);
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeExecute;
		const int _gradeSign;
};
std::ostream&	operator<<(std::ostream&, const Form&);
#endif
