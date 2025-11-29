#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
	private:
		int number;
		static const int c = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed&);
		Fixed(const int value);
		Fixed(const float value);  
		Fixed& operator=(const Fixed&);
		int getRawBits(void) const;
    	void setRawBits(int const raw);
		float toFloat(void) const;
    	int toInt(void) const;
		friend std::ostream& operator<<(std::ostream& o, const Fixed& fixed);
	};
#endif