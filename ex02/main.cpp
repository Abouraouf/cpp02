#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat(); // convert Fixed to float for printing
    return os;
}

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
return 0;
}
