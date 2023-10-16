
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	Base *random;
	Base obj;

	random = obj.generate();
	obj.identify(random);
	obj.identify(*random);

	A a;
	obj.identify(a);
}
