#include "headers.h"

int manage()        //function for manage application
{
    if(ST::enter_wk==true)
    {
        std::cout << "Enter text: ";
        std::getline(std::cin, data::input_text);   //entering text using the keyboard  
    
    }
    else if(ST::enter_wk == false)
        read_txt();                     //reading text from a file
    if (ST::action_c==1)
    {    
        std::cout << data::input_text << "\n";
        encryption();                   //encryption first level
    }
    else if (ST::action_c==2)
        decryption();                   //decryption first level
    if (ST::enter_it == false)
        write_txt();                    //writing data to a file
    
    else if (ST::enter_it == true)
    {
        std::cout << "Output text: \n";
        printv();
    }
    return 0;
}
void printh()       //print information
{
    std::cout << "Welcome to cryptodata " << "\n";
    std::cout  << "\n";
    std::cout << "Compile: " << "\n";
    std::cout << "\tg++ main.cpp -o cryptodata " << "\n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "Excample: " << "\n\t" << "For Linux OS: ./cryptodata /media/user/usb/database.txt -d --rf /home/data/input.txt --wf /home/data/output.txt" << "\n";
    std::cout << "\tFor Windows OS : ./cryptodata.exe /media/user/usb/database.txt -d --rf /home/data/input.txt --wf /home/data/output.txt" << "\n";
    std::cout << "                                \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "  /media/user/database.txt     |    First argument  - path to database, if your not have database " << "\n";
    std::cout << "                               |    file, create her. The argument is required.       \n";
    std::cout << "--------------------------------------------------------------------------------------------------\n";
    std::cout << "        -d / -e                |    Second argument - action (-d - decryption, -e - encryption). " << "\n";
    std::cout << "                               |    The argument is required.  \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "        --rf                   |    Third argument  - read file for input text. The argument is not required." << "\n";
    std::cout << "                               |    The argument is required.  \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "  /home/data/input.txt         |    Fourth argument - path for read input text. If third argument written," << "\n";
    std::cout << "                               |    the argument is required.  \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "        --wf                   |    Fifth argument  - write file for output text. The argument is not required." << "\n";
    std::cout << "                               |    The argument is required.  \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "  /home/data/output.txt        |    Sixth argument  - path for write output text. If fifth argument written," << "\n";
    std::cout << "                               |    the argument is required.  \n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    std::cout << "          -h                   |    Seventh argument  - information command." << "\n";
    std::cout << "                               |    \n";
    std::cout << "--------------------------------------------------------------------------------------------------\n";
}
int main(int argc, char** argv)
{
    std::srand(time(NULL));
    //check input arguments
    if (argc==1)
    {
        std::cout << "You not enter path to DB and not select action. For getting information: ./cryptodata -h" << std::endl;
        std::cout << "Example: " << argv[0] << " /media/user/usb/database.txt -d " << std::endl;
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
            std::cout << "You not enter path to DB or not select action.  For getting information: ./cryptodata -h" << std::endl;
            std::cout << "Example: " << argv[0] << " /media/user/usb/database.txt -d " << std::endl;
            return 1;
        }
        
    }
    else if (argc==3)
    {
        PTHS::PATH = std::string(argv[1]);          //write data from the local variables
        write_to_cache(PTHS::PATH);                 //include data base
        if(std::string(argv[2])=="-e")
            ST::action_c = 1;                       //variable that stores the state(-e - encryption (=1))
        if(std::string(argv[2])=="-d")
            ST::action_c = 2;
        manage();
    }
    else if (argc==5)
    {
        PTHS::PATH = std::string(argv[1]);          //write data from the local variables
        write_to_cache(PTHS::PATH);                 //include data base
        if(std::string(argv[2])=="-e")
            ST::action_c = 1;                       //variable that stores the state(-e - encryption (=1))
        if(std::string(argv[2])=="-d")
            ST::action_c = 2;
        if((std::string(argv[3])=="--wf"))
        {   
            PTHS::PATHW = std::string(argv[4]);     //path for reading a data from file
            ST::enter_it = false;
        }
        if((std::string(argv[3])=="--rf"))
        {   
            PTHS::PATHR = std::string(argv[4]);     //path for reading a data from file
            ST::enter_wk = false;
        }
        manage();
    }
    else
    {
        PTHS::PATH = std::string(argv[1]);          //write data from the local variables
        write_to_cache(PTHS::PATH);                 //include data base
        if(std::string(argv[2])=="-e")
            ST::action_c = 1;                       //variable that stores the state(-e - encryption (=1))
        if(std::string(argv[2])=="-d")
            ST::action_c = 2;                       //variable that stores the state(-d - decryption (=2))
    
        if((std::string(argv[3])=="--rf"))
        {   
            PTHS::PATHR = std::string(argv[4]);     //path for reading a data from file
            ST::enter_wk = false;
        }
        if(std::string(argv[5])=="--wf")
        {
            PTHS::PATHW = std::string(argv[6]);     //path for write data to file
            ST::enter_it = false;
        }
        manage();                                   //manage application
    }                      
    return 0;
}
