
//Реализовать запись данных в кеш в виде класса WriteToCache

class Cryptography{
private:
    size_t              size;
    std::string         path;

    std::string         inputText;
    std::string         buffer;
    std::string         outputText; 

    char                fst_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //
    char                snd_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //second level encryption.
    char                thrd_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];      //

    char                digitals_crypto[Alphabets::var_d1th][Alphabets::var_col];     //
    char                english_crypto[Alphabets::var_eng][Alphabets::var_col];       //first level encryption.
    char                english_crypto_up[Alphabets::var_eng][Alphabets::var_col];    //    
    char                symbols_crypto[Alphabets::var_sym][Alphabets::var_col];       //

    int decryption_duble()                     //decryption second level
    {
        //int size = strleny(buffer);
        size = buffer.length();
        // std::cout << "begin decryption2" << std::endl;
        // std::cout << "size = " << size << std::endl;
        for (size_t j = 0; j < size; j++)      //search values
        {
            for (size_t k = 0; k < 26; k++)
            {
                if (buffer[j] == english_crypto[k][0])
                {   
                    if(buffer[j+1] == english_crypto[k][1])
                    {   
                        if(buffer[j+2] == english_crypto[k][2])
                        {   
                            if (buffer[j+3] == english_crypto[k][3])
                            {       
                                if (buffer[j+4] == english_crypto[k][4])
                                {
                                    outputText += Alphabets::english[k];
                                    j+=3;
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
            for (size_t k = 0; k < 26; k++)
            {
                if (buffer[j] == english_crypto_up[k][0])
                {   
                    if(buffer[j+1] == english_crypto_up[k][1])
                    {   
                        if(buffer[j+2] == english_crypto_up[k][2])
                        {   
                            if (buffer[j+3] == english_crypto_up[k][3])
                            {       
                                if (buffer[j+4] == english_crypto_up[k][4])
                                {
                                    outputText += Alphabets::english_up[k];
                                    j+=3;
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
            for (size_t k = 0; k < 33; k++)
            {
                if (buffer[j] == symbols_crypto[k][0])
                {   
                    if(buffer[j+1] == symbols_crypto[k][1])
                    {   
                        if(buffer[j+2] == symbols_crypto[k][2])
                        {   
                            if (buffer[j+3] == symbols_crypto[k][3])
                            {       
                                if (buffer[j+4] == symbols_crypto[k][4])
                                {
                                    outputText += Alphabets::symbols[k];
                                    j+=3;
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
            for (size_t k = 0; k < 10; k++)
            {
                if (buffer[j] == digitals_crypto[k][0])
                {   
                    if(buffer[j+1] == digitals_crypto[k][1])
                    {   
                        if(buffer[j+2] == digitals_crypto[k][2])
                        {   
                            if (buffer[j+3] == digitals_crypto[k][3])
                            {       
                                if (buffer[j+4] == digitals_crypto[k][4])
                                {
                                    outputText += Alphabets::digitals[k];
                                    j+=3;
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    void checkcrypto(){
        for (size_t i = 0; i < Alphabets::var_d1th; i++)
        {
            for (size_t j = 0; j < Alphabets::var_2th; j++)
            {
                for (size_t l = 0; l < Alphabets::var_3th; l++)
                {
                    std::cout << fst_[i][j][l];
                }
            }
        }
        for (size_t i = 0; i < Alphabets::var_d1th; i++)
        {
            for (size_t j = 0; j < Alphabets::var_2th; j++)
            {
                for (size_t l = 0; l < Alphabets::var_3th; l++)
                {
                    std::cout << snd_[i][j][l];
                }
            }
        }
        for (size_t i = 0; i < Alphabets::var_d1th; i++)
        {
            for (size_t j = 0; j < Alphabets::var_2th; j++)
            {
                for (size_t l = 0; l < Alphabets::var_3th; l++)
                {
                    std::cout << thrd_[i][j][l];
                }
            }
        }
        std::cout << "eng" << std::endl;
        for (size_t i = 0; i < Alphabets::var_eng; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << english_crypto[i][j];
            }
        }
        std::cout << "eng_up" << std::endl;
        for (size_t i = 0; i < Alphabets::var_eng; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << english_crypto_up[i][j];
            }
        }
        std::cout << "symbols" << std::endl;

        for (size_t i = 0; i < Alphabets::var_sym; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << symbols_crypto[i][j];
            }
        }
        std::cout << "digitals" << std::endl;
        for (size_t i = 0; i < Alphabets::var_d1th; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << digitals_crypto[i][j];
            }
        }
    }
    int encryption_duble()                     //encryption second level
    {
        // int size = strleny(buffer);
        std::cout << buffer << std::endl;
        std::cout << "begin encry2" << std::endl;

        size = buffer.length();

        // std::cout << "size = (buffer)"
        for (size_t j = 0; j < size; j++)   //search values
        {
            for (size_t i = 0; i < 10; i++)
            {
                if (buffer[j]==Alphabets::digitals[i])
                {
                    append(COND::SECOND_LVL ,i , COND::DIG);
                    i = 0;
                    break;
                }
            }
        }
        std::cout << "end encry2" << std::endl;
        std::cout << outputText << std::endl;
        return 0;
    }

protected:
    
public:
    std::string GetterIT()  {return inputText;}
    std::string GetterOT()  {return outputText;}

    void Setter(std::string* value) {inputText = *value;}

    Cryptography(std::string* value, std::string path){
        inputText = *value;
        this->path = path;
        size = strleny(inputText);
    }
    Cryptography(std::string value, std::string path){
        inputText = value;
        this->path = path;
        size = strleny(inputText);
    }
    Cryptography(){}

    int write_to_cache(std::string& path)   //write Alphabets to global variable
    {
        char            buff[130];          //
        char            buff2[130];         //
        char            buff3[165];         //          local variables  
        char            buff4[50];          //                for
        char            buff5[60];          //      storing temporary values.
        char            buff6[60];          //
        char            buff7[60];          //
        std::ifstream   fin;                // create stream for reading Alphabets from a file.
        fin.open(path);                     //open file
        if(fin.is_open())
        {
            
            fin.getline(buff, 131);     //
            fin.getline(buff2, 131);    //
            fin.getline(buff3, 166);    //      reading 
            fin.getline(buff4, 51);     //        Alphabets
            fin.getline(buff5, 61);     //
            fin.getline(buff6, 61);     //
            fin.getline(buff7, 61);     //
            fin.close();
        }
        else
        {
            std::cout << ". File opening error, check the correct path. [Read Alphabetsbase]" << '\n';
            exit(1);
        }
        for (size_t j = 0, k = 0, p = 0; j < 33; j++)
        {
            for (size_t i = 0; i < 5; i++, k++)
            {
                if (j < 10) {digitals_crypto[j][i]=buff4[k];}
                if (j < 26)
                {
                    english_crypto[j][i]=buff[k];             //write to global Alphabets
                    english_crypto_up[j][i]=buff2[k]; 
                }
                if(j < 33)  {symbols_crypto[j][i]=buff3[k]; }
            }
            if (j < 10)
            {
                for (size_t i = 0; i < 3; i++)
                {
                    for (size_t l = 0; l < 2; l++, p++)
                    {
                        fst_[j][i][l]  = buff5[p];              //write to global Alphabets
                        snd_[j][i][l]  = buff6[p];
                        thrd_[j][i][l] = buff7[p];
                    }
                }
            }
        }
        std::cout << "write to cache" << std::endl;
        return 0;
    }

    void append(int lvl, int index, int descript)  //function for append Alphabets in local variable
    {
        std::cout << index<< std::endl;
        if (lvl==COND::FIRST_LVL)
        {
            if      (descript==COND::ENG)           {for (size_t i = 0; i < 5; i++)  {buffer += english_crypto[index][i];}}
            else if (descript==COND::ENG_UP)        {for (size_t i = 0; i < 5; i++)  {buffer += english_crypto_up[index][i];}}
            else if (descript==COND::SYM)           {for (size_t i = 0; i < 5; i++)  {buffer += symbols_crypto[index][i];}}
            else if (descript==COND::DIG)           {for (size_t i = 0; i < 5; i++)  {buffer += digitals_crypto[index][i];}}
        }
        if (lvl==COND::SECOND_LVL)
        {
            int       n = rand() % 3;                //generating a value for randomly selecting an array element
            int slct_ar = rand() % 3;          //generating a value for a random array selection
            if      (slct_ar==0)    {for (size_t i = 0; i < 2; i++)  {outputText += fst_[index][n][i];}}
            else if (slct_ar==1)    {for (size_t i = 0; i < 2; i++)  {outputText += snd_[index][n][i];}}
            else if (slct_ar==2)    {for (size_t i = 0; i < 2; i++)  {outputText += thrd_[index][n][i];}}   
        }
    }

    int decryption()                           //decryption first level
    {
        // int   size  =  strleny(inputText);
        //search values
        
        // std::cout << "begin decryption" << std::endl;
        // std::cout << "size = " << size << std::endl;
        for (size_t y = 0; y < size; y+=2)
        { 
            for (size_t i = 0; i < 10; i++)
            {
                for (size_t k = 0; k < 3; k++)
                {
                    if(inputText[y] == fst_[i][k][0])
                    {
                        if (inputText[y+1]==fst_[i][k][1])
                        {
                            buffer += Alphabets::digitals[i]; 
                            i++;
                            break;
                        } 
                    }
                    if(inputText[y]==snd_[i][k][0])
                    {
                        if (inputText[y+1]==snd_[i][k][1])
                        {
                            buffer += Alphabets::digitals[i]; 
                            i++;
                            break;
                        } 
                    }
                    if(inputText[y]==thrd_[i][k][0])
                    {
                        if (inputText[y+1]==thrd_[i][k][1])
                        {
                            buffer += Alphabets::digitals[i]; 
                            i++;
                            break;
                        } 
                    }
                }
            }
        }
        // std::cout << buffer << std::endl;
        decryption_duble();       //decryption second level
        return 0;
    }
    int encryption()                           //encryption first level
    {
        std::cout << "begin encryption" << std::endl;
        std::cout << inputText << std::endl;
        checkcrypto();
        // std::cout << outputText << std::endl;
        // std::cout << "size = " << size << std::endl;
        // int  size  =  strleny();   
        for (size_t j = 0; j < size; j++)      //search values
        {
            for (size_t i = 0; i < 33; i++)
            {
                if (inputText[j]==Alphabets::symbols[i])
                {
                    std::cout << i << std::endl;
                    append(COND::FIRST_LVL ,i , COND::SYM);
                    i = 0;
                    break;
                }
                if (i < 10)
                {
                    if (inputText[j]==Alphabets::digitals[i])
                    {
                        std::cout << i << std::endl;
                        append(COND::FIRST_LVL ,i , COND::DIG);
                        i = 0;
                        break;
                    }
                }
                if (i < 26) {
                    if (inputText[j]==Alphabets::english[i])
                    {
                        std::cout << i << std::endl;
                        append(COND::FIRST_LVL ,i , COND::ENG);
                        i = 0;
                        break;
                    }
                    if (inputText[j]==Alphabets::english_up[i])
                    {
                        std::cout << i << std::endl;
                        append(COND::FIRST_LVL ,i , COND::ENG_UP);
                        i = 0;
                        break;
                    }
                }   
            }
        }
        std::cout << buffer << std::endl;
        std::cout << "end encryption" << std::endl;
        encryption_duble(); //encryption second level
        return 0;
    }
};


