#include <iostream>
#include <typeinfo>


int main() {
    typedef unsigned short USHORT;
    typedef unsigned int UINT;
    USHORT s;
    UINT i;
    std::cout << "Type of USHORT: " << typeid(s).name() << std::endl;
    std::cout << "Type of unsigned short: " << typeid(unsigned short).name() << std::endl;
    std::cout << "Type of UINT: " << typeid(i).name() << std::endl;
    std::cout << "Type of unsigned int: " << typeid(unsigned int).name() << std::endl;
    return 0;
}