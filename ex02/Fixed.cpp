#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int asd) : _fixedPointValue(asd) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float asd) : _fixedPointValue(asd) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed Fixed::operator+(const Fixed& other) const{
    Fixed ret;
    ret.setRawBits(getRawBits() + other.getRawBits());
    return (ret);
}

Fixed Fixed::operator-(const Fixed& other) const{
    Fixed ret;
    ret.setRawBits(getRawBits() - other.getRawBits());
    return (ret);
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed ret;
    ret.setRawBits(getRawBits() * other.getRawBits());
    return (ret);
}

Fixed Fixed::operator/(const Fixed& other) const{
    Fixed ret;
    ret.setRawBits(getRawBits() / other.getRawBits());
    return (ret);
}

bool Fixed::operator>(const Fixed& other) {
    return(getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) {
    return(getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) {
    return(getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) {
    return(getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) {
    return(getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) {
    return(getRawBits() != other.getRawBits());
}

Fixed&	Fixed::operator++() {
    _fixedPointValue++;
    return (*this);
}

Fixed	Fixed::operator++(int) {
    Fixed ret(*this);
    operator++();
    return (ret);
}

Fixed&	Fixed::operator--() {
    _fixedPointValue--;
    return (*this);
}

Fixed	Fixed::operator--(int) {
    Fixed ret(*this);
    operator--();
    return (ret);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

float Fixed::toFloat() const {
        return (float)_fixedPointValue / (1 << _fractionalBits); 
}

Fixed const &min(Fixed const &a, Fixed const &b) {
	return Fixed::min(a, b);
}

Fixed const &max(Fixed const &a, Fixed const &b) {
	return Fixed::max(a, b);
}

