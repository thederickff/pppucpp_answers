#include <iostream>

void getInput(const char* message);

int main()
{
    getInput("Enter a value and see what happens :)");
    
    return 0;
}

void getInput(const char* message)
{
    std::cin.putback('.');
    double val;
    std::cout << message << std::endl;
    std::cin >> val;
    std::cout << val << std::endl;
    
}