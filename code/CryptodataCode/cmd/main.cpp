#include "headers.h"
// TEST()


int main(int argc, char** argv)
{
    std::srand(time(NULL));
    Controller(processingArgs(argc,argv));
    // TEST(processingArgs(argc,argv));
    return 1;
}
