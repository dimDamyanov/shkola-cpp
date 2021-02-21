#include <iostream>

int main() {
    int x = 5, sum;
    sum = x++;
    std::cout << "x= " << x << std::endl;
    std::cout << "sum= " << sum << std::endl;
    x = 5;
    sum = ++x;
    std::cout << "x= " << x << std::endl;
    std::cout << "sum= " << sum << std::endl;
    return 0;
}