#include "headers.h"

int manage(std::string path)        //function for manage application
{
    std::string inputText;
    std::string outputText;
    Cryptography cryptography;
    cryptography.write_to_cache(path);
    if(ST::enter_wk==true)
    {
        std::cout << "Enter text: ";
        std::getline(std::cin, inputText);   //entering text using the keyboard  
        cryptography.Setter(&inputText);

    }
    else if(ST::enter_wk == false){
        inputText = read_txt();                     //reading text from a file
        cryptography.Setter(&inputText);
    }
    std::cout << cryptography.GetterIT() << std::endl;
    if      (ST::action_c==1)   {cryptography.encryption();}                   //encryption first level
    else if (ST::action_c==2)   {cryptography.decryption();}                   //decryption first level
    std::cout << cryptography.GetterOT() << std::endl;
    if (ST::enter_it == false)
    {
        outputText = cryptography.GetterOT();
        write_txt(outputText);                    //writing Alphabets to a file
    }
    else if (ST::enter_it == true)      //print in terminal
    {
        std::cout << "Output text:\n" << "Begin\n\n";
        printv(outputText);
        std::cout <<  "\nEnd\n";
    }
    return 0;
}

// int main(){
//     std::string path = "/home/serpc/project/cpp/cryptodata/code/utils/database.db";
//     Cryptography a("=D7.KLG>/{?!P\"KL^5xUOg W^SPBxU");
//     // Cryptography a("aaa");
//     std::cout << a.GetterIT() << std::endl;
//     a.write_to_cache(path);
//     a.decryption();
//     // a.encryption();
//     std::cout << a.GetterOT() << std::endl;
// }
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
        // PTHS::PATH = std::string(argv[1]);          //add path Alphabets base 
        // write_to_cache(PTHS::PATH);                 //include Alphabets base
        if(std::string(argv[2])=="-e")  ST::action_c = 1;                       //variable that stores the state(-e - encryption (=1))
        if(std::string(argv[2])=="-d")  ST::action_c = 2;
        
        if (argc == 5)
        {
            if((std::string(argv[3])=="--wf"))
            {   
                PTHS::PATHW = std::string(argv[4]);     //path for writing a Alphabets from file
                ST::enter_it = false;
            }
            if((std::string(argv[3])=="--rf"))
            {   
                PTHS::PATHR = std::string(argv[4]);     //path for reading a Alphabets from file
                ST::enter_wk = false;
            }
            
        }
        else if (argc == 7)
        {
            if((std::string(argv[3])=="--rf"))
            {   
                PTHS::PATHR = std::string(argv[4]);     //path for reading a Alphabets from file
                ST::enter_wk = false;
            }
            if(std::string(argv[5])=="--wf")
            {
                PTHS::PATHW = std::string(argv[6]);     //path for write Alphabets to file
                ST::enter_it = false;
            }
        }
        

        return manage(std::string(argv[1]));
    }
    return 1;
}
