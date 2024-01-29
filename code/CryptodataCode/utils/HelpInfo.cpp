void printh()       //print information
{
    std::cout << "Welcome to cryptodata " << "\n";
    std::cout  << "\n";
    std::cout << "Compile: " << "\n";
    std::cout << "\tg++ main.cpp -o cryptodata " << "\n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "Excample: " << "\n\t" << "For Linux OS: ./cryptodata /media/user/usb/Alphabetsbase.txt -d --rf /example/encry.txt --wf /example/decry.txt" << "\n";
    std::cout << "\tFor Windows OS : ./cryptodata.exe /media/user/usb/Alphabetsbase.txt -d --rf /example/encry.txt --wf /example/decry.txt" << "\n";
    std::cout << "                                \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "  /media/user/Alphabetsbase.txt|    First argument  - path to Alphabetsbase, if your not have Alphabetsbase " << "\n";
    std::cout << "                               |    file, create her. The argument is required.       \n";
    std::cout << "--------------------------------------------------------------------------------------------------\n";
    std::cout << "        -d / -e                |    Second argument - action (-d - decryption, -e - encryption). " << "\n";
    std::cout << "                               |    The argument is required.  \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "        --rf                   |    Third argument  - read file for input text. The argument is not required." << "\n";
    std::cout << "                               |    The argument is required.  \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "  /home/Alphabets/input.txt    |    Fourth argument - path for read input text. If third argument written," << "\n";
    std::cout << "                               |    the argument is required.  \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "        --wf                   |    Fifth argument  - write file for output text. The argument is not required." << "\n";
    std::cout << "                               |    The argument is required.  \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "  /home/Alphabets/output.txt   |    Sixth argument  - path for write output text. If fifth argument written," << "\n";
    std::cout << "                               |    the argument is required.  \n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    std::cout << "          -h                   |    Seventh argument  - information command." << "\n";
    std::cout << "                               |    \n";
    std::cout << "--------------------------------------------------------------------------------------------------\n";
}

void printErr(char* arg){
    std::cout << "You not enter path to DB or not select action.  For getting information: " << arg << " -h " << std::endl;
    std::cout << "Example: " << arg << " /media/user/usb/Alphabetsbase.txt -d " << std::endl;
}
