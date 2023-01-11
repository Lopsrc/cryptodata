
class Cryptography{
protected:
    std::string         path;

    StorageIOText storageIOText; 

    std::string         bufferClipboard;
    std::string         bufferClipboard2;

    StorageEncryptionCode storageEncryptionCode;

    void checkcrypto(){
        std::cout << "\ncryptoshifr 1 lvl " << std::endl;
        for (size_t i = 0; i < Alphabets::var_d1th; i++)
        {
            for (size_t j = 0; j < Alphabets::var_2th; j++)
            {
                for (size_t l = 0; l < Alphabets::var_3th; l++)
                {
                    std::cout << storageEncryptionCode.fst_[i][j][l];
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
                    std::cout << storageEncryptionCode.snd_[i][j][l];
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
                    std::cout << storageEncryptionCode.thrd_[i][j][l];
                }
            }
        }
        std::cout << "\neng" << std::endl;
        for (size_t i = 0; i < Alphabets::var_eng; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << storageEncryptionCode.english_crypto[i][j];
            }
        }
        std::cout << "\neng_up" << std::endl;
        for (size_t i = 0; i < Alphabets::var_eng; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << storageEncryptionCode.english_crypto_up[i][j];
            }
        }
        std::cout << "\nsymbols" << std::endl;

        for (size_t i = 0; i < Alphabets::var_sym; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << storageEncryptionCode.symbols_crypto[i][j];
            }
        }
        std::cout << "\ndigitals" << std::endl;
        for (size_t i = 0; i < Alphabets::var_d1th; i++)
        {
            for (size_t j = 0; j < Alphabets::var_col; j++)
            {
                std::cout << storageEncryptionCode.digitals_crypto[i][j];
            }
        }
    }
     
protected:
    
public:
    std::string GetterIT()  {return storageIOText.inputText;}
    std::string GetterOT()  {return storageIOText.outputText;}
    void Setter(std::string* value) {storageIOText.inputText = *value;}
    
    Cryptography(){}

    bool checkSum(){
        std::cout << "size inputtext = " << storageIOText.inputText.length() << std::endl;
        std::cout << "size outputtext = " << storageIOText.outputText.length() << std::endl;
        if(ST::action_c == 1){
            if (storageIOText.inputText.length() != storageIOText.outputText.length()/10) {return false;}
        }
        else if(ST::action_c == 2){
            if (storageIOText.inputText.length() != storageIOText.outputText.length()*10) {return false;}
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

        char            encryptionFourthEnglishCode[130];          //
        char            encryptionFourthEnglishUpCode[130];         //
        char            encryptionFourhSymbolsCode[165];         //          local variables  
        char            encryptionFourthDigitalsCode[50];          //                for
        char            encryptionThirdFirstCode[60];          //      storing temporary values.
        char            encryptionThirdSecondCode[60];          //
        char            encryptionThirdThirdCode[60];          //
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
                if (j < 10) 
                {
                    storageEncryptionCode.digitals_crypto[j][i]=buff4[k];
                    storageEncryptionCode.digitals_crypto_Fourth[j][i]=encryptionFourthDigitalsCode[k];
                }
                if (j < 26)
                {
                    storageEncryptionCode.english_crypto[j][i]=buff[k];             //write to global Alphabets
                    storageEncryptionCode.english_crypto_up[j][i]=buff2[k]; 
                    storageEncryptionCode.english_crypto_Fourth[j][i]=encryptionFourthEnglishCode[k];
                    storageEncryptionCode.english_crypto_up_Fourth[j][i]=encryptionFourthEnglishUpCode[k];
                }
                if(j < 33)  
                {
                    storageEncryptionCode.symbols_crypto[j][i]=buff3[k]; 
                    storageEncryptionCode.symbols_crypto_Fourth[j][i]=encryptionFourhSymbolsCode[k];
                }
            }
            if (j < 10)
            {
                for (size_t i = 0; i < 3; i++)
                {
                    for (size_t l = 0; l < 2; l++, p++)
                    {
                        storageEncryptionCode.fst_[j][i][l]  = buff5[p];              //write to global Alphabets
                        storageEncryptionCode.snd_[j][i][l]  = buff6[p];
                        storageEncryptionCode.thrd_[j][i][l] = buff7[p];
                        storageEncryptionCode.encryptionThirdLevelFirstCode[j][i][l]  = encryptionThirdFirstCode[p];              //write to global Alphabets
                        storageEncryptionCode.encryptionThirdLevelSecondCode[j][i][l]  = encryptionThirdSecondCode[p];
                        storageEncryptionCode.encryptionThirdLevelThirdCode[j][i][l] = encryptionThirdThirdCode[p];
                    }
                }
            }
        }
        std::cout << "write to cache" << std::endl;
        // checkcrypto();
        return 0;
    }

    void append(int lvl, int index, int descript)  //function for append Alphabets in local variable
    {
        // std::cout << index<< std::endl;
        if (lvl==COND::FIRST_LVL)
        {
            if      (descript==COND::ENG)           {for (size_t i = 0; i < 5; i++)  {bufferClipboard += storageEncryptionCode.english_crypto[index][i];}}
            else if (descript==COND::ENG_UP)        {for (size_t i = 0; i < 5; i++)  {bufferClipboard += storageEncryptionCode.english_crypto_up[index][i];}}
            else if (descript==COND::SYM)           {for (size_t i = 0; i < 5; i++)  {bufferClipboard += storageEncryptionCode.symbols_crypto[index][i];}}
            else if (descript==COND::DIG)           {for (size_t i = 0; i < 5; i++)  {bufferClipboard += storageEncryptionCode.digitals_crypto[index][i];}}
        }
        if (lvl==COND::SECOND_LVL)
        {
            int       randomColumn  = rand() % 3;                //generating a value for randomly selecting an array element
            int       randomSelect  = rand() % 3;          //generating a value for a random array selection
            if      (randomSelect==0)    {for (size_t i = 0; i < 2; i++)  {storageIOText.outputText += storageEncryptionCode.fst_[index][randomColumn][i];}}
            else if (randomSelect==1)    {for (size_t i = 0; i < 2; i++)  {storageIOText.outputText += storageEncryptionCode.snd_[index][randomColumn][i];}}
            else if (randomSelect==2)    {for (size_t i = 0; i < 2; i++)  {storageIOText.outputText += storageEncryptionCode.thrd_[index][randomColumn][i];}}   
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

        size_t size = bufferClipboard.length();

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
        std::cout << storageIOText.outputText << "  (output text)" << std::endl;
        return 0;
    }
    int decryptionFourthLevel(){return 0;}
    int decryptionThirdLevel(){return 0;}
    int decryptionSecondLevel()                     //decryption second level
    {
        //int size = strleny(bufferClipboard);
        size_t size = bufferClipboard.length();
        // std::cout << "begin decryption2" << std::endl;
        // std::cout << "size = " << size << std::endl;
        for (size_t j = 0; j < size; j++)      //search values
        {
            for (size_t k = 0; k < 26; k++)
            {
                if (bufferClipboard[j] == storageEncryptionCode.english_crypto[k][0])
                {   
                    if(bufferClipboard[j+1] == storageEncryptionCode.english_crypto[k][1])
                    {   
                        if(bufferClipboard[j+2] == storageEncryptionCode.english_crypto[k][2])
                        {   
                            if (bufferClipboard[j+3] == storageEncryptionCode.english_crypto[k][3])
                            {       
                                if (bufferClipboard[j+4] == storageEncryptionCode.english_crypto[k][4])
                                {
                                    storageIOText.outputText += Alphabets::english[k];
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
                if (bufferClipboard[j] == storageEncryptionCode.english_crypto_up[k][0])
                {   
                    if(bufferClipboard[j+1] == storageEncryptionCode.english_crypto_up[k][1])
                    {   
                        if(bufferClipboard[j+2] == storageEncryptionCode.english_crypto_up[k][2])
                        {   
                            if (bufferClipboard[j+3] == storageEncryptionCode.english_crypto_up[k][3])
                            {       
                                if (bufferClipboard[j+4] == storageEncryptionCode.english_crypto_up[k][4])
                                {
                                    storageIOText.outputText += Alphabets::english_up[k];
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
                if (bufferClipboard[j] == storageEncryptionCode.symbols_crypto[k][0])
                {   
                    if(bufferClipboard[j+1] == storageEncryptionCode.symbols_crypto[k][1])
                    {   
                        if(bufferClipboard[j+2] == storageEncryptionCode.symbols_crypto[k][2])
                        {   
                            if (bufferClipboard[j+3] == storageEncryptionCode.symbols_crypto[k][3])
                            {       
                                if (bufferClipboard[j+4] == storageEncryptionCode.symbols_crypto[k][4])
                                {
                                    storageIOText.outputText += Alphabets::symbols[k];
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
                if (bufferClipboard[j] == storageEncryptionCode.digitals_crypto[k][0])
                {   
                    if(bufferClipboard[j+1] == storageEncryptionCode.digitals_crypto[k][1])
                    {   
                        if(bufferClipboard[j+2] == storageEncryptionCode.digitals_crypto[k][2])
                        {   
                            if (bufferClipboard[j+3] == storageEncryptionCode.digitals_crypto[k][3])
                            {       
                                if (bufferClipboard[j+4] == storageEncryptionCode.digitals_crypto[k][4])
                                {
                                    storageIOText.outputText += Alphabets::digitals[k];
                                    j+=3;
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << "outputText = " << storageIOText.outputText << std::endl;
        return 0;
    }

public:
    int decryption()                           //decryption first level
    {
        // int   size  =  strleny(inputText);
        //search values
        size_t size = storageIOText.inputText.length();
        std::cout << "begin buffer" << bufferClipboard << std::endl;
        std::cout << "size = " << size << std::endl;
        // bool flagFindStatus = false;
        for (size_t y = 0; y < size; y+=2)
        { 
            for (size_t i = 0; i < 10; i++)
            {
                for (size_t k = 0; k < 3; k++)
                {
                    if(storageIOText.inputText[y] == storageEncryptionCode.fst_[i][k][0])
                    {
                        if (storageIOText.inputText[y+1]==storageEncryptionCode.fst_[i][k][1])
                        {
                            std::cout << "first shifr ";
                            bufferClipboard += Alphabets::digitals[i]; 
                            std::cout << bufferClipboard << std::endl;
                            // i++;
                            // flagFindStatus = true;
                            break;
                        }
                    }
            
                    if(storageIOText.inputText[y]==storageEncryptionCode.snd_[i][k][0])
                    {
                        if (storageIOText.inputText[y+1]==storageEncryptionCode.snd_[i][k][1])
                        {
                            std::cout << "second shifr ";
                            bufferClipboard += Alphabets::digitals[i]; 
                            // i++;
                            // flagFindStatus = true;
                            break;
                        } 
                    }
                    
                    if(storageIOText.inputText[y]==storageEncryptionCode.thrd_[i][k][0])
                    {
                        if (storageIOText.inputText[y+1]==storageEncryptionCode.thrd_[i][k][1])
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
        size_t size = storageIOText.inputText.length();
        // checkcrypto();
        // std::cout << outputText << std::endl;
        std::cout << "size(inputtext) = " << size << std::endl;
        // int  size  =  strleny();   
        for (size_t j = 0; j < size; j++)      //search values
        {
            for (size_t i = 0; i < 33; i++)
            {
                if (storageIOText.inputText[j]==Alphabets::symbols[i])
                {
                    // std::cout << i << std::endl;
                    append(COND::FIRST_LVL ,i , COND::SYM);
                    i = 0;
                    break;
                }
                if (i < 10)
                {
                    if (storageIOText.inputText[j]==Alphabets::digitals[i])
                    {
                        // std::cout << i << std::endl;
                        append(COND::FIRST_LVL ,i , COND::DIG);
                        i = 0;
                        break;
                    }
                }
                if (i < 26) {
                    if (storageIOText.inputText[j]==Alphabets::english[i])
                    {
                        // std::cout << i << std::endl;
                        append(COND::FIRST_LVL ,i , COND::ENG);
                        i = 0;
                        break;
                    }
                    if (storageIOText.inputText[j]==Alphabets::english_up[i])
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
