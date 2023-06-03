
#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <iostream>

class Form {
	public:
		Form();
		Form(const Form&);
		~Form();
		Form&	operator= (const Form&); // const for safety... not super nesessary
};
std::ostream&	operator<<(std::ostream&, const Form&);
#endif
