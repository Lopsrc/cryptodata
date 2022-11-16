#include <iostream>

int main(){

    for (int i = 0, j = 0; i < 5; i++, j++)
    {
        std::cout << i << "\t" << j << std::endl;
    }
    std::cout << "-------------------------------------"<< std::endl;
    for (int i = 0, j = 0; i < 5; i++, j++)
    {
        std::cout << i << "\t" << j << std::endl;
    }
    return 0;
}