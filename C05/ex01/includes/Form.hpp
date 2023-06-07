
#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <iostream>

class Form {
	public:
		Form();
		Form(const std::string _name, const int _gradeExecute, const int _gradeSign);
		Form()
		Form(const Form&);
		~Form();
		Form&	operator= (const Form&); // const for safety... not super nesessary
	
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeExecute;
		const int _gradeSign;
};
std::ostream&	operator<<(std::ostream&, const Form&);
#endif