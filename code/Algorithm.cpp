
//проверить алгоритмы расшифровки. или нет. сначала шифровки, может проблема в этом, некорректное шифрование привело к некорректной расшифровки, хотя size  одинаков

class Cryptography{
protected:
    size_t              size;
    std::string         path;

    std::string         inputText;
    std::string         bufferClipboard;
    std::string         bufferClipboard2;
    std::string         outputText; 

    char                fst_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //
    char                snd_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //second level encryption.
    char                thrd_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];      //

    char                digitals_crypto[Alphabets::var_d1th][Alphabets::var_col];     //
    char                english_crypto[Alphabets::var_eng][Alphabets::var_col];       //first level encryption.
    char                english_crypto_up[Alphabets::var_eng][Alphabets::var_col];    //    
    char                symbols_crypto[Alphabets::var_sym][Alphabets::var_col];       //

    void checkcrypto(){
        std::cout << "\ncryptoshifr 1 lvl " << std::endl;
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
        std::cout << "\ncryptoshifr 2 lvl " << std::endl;
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
        std::cout << "\ncryptoshifr 3 lvl " << std::endl;
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
        std::cout << "\neng" << std::endl;
        for (size_t i = 0; i < Alphabets::var_eng; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << english_crypto[i][j];
            }
        }
        std::cout << "\neng_up" << std::endl;
        for (size_t i = 0; i < Alphabets::var_eng; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << english_crypto_up[i][j];
            }
        }
        std::cout << "\nsymbols" << std::endl;

        for (size_t i = 0; i < Alphabets::var_sym; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << symbols_crypto[i][j];
            }
        }
        std::cout << "\ndigitals" << std::endl;
        for (size_t i = 0; i < Alphabets::var_d1th; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << digitals_crypto[i][j];
            }
        }
    }
     
protected:
    
public:
    std::string GetterIT()  {return inputText;}
    std::string GetterOT()  {return outputText;}
    void Setter(std::string* value) {inputText = *value;}
    
    Cryptography(){}

    bool checkSum(){
        std::cout << "size inputtext = " << inputText.length() << std::endl;
        std::cout << "size outputtext = " << outputText.length() << std::endl;
        if(ST::action_c == 1){
            if (inputText.length() != outputText.length()/10) {return false;}
        }
        else if(ST::action_c == 2){
            if (inputText.length() != outputText.length()*10) {return false;}
        }
        return true;
    }

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
        checkcrypto();
        return 0;
    }

    void append(int lvl, int index, int descript)  //function for append Alphabets in local variable
    {
        // std::cout << index<< std::endl;
        if (lvl==COND::FIRST_LVL)
        {
            if      (descript==COND::ENG)           {for (size_t i = 0; i < 5; i++)  {bufferClipboard += english_crypto[index][i];}}
            else if (descript==COND::ENG_UP)        {for (size_t i = 0; i < 5; i++)  {bufferClipboard += english_crypto_up[index][i];}}
            else if (descript==COND::SYM)           {for (size_t i = 0; i < 5; i++)  {bufferClipboard += symbols_crypto[index][i];}}
            else if (descript==COND::DIG)           {for (size_t i = 0; i < 5; i++)  {bufferClipboard += digitals_crypto[index][i];}}
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

};

class CryptographyEnglish:public Cryptography{
private:
    int encryptionFourthLevel(){return 0;}
    int encryptionThirdLevel(){return 0;}
    int encryptionSecondLevel()                     //encryption second level
    {
        // int size = strleny(bufferClipboard);
        // std::cout << bufferClipboard << std::endl;
        std::cout << "begin encry2" << std::endl;

        size = bufferClipboard.length();

        std::cout << "size = (bufferClipboard) " << size << std::endl;
        for (size_t j = 0; j < size; j++)   //search values
        {
            for (size_t i = 0; i < 10; i++)
            {
                if (bufferClipboard[j]==Alphabets::digitals[i])
                {
                    append(COND::SECOND_LVL ,i , COND::DIG);
                    i = 0;
                    break;
                }
            }
        }
        std::cout << "end encry2" << std::endl;
        std::cout << outputText << "  (output text)" << std::endl;
        return 0;
    }
    int decryptionFourthLevel(){return 0;}
    int decryptionThirdLevel(){return 0;}
    int decryptionSecondLevel()                     //decryption second level
    {
        //int size = strleny(bufferClipboard);
        size = bufferClipboard.length();
        // std::cout << "begin decryption2" << std::endl;
        // std::cout << "size = " << size << std::endl;
        for (size_t j = 0; j < size; j++)      //search values
        {
            for (size_t k = 0; k < 26; k++)
            {
                if (bufferClipboard[j] == english_crypto[k][0])
                {   
                    if(bufferClipboard[j+1] == english_crypto[k][1])
                    {   
                        if(bufferClipboard[j+2] == english_crypto[k][2])
                        {   
                            if (bufferClipboard[j+3] == english_crypto[k][3])
                            {       
                                if (bufferClipboard[j+4] == english_crypto[k][4])
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
                if (bufferClipboard[j] == english_crypto_up[k][0])
                {   
                    if(bufferClipboard[j+1] == english_crypto_up[k][1])
                    {   
                        if(bufferClipboard[j+2] == english_crypto_up[k][2])
                        {   
                            if (bufferClipboard[j+3] == english_crypto_up[k][3])
                            {       
                                if (bufferClipboard[j+4] == english_crypto_up[k][4])
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
                if (bufferClipboard[j] == symbols_crypto[k][0])
                {   
                    if(bufferClipboard[j+1] == symbols_crypto[k][1])
                    {   
                        if(bufferClipboard[j+2] == symbols_crypto[k][2])
                        {   
                            if (bufferClipboard[j+3] == symbols_crypto[k][3])
                            {       
                                if (bufferClipboard[j+4] == symbols_crypto[k][4])
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
                if (bufferClipboard[j] == digitals_crypto[k][0])
                {   
                    if(bufferClipboard[j+1] == digitals_crypto[k][1])
                    {   
                        if(bufferClipboard[j+2] == digitals_crypto[k][2])
                        {   
                            if (bufferClipboard[j+3] == digitals_crypto[k][3])
                            {       
                                if (bufferClipboard[j+4] == digitals_crypto[k][4])
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
        std::cout << "outputText = " << outputText << std::endl;
        return 0;
    }

public:
    int decryption()                           //decryption first level
    {
        // int   size  =  strleny(inputText);
        //search values
        size = inputText.length();
        std::cout << "begin buffer" << bufferClipboard << std::endl;
        std::cout << "size = " << size << std::endl;
        // bool flagFindStatus = false;
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
                            std::cout << "first shifr ";
                            bufferClipboard += Alphabets::digitals[i]; 
                            std::cout << bufferClipboard << std::endl;
                            // i++;
                            // flagFindStatus = true;
                            break;
                        }
                    }
            
                    if(inputText[y]==snd_[i][k][0])
                    {
                        if (inputText[y+1]==snd_[i][k][1])
                        {
                            std::cout << "second shifr ";
                            bufferClipboard += Alphabets::digitals[i]; 
                            // i++;
                            // flagFindStatus = true;
                            break;
                        } 
                    }
                    
                    if(inputText[y]==thrd_[i][k][0])
                    {
                        if (inputText[y+1]==thrd_[i][k][1])
                        {
                            std::cout << "third shifr ";
                            bufferClipboard += Alphabets::digitals[i]; 
                            // i++;
                            // flagFindStatus = true;
                            break;
                        } 
                    }
                    
                }
            }
            
            
            // std::cout << bufferClipboard << std::endl;
        }
        std::cout << "bufferClipboard = " << bufferClipboard << std::endl;
        std::cout << "size bufferClipboard = " << bufferClipboard.length() << std::endl;
        decryptionSecondLevel();       //decryption second level
        return 0;
    }
    int encryption()                           //encryption first level
    {
        // std::cout << "begin encryption" << std::endl;
        // std::cout << inputText << std::endl;
        size = inputText.length();
        // checkcrypto();
        // std::cout << outputText << std::endl;
        std::cout << "size(inputtext) = " << size << std::endl;
        // int  size  =  strleny();   
        for (size_t j = 0; j < size; j++)      //search values
        {
            for (size_t i = 0; i < 33; i++)
            {
                if (inputText[j]==Alphabets::symbols[i])
                {
                    // std::cout << i << std::endl;
                    append(COND::FIRST_LVL ,i , COND::SYM);
                    i = 0;
                    break;
                }
                if (i < 10)
                {
                    if (inputText[j]==Alphabets::digitals[i])
                    {
                        // std::cout << i << std::endl;
                        append(COND::FIRST_LVL ,i , COND::DIG);
                        i = 0;
                        break;
                    }
                }
                if (i < 26) {
                    if (inputText[j]==Alphabets::english[i])
                    {
                        // std::cout << i << std::endl;
                        append(COND::FIRST_LVL ,i , COND::ENG);
                        i = 0;
                        break;
                    }
                    if (inputText[j]==Alphabets::english_up[i])
                    {
                        // std::cout << i << std::endl;
                        append(COND::FIRST_LVL ,i , COND::ENG_UP);
                        i = 0;
                        break;
                    }
                }   
            }
        }
        std::cout << bufferClipboard << "   (bufferClipboard)" << std::endl;
        std::cout << "end encryption" << std::endl;
        encryptionSecondLevel(); //encryption second level
        return 0;
    }

};
class CryptographyRussian:public Cryptography{
private:
    int encryptionFourthLevel(){return 0;}
    int encryptionThirdLevel(){return 0;}
    int encryptionSecondLevel(){return 0;}

    int decryptionFourthLevel(){return 0;}
    int decryptionThirdLevel(){return 0;}
    int decryptionSecondLevel(){return 0;}

public:
    CryptographyRussian(){}
    
    int encryption(){return 0;}
    int decryption(){return 0;}
};
