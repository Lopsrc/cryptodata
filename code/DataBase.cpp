
int write_to_cache(std::string& path)   //write data to global variable
{
    char            buff[130];          //
    char            buff2[130];         //
    char            buff3[165];         //          local variables  
    char            buff4[50];          //                for
    char            buff5[60];          //      storing temporary values.
    char            buff6[60];          //
    char            buff7[60];          //
    std::ifstream   fin;                // create stream for reading data from a file.
    //fin.exceptions(std::ifstream::badbit | std::ifstream::failbit); //for correct exception handling.
    fin.open(path);             //open file
    if(fin.is_open())
    {
        
        fin.getline(buff, 131);     //
        fin.getline(buff2, 131);    //
        fin.getline(buff3, 166);    //      reading 
        fin.getline(buff4, 51);     //        data
        fin.getline(buff5, 61);     //
        fin.getline(buff6, 61);     //
        fin.getline(buff7, 61);     //
        fin.close();
    
    }
    else//(const std::exception& e)
    {
        std::cout << ". File opening error, check the correct path. [Read database]" << '\n';
        exit(1);
    }
    int  k = 0;
    for (size_t j = 0; j < 26; j++)
    {
        for (size_t i = 0; i < 5; i++)
        {
            data::english_crypto[j][i]=buff[k];             //write to global data
            k++;
        }
    }
    k = 0;
    for (size_t j = 0; j < 26; j++)
    {
        for (size_t i = 0; i < 5; i++)
        {
            data::english_crypto_up[j][i]=buff2[k];          //write to global data
            k++;
        }
    }
    k = 0;
    for (size_t j = 0; j < 33; j++)
    {
        for (size_t i = 0; i < 5; i++)
        {
            data::symbols_crypto[j][i]=buff3[k];             //write to global data
            k++;
        }
    }
    k = 0;
    for (size_t j = 0; j < 10; j++)
    {
        for (size_t i = 0; i < 5; i++)
        {
            data::digitals_crypto[j][i]=buff4[k];             //write to global data
            k++;
        }
    }
    k = 0;
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t l = 0; l < 2; l++)
            {
                data::fst_[i][j][l] = buff5[k];              //write to global data
                k++;
            }
        }
    }
    k = 0;
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t l = 0; l < 2; l++)
            {
                data::snd_[i][j][l] = buff5[k];              //write to global data
                k++;
            }
        }
    }
    k = 0;
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t l = 0; l < 2; l++)
            {
                data::thrd_[i][j][l] = buff5[k];             //write to global data
                k++;
            }
        }
    }
    return 0;
}
int read_txt()                          //read data from a file
{
    std::string         txt;      //       local variables
    std::string         txt2;     //  for storing temporary values.
    std::ifstream       fin;      // create stream for reading data from a file.     
    //fin.exceptions(std::ifstream::badbit | std::ifstream::failbit); //for correct exception handling.
    fin.open(PTHS::PATHR);          //open file
    if(fin.is_open())
    {
        
        if (ST::action_c==1)            //for encryption
        {
            while (!(fin.eof()))
            {
                std::getline(fin, txt2);    //get value
                data::input_text+=txt2;     //write data from a file
                data::input_text+=data::keyw; //add keyword
            }
        }
        if (ST::action_c==2)            //for encryption
        {
            while (!(fin.eof()))
            {
                std::getline(fin,txt2);     //get value
                data::input_text+=txt2;     //write data from a file
            }
        }
        fin.close();                    
    }
    else //(const std::exception& e)
    {
        std::cout << ". File opening error, check the correct path.[Read text]" << '\n';
        exit(1);
    }
    return 0;
}
int write_txt()                         //write data to file
{
    int            size  =  strleny(data::text2);   
    std::ofstream  fout;    // create stream for write data to file. 
    //fout.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    fout.open(PTHS::PATHW);
    if(fout.is_open())
    {
        
        for (size_t i = 0; i < size; i++)
        {
            if (data::text2[i]==data::keyw[0])
            {
                if (data::text2[i+1]==data::keyw[1])
                {
                    if (data::text2[i+2]==data::keyw[2])
                    {
                        if (data::text2[i+3]==data::keyw[3])
                        {
                            fout << "\n";
                            i+=3;
                            continue;
                        }
                    }
                }
            }
            fout << data::text2[i]; //write data to file
        }
        fout.close();
    }
    else//(const std::exception& e)
    {
        std::cout << ". File opening error, check the correct path.[Output text]" << '\n';
        exit(1);
    }
    return 0;
}