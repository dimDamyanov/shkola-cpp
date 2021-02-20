#include <iostream>
#include <typeinfo>


int main() {
    typedef unsigned short USHORT;
    typedef unsigned int UINT;
    USHORT s;
    UINT i;
    std::cout << "Type of USHORT: " << typeid(int).name() << std::endl;
    std::cout << "Type of UINT: " << typeid(i).name() << std::endl;
    return 0;
}