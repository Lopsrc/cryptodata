#include "headers.h"


int main(int argc, char** argv)
{
    std::srand(time(NULL));
    if(processingArgs(argc, argv)==1)
    {
        return 1;
    }
    Controller(std::string(argv[1]));

    return 0;
}
