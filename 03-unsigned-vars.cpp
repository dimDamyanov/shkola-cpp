#include <iostream>

int main() {
    short sa = 0;
    unsigned short sb = 0;
    int ia = 0;
    unsigned int ib = 0;
    long la = 0;
    unsigned long lb = 0;
    sa |= 1;
    sb |= 1;
    ia |= 1;
    ib |= 1;
    la |= 1;
    lb |= 1;
    for (int i=0;i<15;i++){
        sa <<= 1;
        sb <<= 1;
        sb |= 1;
    }
    for (int i=0;i<31;i++){
        ia <<= 1;
        ib <<= 1;
        ib |= 1;
    }
    for (int i=0;i<63;i++) {
        la <<= 1;
        lb <<= 1;
        lb |= 1;
    }
    std::cout << "signed short: " << sa <<'\n';
    std::cout << "unsigned short: "<< sb <<'\n';
    std::cout << "signed int: " << ia <<'\n';
    std::cout << "unsigned int: "<< ib <<'\n';
    std::cout << "signed long: "<< la <<'\n';
    std::cout << "unsigned long: "<< lb <<'\n';
    return 0;
}