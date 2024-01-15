
#include "identifyFunction.hpp"

int	main(void)
{
	Base *random;

	std::cout << "\033[1;33mGenerating Random A, B or C.... \033[0m" << std::endl;
	random = generate();
	identify(random);
	identify(*random);

	std::cout << "\033[1;33mTesting how it would behave with an Invalid Type.... \033[0m" << std::endl;
	random = NULL;
	identify(random);
	identify(*random);
}
