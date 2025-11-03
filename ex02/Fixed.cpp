#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}


Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat() const {
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return this->_fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream &o, Fixed const &fixed) {
    o << fixed.toFloat();
    return o;
}


int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}



bool Fixed::operator>(const Fixed& other) const {
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const {
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const {
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const {
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const {
    return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const {
    return (this->getRawBits() != other.getRawBits());
}


Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long val1 = this->getRawBits();
    long long val2 = other.getRawBits();
    result.setRawBits((val1 * val2) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long long val1 = this->getRawBits();
    long long val2 = other.getRawBits();
    result.setRawBits((val1 << _fractionalBits) / val2);
    return result;
}

Fixed& Fixed::operator++() {
    this->_fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    operator++();     
    return (temp);   
}

Fixed& Fixed::operator--() {
    this->_fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    operator--();
    return (temp);
}


Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}
