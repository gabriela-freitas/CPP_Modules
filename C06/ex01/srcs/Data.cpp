#include "Data.hpp"

Data::Data():
a(123),str("Helloo"), b(2.333){}

std::ostream& operator<<(std::ostream& s, const Data& param) {
	s << "Data: "<< param.a << " " << param.str << " " << param.b << std::endl;
	return (s);
}
