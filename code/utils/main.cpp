#include "headers.h"
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
int writef()
{
    std::ofstream fout;
    fout.open(Alphabets::path);      //open file
    if(fout.is_open())
    {
        for (size_t i = 0; i < 95; i++)
        {
            if ((i==26) || (i==52) || (i==85))
                fout << "\n";
            fout << Alphabets::ar[i];                    //write Alphabets first level
        }
        fout << "\n";
        for (size_t i = 0; i < 30; i++)
        {
            fout << Alphabets::buffer_frst[i][0];        //write Alphabets second level
            fout << Alphabets::buffer_frst[i][1];
        }
        fout << "\n";
        for (size_t i = 0; i < 30; i++)
        {
            fout << Alphabets::buffer_scnd[i][0];        //write Alphabets second level
            fout << Alphabets::buffer_scnd[i][1];
        }
        fout << "\n";
        for (size_t i = 0; i < 30; i++)
        {
            fout << Alphabets::buffer_thrd[i][0];        //write Alphabets second level
            fout << Alphabets::buffer_thrd[i][1];
        }
        fout.close();
    }
    else
    {
        std::cout << ". File opening error, check the correct path.[Read Alphabetsbase]" << '\n';
        exit(1);
    }
    return 0;
}
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
    writef();                               //write Alphabets to file
    
    return 0;
}
