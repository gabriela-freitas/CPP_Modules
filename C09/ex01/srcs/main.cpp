#include "RPN.hpp"
#include "testingUtils.hpp"

void printResult(bool res)
{
	if (res)
		printGreen("Correct result!");
	else
		printRed("Hmm something is off");
}

double test(std::string equation)
{
	std::stringstream ss;
	double result;

	printGray("Equation input: " + equation);
	try
	{
		ss << "Result: ";
		result = caculateRPNexpression(equation);
		ss << result;
		printBlue(ss.str());
	}
	catch (std::exception &e)
	{
		printRed(e.what());
	}
	return result;
}

void test(std::string equation, double expectedResult)
{
	double result;

	result = test(equation);
	printResult(abs(result - expectedResult) < 0.00001);
}

int main(int ac, char **av)
{

	if (ac == 2)
	{
		printBlue(" >> Using input");
		test(av[1]);
		std::cout << std::endl;
	}

	printBlue(" >> Testing with some valid equations");
	test("3 4 + 5 6 * /", (3 + 4) / (5 * 6));
	test("3 4 + 5 *", (3 + 4) * 5);
	test("5 2 - 7 * 3 /", (5 - 2) * 7 / 3);
	test("4 2 / 3 + 6 *", ((4 / 2) + 3) * 6);
	test("2 3 * 5 4 * + 1 -", 2 * 3 + 5 * 4 - 1);
	test("9 2 / 3 * 4 -", ((9.0 / 2) * 3) - 4);

	std::cout << std::endl;
	printBlue(" >> Now, some invalid ones and wait for erros messages");
	test("3 + 4");
	test("3 4 + *");
	test("5 2 - 7 * /");
	test("4 2 / 3 + *");
	test("2 3 s* 5 4 + 1 -");
	test("2 3* 5 4 + 1 <");
	return (0);
}
