
#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__
#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer&);

	public:
		~Serializer();
		Serializer&	operator= (const Serializer&);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
