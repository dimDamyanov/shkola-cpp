#include <iostream>
#include <typeinfo>

int main() {
    auto index = 3;
    auto multiple = 2.25F;
    auto rate = 500 / 3.0;
    std::cout << typeid(index).name() << std::endl;
    std::cout << typeid(multiple).name() << std::endl;
    std::cout << typeid(rate).name() << std::endl;
    return 0;
}