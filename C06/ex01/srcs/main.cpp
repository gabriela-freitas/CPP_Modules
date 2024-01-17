
#include "Data.hpp"
#include "Serializer.hpp"
#include <sstream>

int	main(void)
{
	Data d;
	uintptr_t ptr;
	std::stringstream addr1;
	std::stringstream addr2;

	std::cout << "Before Serializer: " << &d << std::endl << d;
	ptr = Serializer::serialize(&d);
	d.str = "Another";
	addr1 << &d;
	std::cout << "After Serializer: " << ptr << std::endl;

	Data *other = Serializer::deserialize(ptr);
	addr2 << other;
	std::cout << "Now deserializing: " << other << std::endl << *other;

	if (!addr1.str().compare(addr2.str()))
	{
		std::cout << "\033[1;32m<< Adresses are equal >>\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[1;33m<< Adresses are not equal >>\033[0m" << std::endl;
	}
	return (0);
}
