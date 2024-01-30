#include "MutantStack.hpp"
#include "testingUtils.hpp"
#include <vector>
#define SIZE 42

int main(void)
{
	std::srand(std::time(0));

	printBlue(" >> Generating the MutantStack");

	MutantStack<int> mStack;
	std::string mStackContent;

	// just making sure i can use push to add elements
	mStack.push(1024);
	mStackContent = containerToStr(seedContainerRandomNumbers(mStack, SIZE));
	std::cout << mStackContent << std::endl;

	printYellow(" >> Now Creating an identical Vector");
	std::vector<int> vector;
	std::string vectorContent;
	seedSecondContainer(mStack, vector);
	vectorContent = containerToStr(vector);

	printBlue(" >> Making sure their content is the same");
	if (!mStackContent.compare(vectorContent))
		printGreen("Their content is equal!!!");
	else
		printRed("Hmmm something is off");

	printBlue(" >> Making sure we can create and std::stack from MutantStack");
	std::stack<int> realStack(mStack);

	std::stringstream test;

	test << "realStack last element: " << realStack.top() << std::endl;
	test << "MutantStack last element: " << mStack.top();

	printGreen(test.str());

	return (0);
}
