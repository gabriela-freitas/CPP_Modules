#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& param) {
	(void)param;
	std::cout << "Default constructor called" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Serializer" << " destroyed" << std::endl;
}

Serializer& Serializer::operator= (const Serializer& param) {
	(void)param;
	return (*this);
}

uintptr_t  Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
