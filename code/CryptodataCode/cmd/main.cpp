#include "headers.h"

int main(int argc, char** argv)
{
    std::srand(time(NULL));

    Controller(processingArgs(argc,argv));
    return 0;
}
