#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
    
    public:
    Fixed();                       
    Fixed(const int value);         
    Fixed(const float value);       
    Fixed(const Fixed& other);     
    ~Fixed();                       
    
    Fixed& operator=(const Fixed& other); 

   
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    
    Fixed& operator++();    // Pre-increment
    Fixed& operator--();    // Pre-decrement
    Fixed operator++(int);  // Post-increment
    Fixed operator--(int);  // Post-decrement

    static Fixed& min(Fixed &a, Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& min(Fixed const &a, Fixed const &b);
    static const Fixed& max(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream &o, Fixed const &fixed);

#endif
