
#include "Data.hpp"
Data::Data():
	a(127),
	str("Hello World"),
	b(2.27f)
{
	std::cout << "Data Default Constructor called" << std::endl;
}

Data::Data(const Data& param):
	a(param.a),
	str(param.str),
	b(param.b)
{
	std::cout << "Data Copy Constructor called" << std::endl;
}

Data::~Data() {
	std::cout << "Data" << " destroyed" << std::endl;
}

Data& Data::operator= (const Data& param) {
	if (this != &param)
	{
		a = param.a;
		str = param.str;
		b = param.b;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const Data& param) {
	s << "Data: "<< param.a << " " << param.str << " " << param.b << std::endl;
	return (s);
}
