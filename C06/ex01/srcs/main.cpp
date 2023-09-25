
#include "ex01.hpp"
#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data *d = new Data();
	uintptr_t ptr;

	std::cout << "Before Serializer: " << d << std::endl;
	std::cout << *d;
	ptr = Serializer::serialize(d);
	std::cout << "After Serializer: " << ptr << std::endl;

	Data *other = Serializer::deserialize(ptr);
	std::cout << "Now deserializing: " << other << std::endl;
	std::cout << *other;
	delete other;
	
	return (0);
}
