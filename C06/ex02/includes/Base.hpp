
#ifndef __BASE_HPP__
# define __BASE_HPP__
#include <iostream>

class Base {
	public:
		virtual ~Base();
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
};

#endif
