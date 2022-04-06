#include "headers.h"
void printh()
{
    std::cout << "\n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "Excample: " << "\n\t" << "generator /media/user/database.txt " << "\n";
    std::cout << "                                \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "  /media/user/database.txt     |    First argument  - path to database. The argument is required" << "\n";
    std::cout << "                               |\n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "          -h                   |    Second argument  - information command." << "\n";
    std::cout << "                               |    \n";
    std::cout << "--------------------------------------------------------------------------------------------------\n";

}
int writef()
{
    std::ofstream fout;
    fout.open(data::path);      //open file
    if(fout.is_open())
    {
        for (size_t i = 0; i < 95; i++)
        {
            if ((i==26) || (i==52) || (i==85))
                fout << "\n";
            fout << data::ar[i];                    //write data first level
        }
        fout << "\n";
        for (size_t i = 0; i < 30; i++)
        {
            fout << data::buffer_frst[i][0];        //write data second level
            fout << data::buffer_frst[i][1];
        }
        fout << "\n";
        for (size_t i = 0; i < 30; i++)
        {
            fout << data::buffer_scnd[i][0];        //write data second level
            fout << data::buffer_scnd[i][1];
        }
        fout << "\n";
        for (size_t i = 0; i < 30; i++)
        {
            fout << data::buffer_thrd[i][0];        //write data second level
            fout << data::buffer_thrd[i][1];
        }
        fout.close();
    }
    else
    {
        std::cout << ". File opening error, check the correct path.[Read database]" << '\n';
        exit(1);
    }
    return 0;
}
int main(int argc, char** argv)
{
    if (argc==1)
    {
        std::cout << "You not enter name database. For getting information: " << argv[0] <<  "-h" << std::endl;
        std::cout << "Example: " << argv[0] << " /media/user/usb/database.txt " << std::endl;
        return 1;
    }
    if (std::string(argv[1])=="-h")
    {
        printh();
        return 0;
    }
    
    data::path = std::string(argv[1]);      
    std::srand(time(NULL));                 
    generator_frst();                       //generating first level
    generator_scnd();                       //generating second level
    writef();                               //write data to file
    
    return 0;
}
