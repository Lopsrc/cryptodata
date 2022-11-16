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
        encryption();                   //encryption first level
    else if (ST::action_c==2)
        decryption();                   //decryption first level
    if (ST::enter_it == false)
        write_txt();                    //writing data to a file
    
    else if (ST::enter_it == true)      //print in terminal
    {
        std::cout << "Output text:\n" << "Begin\n\n";
        printv();
        std::cout <<  "\nEnd\n";
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
    std::cout << "Excample: " << "\n\t" << "For Linux OS: ./cryptodata /media/user/usb/database.txt -d --rf /example/encry.txt --wf /example/decry.txt" << "\n";
    std::cout << "\tFor Windows OS : ./cryptodata.exe /media/user/usb/database.txt -d --rf /example/encry.txt --wf /example/decry.txt" << "\n";
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

void printErr(char* arg){
    std::cout << "You not enter path to DB or not select action.  For getting information:" << arg << "-h  " << std::endl;
    std::cout << "Example: " << arg << " /media/user/usb/database.txt -d " << std::endl;
}

int main(int argc, char** argv)
{
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
        PTHS::PATH = std::string(argv[1]);          //add path data base 
        write_to_cache(PTHS::PATH);                 //include data base
        if(std::string(argv[2])=="-e")  ST::action_c = 1;                       //variable that stores the state(-e - encryption (=1))
        if(std::string(argv[2])=="-d")  ST::action_c = 2;
        
        if (argc == 5)
        {
            if((std::string(argv[3])=="--wf"))
            {   
                PTHS::PATHW = std::string(argv[4]);     //path for writing a data from file
                ST::enter_it = false;
            }
            if((std::string(argv[3])=="--rf"))
            {   
                PTHS::PATHR = std::string(argv[4]);     //path for reading a data from file
                ST::enter_wk = false;
            }
            
        }
        else if (argc == 7)
        {
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
        }
        

        return manage();
    }
    return 1;
}
