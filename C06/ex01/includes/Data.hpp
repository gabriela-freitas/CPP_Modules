
#ifndef __DATA_HPP__
# define __DATA_HPP__

#include <iostream>

class Data {
	public:
		Data();
		Data(const Data&);
		~Data();
		Data&	operator= (const Data&); // const for safety... not super nesessary

		int a;
		std::string str;
		float b;
};
std::ostream&	operator<<(std::ostream&, const Data&);
#endif
