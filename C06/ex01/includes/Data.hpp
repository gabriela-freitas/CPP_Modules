
#ifndef __DATA_HPP__
# define __DATA_HPP__

#include <iostream>

struct Data {
		Data();
		int a;
		std::string str;
		float b;
};

std::ostream&	operator<<(std::ostream&, const Data&);
#endif
