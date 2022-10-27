
#ifndef __FIXED_HPP__
# define __FIXED_HPP__
#include <iostream>
class Fixed {
	public:
		Fixed();
		Fixed(const Fixed&);
		~Fixed();
		Fixed&	operator= (const Fixed&); // const for safety... not super nesessary
	private:
		int _fixedNum;
		const static int _fractional_bits = 8;
};
std::ostream&	operator<<(std::ostream&, const Fixed&);
#endif
