#include "headers.h"


int main(int argc, char** argv)
{
    if (argc==1)
    {
        std::cout << "You not enter name Alphabetsbase. For getting information: " << argv[0] <<  "-h" << std::endl;
        std::cout << "Example: " << argv[0] << " /media/user/usb/Alphabetsbase.txt " << std::endl;
        return 1;
    }
    if (std::string(argv[1])=="-h")
    {
        printh();
        return 0;
    }
    
    Alphabets::path = std::string(argv[1]);      
    std::srand(time(NULL));                 
    generator_frst();                       //generating first level
    generator_scnd();                       //generating second level
    Writer();                               //write Alphabets to file
    
    return 0;
}
