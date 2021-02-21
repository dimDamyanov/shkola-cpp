#include <iostream>

int main() {
    int a, b, c;
    a = 7;
    std::cout << "a= " << a << std::endl;
    std::cout << "b= " << b << std::endl;
    std::cout << "c= " << c << std::endl;
    b = c = a + 13;
    std::cout << "a= " << a << std::endl;
    std::cout << "b= " << b << std::endl;
    std::cout << "c= " << c << std::endl;
    return 0;
}