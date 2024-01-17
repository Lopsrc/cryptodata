
class Cryptography{
protected:
    std::string         path;

    StorageIOText storageIOText; 

    std::string         bufferClipboard;
    std::string         bufferClipboard2;
    StorageEncryptionCode storageEncryptionCode;
    StorageEncryptionCodeNew storageEncryptionCodeN;
       
public:

    std::string GetterIT()  {return storageIOText.inputText;}
    std::string GetterOT()  {return storageIOText.outputText;}
    void        Setter(std::string* value) {storageIOText.inputText = *value;}
    
    Cryptography(){}

    bool checkLengthForKey(){
        // std::cout << storageEncryptionCodeN.englishCryptoKey.length() << "\n" <<
        // storageEncryptionCodeN.englishUpCryptoKey.length() << "\n" <<
        // storageEncryptionCodeN.symbolsCryptoKey.length() << "\n" <<
        // storageEncryptionCodeN.digitalsCryptoKey.length() << "\n" <<
        // storageEncryptionCodeN.firstLayerForSecondLevel.length() << "\n" <<
        // storageEncryptionCodeN.secondLayerForSecondLevel.length()<< "\n" <<
        // storageEncryptionCodeN.thirdLayerForSecondLevel.length()<< std::endl;
        if (
            storageEncryptionCodeN.englishCryptoKey.length()           != 130 ||
            storageEncryptionCodeN.englishUpCryptoKey.length()         != 130 ||
            storageEncryptionCodeN.symbolsCryptoKey.length()           != 165 ||
            storageEncryptionCodeN.digitalsCryptoKey.length()           != 50  ||
            storageEncryptionCodeN.firstLayerForSecondLevel.length()   != 60  ||
            storageEncryptionCodeN.secondLayerForSecondLevel.length()  != 60  ||
            storageEncryptionCodeN.thirdLayerForSecondLevel.length()   != 60
             )
            return false;
        return true;
    }
    bool checkSum(int cryptoAction){
        std::cout << storageIOText.inputText.length() << std::endl;
        std::cout << storageIOText.outputText.length() << storageIOText.outputText << std::endl;

        if(cryptoAction == 1 && (storageIOText.inputText.length() != storageIOText.outputText.length()/10)){
            return false;
        }
        else if(cryptoAction == 2 && (storageIOText.inputText.length() != storageIOText.outputText.length()*10)){
            return false;
        }
        return true;
    }

    int write_to_cache(std::string& path)   //write Alphabets to global variable
    {
        // char            bufferForEng[130];          //
        // char            bufferForEngUp[130];         //
        // char            bufferForSymbols[165];         //          local variables  
        // char            bufferForDigitals[50];          //                for
        // char            bufferForFirstLevel[60];          //      storing temporary values.
        // char            bufferForSecondLevel[60];          //
        // char            bufferForThirdLevel[60];          //

        std::ifstream   fin;                // create stream for reading Alphabets from a file.
        fin.open(path);                     //open file
        if(fin.is_open())
        {
            
            // fin.getline(bufferForEng, 131);     //
            // fin.getline(bufferForEngUp, 131);    //
            // fin.getline(bufferForSymbols, 166);    //      reading 
            // fin.getline(bufferForDigitals, 51);     //        Alphabets
            // fin.getline(bufferForFirstLevel, 61);     //
            // fin.getline(bufferForSecondLevel, 61);     //
            // fin.getline(bufferForThirdLevel, 61);     //
            // fin.close();
            std::getline(fin, storageEncryptionCodeN.englishCryptoKey);     //
            std::getline(fin, storageEncryptionCodeN.englishUpCryptoKey);    //
            std::getline(fin, storageEncryptionCodeN.symbolsCryptoKey);    //      reading 
            std::getline(fin, storageEncryptionCodeN.digitalsCryptoKey);     //        Alphabets
            std::getline(fin, storageEncryptionCodeN.firstLayerForSecondLevel);     //
            std::getline(fin, storageEncryptionCodeN.secondLayerForSecondLevel);     //
            std::getline(fin, storageEncryptionCodeN.thirdLayerForSecondLevel);     //
            fin.close();
        }
        else
        {
            std::cout << ". File opening error, check the correct path. [Read Alphabetsbase]" << '\n';
            return 1;
        }

        // std::cout << storageEncryptionCodeN.englishCryptoKey << "\n" << storageEncryptionCodeN.englishUpCryptoKey << "\n" << storageEncryptionCodeN.symbolsCryptoKey << 
        // "\n" << storageEncryptionCodeN.digitalsCryptoKey << "\n" << storageEncryptionCodeN.firstLayerForSecondLevel << "\n" << storageEncryptionCodeN.secondLayerForSecondLevel <<
        // "\n" << storageEncryptionCodeN.thirdLayerForSecondLevel << std::endl;

        // for (size_t j = 0, k = 0, p = 0; j < 33; j++)
        // {
        //     for (size_t i = 0; i < 5; i++, k++)
        //     {
        //         if (j < 10) 
        //         {
        //             storageEncryptionCode.digitals_crypto[j][i]=bufferForDigitals[k];
        //         }
        //         if (j < 26)
        //         {
        //             storageEncryptionCode.english_crypto[j][i]=bufferForEng[k];             //write to global Alphabets
        //             storageEncryptionCode.english_crypto_up[j][i]=bufferForEngUp[k]; 
        //         }
        //         if(j < 33)  
        //         {
        //             storageEncryptionCode.symbols_crypto[j][i]=bufferForSymbols[k]; 
        //         }
        //     }
        //     if (j < 10)
        //     {
        //         for (size_t i = 0; i < 3; i++)
        //         {
        //             for (size_t l = 0; l < 2; l++, p++)
        //             {
        //                 storageEncryptionCode.fst_[j][i][l]  = bufferForFirstLevel[p];              //write to global Alphabets
        //                 storageEncryptionCode.snd_[j][i][l]  = bufferForSecondLevel[p];
        //                 storageEncryptionCode.thrd_[j][i][l] = bufferForThirdLevel[p];
        //             }
        //         }
        //     }
        // }
        // storageEncryptionCode.len_eng   = strlen(bufferForEng);
        // storageEncryptionCode.len_engUp = strlen(bufferForEngUp);
        // storageEncryptionCode.len_sym   = strlen(bufferForSymbols);
        // storageEncryptionCode.len_dig   = strlen(bufferForDigitals);
        // storageEncryptionCode.len_fst   = strlen(bufferForFirstLevel);
        // storageEncryptionCode.len_snd   = strlen(bufferForSecondLevel);
        // storageEncryptionCode.len_thrd  = strlen(bufferForThirdLevel);
        return 0;
    }

    void append(int lvl, int index, int descript)  //function for append Alphabets in local variable
    {
        if (lvl==COND::FIRST_LVL)
        {
            int indexBegin = index * 5;
            if      (descript==COND::ENG)           {bufferClipboard += storageEncryptionCodeN.englishCryptoKey.substr(indexBegin, 5);}
            else if (descript==COND::ENG_UP)        {bufferClipboard += storageEncryptionCodeN.englishUpCryptoKey.substr(indexBegin, 5);}
            else if (descript==COND::SYM)           {bufferClipboard += storageEncryptionCodeN.symbolsCryptoKey.substr(indexBegin, 5);}
            else if (descript==COND::DIG)           {bufferClipboard += storageEncryptionCodeN.digitalsCryptoKey.substr(indexBegin, 5);}
        }
        if (lvl==COND::SECOND_LVL)
        {
            int       indexBegin    = index * 6; 
            int       randomColumn  = rand() % 3;                //generating a value for randomly selecting an array element
            int       randomSelect  = rand() % 3;          //generating a value for a random array selection
            switch (randomSelect)
            {
            case 0:
                storageIOText.outputText += storageEncryptionCodeN.firstLayerForSecondLevel.substr(indexBegin+randomColumn*2, 2);
                break;
            case 1:
                storageIOText.outputText += storageEncryptionCodeN.secondLayerForSecondLevel.substr(indexBegin+randomColumn*2, 2);
                break;
            case 2:
                storageIOText.outputText += storageEncryptionCodeN.thirdLayerForSecondLevel.substr(indexBegin+randomColumn*2, 2);
                break;
            default:
                break;
            }   
        }
    }

};

class CryptographyEnglish:public Cryptography{
private:
    
    int encryptionSecondLevel()                     //encryption second level
    {
        for (size_t j = 0; j < bufferClipboard.length(); j++)   //search values
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
        return 0;
    }

    int decryptionSecondLevel()                     //decryption second level
    {
        int flag = 0;
        size_t size = bufferClipboard.length();
        for (size_t j = 0; j < size; j++)      //search values
        {
            for (size_t k = 0; k < 26; k++)
            {
                flag = 0;
                for (size_t i = 0; i < 5; i++)
                {
                    if (bufferClipboard[j+i] == storageEncryptionCode.english_crypto[k][i]){
                        flag++;
                        // std::cout << "flag = " << flag << " k = " << k << " i = " << i << " j = " << j << "\t bc = " << bufferClipboard[j+i] << " e_c = " << storageEncryptionCode.english_crypto[k][i] << std::endl;
                    }
                    else
                        break;
                    if (flag==5)
                    {
                        storageIOText.outputText += Alphabets::english[k];
                        j+=3;
                        continue;
                    }
                    
                }
            }
            for (size_t k = 0; k < 26; k++)
            {
                flag = 0;
                for (size_t i = 0; i < 5; i++)
                {
                    if (bufferClipboard[j+i] == storageEncryptionCode.english_crypto_up[k][i])
                        flag++;
                    else
                        break;
                    if (flag==5)
                    {
                        storageIOText.outputText += Alphabets::english_up[k];
                        j+=3;
                        continue;
                    }
                    
                }
            }
            for (size_t k = 0; k < 33; k++)
            {
                flag = 0;
                for (size_t i = 0; i < 5; i++)
                {
                    if (bufferClipboard[j+i] == storageEncryptionCode.symbols_crypto[k][i])
                        flag++;
                    else
                        break;
                    if (flag==5)
                    {
                        storageIOText.outputText += Alphabets::symbols[k];
                        j+=3;
                        continue;
                    }
                    
                }
            }
            for (size_t k = 0; k < 10; k++)
            {
                flag = 0;
                for (size_t i = 0; i < 5; i++)
                {
                    if (bufferClipboard[j+i] == storageEncryptionCode.digitals_crypto[k][i])
                        flag++;
                    else
                        break;
                    if (flag==5)
                    {
                        storageIOText.outputText += Alphabets::digitals[k];
                        j+=3;
                        continue;
                    }
                }
            }
        }
        return 0;
    }

public:
    int decryption()                           //decryption first level
    {
        for (size_t y = 0; y < storageIOText.inputText.length(); y+=2)
        { 
            for (size_t i = 0; i < 10; i++)
            {
                for (size_t k = 0; k < 3; k++)
                {
                    
                    if ((storageIOText.inputText[y]==storageEncryptionCode.fst_[i][k][0] && storageIOText.inputText[y+1]==storageEncryptionCode.fst_[i][k][1]) ||  
                        (storageIOText.inputText[y]==storageEncryptionCode.snd_[i][k][0] && storageIOText.inputText[y+1]==storageEncryptionCode.snd_[i][k][1]) || 
                        (storageIOText.inputText[y]==storageEncryptionCode.thrd_[i][k][0] && storageIOText.inputText[y+1]==storageEncryptionCode.thrd_[i][k][1]))
                    {
                        bufferClipboard += Alphabets::digitals[i]; 
                        break;   
                    }   
                    // if (storageIOText.inputText[y]==storageEncryptionCode.fst_[i][k][0] ||  storageIOText.inputText[y]==storageEncryptionCode.snd_[i][k][0] || storageIOText.inputText[y]==storageEncryptionCode.thrd_[i][k][0])
                    // {
                    //     if (storageIOText.inputText[y+1]==storageEncryptionCode.fst_[i][k][1] ||  storageIOText.inputText[y+1]==storageEncryptionCode.snd_[i][k][1] || storageIOText.inputText[y+1]==storageEncryptionCode.thrd_[i][k][1])
                    //     {
                    //         bufferClipboard += Alphabets::digitals[i]; 
                    //         break;
                    //     }
                    // }
                    // if (storageIOText.inputText[y]==storageEncryptionCode.fst_[i][k][0] ||  storageIOText.inputText[y]==storageEncryptionCode.snd_[i][k][0] || storageIOText.inputText[y]==storageEncryptionCode.thrd_[i][k][0])
                    // {
                    //     if (storageIOText.inputText[y+1]==storageEncryptionCode.fst_[i][k][1] ||  storageIOText.inputText[y+1]==storageEncryptionCode.snd_[i][k][1] || storageIOText.inputText[y+1]==storageEncryptionCode.thrd_[i][k][1])
                    //     {
                    //         bufferClipboard += Alphabets::digitals[i]; 
                    //         break;
                    //     }
                    // }
                
                }
            }
        }
        std::cout << bufferClipboard.length() << " is length bufferclipboard " << bufferClipboard << std::endl;
        decryptionSecondLevel();       //decryption second level
        return 0;
    }
    int encryption()                           //encryption first level
    {  
        for (size_t j = 0; j < storageIOText.inputText.length(); j++)      //search values
        {
            for (size_t i = 0; i < 33; i++)
            {
                if (storageIOText.inputText[j]==Alphabets::symbols[i])
                {
                    append(COND::FIRST_LVL ,i , COND::SYM);
                    i = 0;
                    break;
                }
                if (i < 10)
                {
                    if (storageIOText.inputText[j]==Alphabets::digitals[i])
                    {
                        append(COND::FIRST_LVL ,i , COND::DIG);
                        i = 0;
                        break;
                    }
                }
                if (i < 26) {
                    if (storageIOText.inputText[j]==Alphabets::english[i])
                    {
                        append(COND::FIRST_LVL ,i , COND::ENG);
                        i = 0;
                        break;
                    }
                    if (storageIOText.inputText[j]==Alphabets::english_up[i])
                    {
                        append(COND::FIRST_LVL ,i , COND::ENG_UP);
                        i = 0;
                        break;
                    }
                }   
            }
        }
        encryptionSecondLevel(); //encryption second level
        return 0;
    }

};
class CryptographyRussian:public Cryptography{
private:
    int encryptionSecondLevel(){return 0;}

    int decryptionSecondLevel(){return 0;}

public:
    CryptographyRussian(){}
    
    int encryption(){return 0;}
    int decryption(){return 0;}
};
