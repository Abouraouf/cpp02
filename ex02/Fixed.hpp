#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8; // what is the static means

public:
    Fixed(); // Default constructor
    Fixed(const int asd); // Default constructor
    Fixed(const float asd); // Default constructor
    Fixed(const Fixed& other); // Copy constructor
    ~Fixed(); // Destructor

    Fixed& operator=(const Fixed& other); // Copy assignment operator

    Fixed operator-(const Fixed& other) const ;
    Fixed operator+(const Fixed& other) const ;
    Fixed operator*(const Fixed& other) const ;
    Fixed operator/(const Fixed& other) const ;
    
    
    bool operator>(const Fixed& other);
    bool operator<(const Fixed& other);
    bool operator>=(const Fixed& other);
    bool operator<=(const Fixed& other);
    bool operator==(const Fixed& other);
    bool operator!=(const Fixed& other);
    float toFloat() const;
    Fixed& operator++();
    Fixed operator++(int); // If you returned a reference (Fixed&) like prefix, you’d return the updated object, not the original.
    Fixed& operator--();
    Fixed operator--(int);
    
    
    int getRawBits(void) const;
    void setRawBits(int const raw);

    const static Fixed	&min(Fixed const &a, Fixed const &b);
	const static Fixed	&max(Fixed const &a, Fixed const &b);
};


std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);
Fixed const		&min(Fixed const &a, Fixed const &b);
Fixed const		&max(Fixed const &a, Fixed const &b);


#endif
