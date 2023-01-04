#include "headers.h"

//Проверить в readfile корректность записи данных или работа с классами



int main(int argc, char** argv)
{
    std::cout << argc << std::endl;
    std::srand(time(NULL));
    if (argc==1)        //check input arguments
    {
        printErr(argv[0]);
        return 1;
    }
    else if (argc==2)
    {
        if (std::string(argv[1])=="-h")
        {
            printh();
            return 0;
        }
        else
        {
            printErr(argv[0]);
            return 1;
        }
    }
    else if (argc >= 3)
    {
        // PTHS::PATH = std::string(argv[1]);          //add path Alphabets base 
        // write_to_cache(PTHS::PATH);                 //include Alphabets base
        if(std::string(argv[2])=="-e")  ST::action_c = 1;                       //variable that stores the state(-e - encryption (=1))
        if(std::string(argv[2])=="-d")  ST::action_c = 2;
        
        if (argc == 5)
        {
            std::cout << 0001 << std::endl;
            if((std::string(argv[3])=="--wf"))
            {   
                PTHS::PATHW = std::string(argv[4]);     //path for writing a Alphabets from file
                ST::enter_it = 1;
            }
            if((std::string(argv[3])=="--rf"))
            {   
                PTHS::PATHR = std::string(argv[4]);     //path for reading a Alphabets from file
                ST::enter_wk = 1;
            }
            
        }
        else if (argc == 7)
        {
            std::cout << "seven" << std::endl;
            
            if((std::string(argv[3])=="-rf")||(std::string(argv[5])=="-wf"))
            {   
                std::cout << "Неккоректный флаг --rf  или --wf" << std::endl;
            }
            if((std::string(argv[3])=="--rf"))
            {   
                std::cout << "rf" << std::endl;
                PTHS::PATHR = std::string(argv[4]);     //path for reading a Alphabets from file
                ST::enter_wk = 1;
            }
            if(std::string(argv[5])=="--wf")
            {
                std::cout << "wf" << std::endl;
                PTHS::PATHW = std::string(argv[6]);     //path for write Alphabets to file
                ST::enter_it = 1;
            }
        }
        
        return Controller(std::string(argv[1]));
    }
    return 1;
}
