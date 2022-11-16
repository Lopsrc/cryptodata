
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
    fin.open(path);                     //open file
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
    else
    {
        std::cout << ". File opening error, check the correct path. [Read database]" << '\n';
        exit(1);
    }
    for (size_t j = 0, k = 0, p = 0; j < 33; j++)
    {
        for (size_t i = 0; i < 5; i++, k++)
        {
            if (j < 10) {data::digitals_crypto[j][i]=buff4[k];}
            if (j < 26)
            {
                data::english_crypto[j][i]=buff[k];             //write to global data
                data::english_crypto_up[j][i]=buff2[k]; 
            }
            if(j < 33)  {data::symbols_crypto[j][i]=buff3[k]; }
        }
        if (j < 10)
        {
            for (size_t i = 0; i < 3; i++)
            {
                for (size_t l = 0; l < 2; l++, p++)
                {
                    data::fst_[j][i][l]  = buff5[p];              //write to global data
                    data::snd_[j][i][l]  = buff6[p];
                    data::thrd_[j][i][l] = buff7[p];
                }
            }
        }
    }
    return 0;
}
int read_txt()                      //read data from a file
{
    std::string         txt;        //       local variables
    std::string         txt2;       //  for storing temporary values.
    std::ifstream       fin;        // create stream for reading data from a file.     
    fin.open(PTHS::PATHR);          //open file
    if(fin.is_open())
    {
        if (ST::action_c==1)        //for encryption
        {
            while (!(fin.eof()))
            {
                std::getline(fin, txt2);        //get value
                data::input_text+=txt2;         //write data from a file
                data::input_text+=data::keyw;   //add keyword
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
    else 
    {
        std::cout << ". File opening error, check the correct path.[Read text]" << '\n';
        exit(1);
    }
    return 0;
}
int write_txt()                         //write data to file
{
    int            size  =  strleny(data::text2);   
    std::ofstream  fout;                // create stream for write data to file. 
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
    else
    {
        std::cout << ". File opening error, check the correct path.[Output text]" << '\n';
        exit(1);
    }
    return 0;
}