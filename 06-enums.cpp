#include <iostream>

int main() {
    enum COLOR {RED, BLUE, GREEN, WHITE, BLACK};
    std::cout << "Color RED => " << RED << std::endl;
    std::cout << "Color BLUE => " << BLUE << std::endl;
    std::cout << "Color GREEN => " << GREEN << std::endl;
    std::cout << "Color WHITE => " << WHITE << std::endl;
    std::cout << "Color BLACK => " << BLACK << std::endl;
    enum DIRECTIONS {North = 100, Northeast, East = 200, Southeast,
     South = 300, Southwest, West = 400, Northwest};
    std::cout << "North => " << North << std::endl;
    std::cout << "Northeast => " << Northeast << std::endl;
    std::cout << "East => " << East << std::endl;
    std::cout << "Southeast => " << Southeast << std::endl;
    std::cout << "South => " << South << std::endl;
    std::cout << "Southwest => " << Southwest << std::endl;
    std::cout << "West => " << West << std::endl;
    std::cout << "Northwest => " << Northwest << std::endl;
    return 0;  
}