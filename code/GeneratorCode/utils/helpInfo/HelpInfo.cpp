void printh()
{
    std::cout << "\n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "Excample: " << "\n\t" << "generator /media/user/Alphabetsbase.txt " << "\n";
    std::cout << "                                \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "  /media/user/Alphabetsbase.txt     |    First argument  - path to Alphabetsbase. The argument is required" << "\n";
    std::cout << "                               |\n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "          -h                   |    Second argument  - information command." << "\n";
    std::cout << "                               |    \n";
    std::cout << "--------------------------------------------------------------------------------------------------\n";

}

void messageErrorOfTheInputArgs(char* argv){
    std::cout << "You not enter name Alphabetsbase. For getting information: " << argv <<  "-h" << std::endl;
    std::cout << "Example: " << argv << " /media/user/usb/Alphabetsbase.txt " << std::endl;
}