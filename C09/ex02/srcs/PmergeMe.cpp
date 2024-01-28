
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// TODO (default constructor)
}
PmergeMe::PmergeMe(const PmergeMe& param) {
	// TODO (copy constructor)
	(void)param;
}
PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe" << " destroyed" << std::endl;
	// TODO (destructor)
}
PmergeMe& PmergeMe::operator= (const PmergeMe& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const PmergeMe& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}

