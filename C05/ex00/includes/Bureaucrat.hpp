
#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__
#include <iostream>

class Bureaucrat {

	private:
		const std::string _name;
		int _grade;

	public:
		class myException
		{
			public:
				void message() const;
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

		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();
		Bureaucrat&	operator= (const Bureaucrat&);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade(int amount);
		void decrementGrade(int amount);
};
std::ostream&	operator<<(std::ostream&, const Bureaucrat&);
#endif
