
class Cryptography{
protected:
    std::string         path;

    StorageIOText storageIOText; 

    std::string         bufferClipboard;
    std::string         bufferClipboard2;

    StorageEncryptionCode storageEncryptionCode;
    void defineLengthForKey(){
        int result = 0;
        for (size_t i = 0; i < 10; i++)
        {
           
            
            
            result += strlen(storageEncryptionCode.fst_[i]);
                
            
            
        }
        std::cout << result << " - result " << std::endl;
    }
       
public:
    std::string GetterIT()  {return storageIOText.inputText;}
    std::string GetterOT()  {return storageIOText.outputText;}
    void Setter(std::string* value) {storageIOText.inputText = *value;}
    
    Cryptography(){}

    bool checkLengthForKey(){
        if (storageEncryptionCode.len_eng   != 130 ||
            storageEncryptionCode.len_engUp != 130 ||
            storageEncryptionCode.len_sym   != 165 ||
            storageEncryptionCode.len_dig   != 50 ||
            storageEncryptionCode.len_fst   != 60 ||
            storageEncryptionCode.len_snd   != 60 ||
            storageEncryptionCode.len_thrd  != 60)
            return false;
        defineLengthForKey();
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
        char            bufferForEng[130];          //
        char            bufferForEngUp[130];         //
        char            bufferForSymbols[165];         //          local variables  
        char            bufferForDigitals[50];          //                for
        char            bufferForFirstLevel[60];          //      storing temporary values.
        char            bufferForSecondLevel[60];          //
        char            bufferForThirdLevel[60];          //

        std::ifstream   fin;                // create stream for reading Alphabets from a file.
        fin.open(path);                     //open file
        if(fin.is_open())
        {
            
            fin.getline(bufferForEng, 131);     //
            fin.getline(bufferForEngUp, 131);    //
            fin.getline(bufferForSymbols, 166);    //      reading 
            fin.getline(bufferForDigitals, 51);     //        Alphabets
            fin.getline(bufferForFirstLevel, 61);     //
            fin.getline(bufferForSecondLevel, 61);     //
            fin.getline(bufferForThirdLevel, 61);     //
            fin.close();
        }
        else
        {
            std::cout << ". File opening error, check the correct path. [Read Alphabetsbase]" << '\n';
            return 1;
        }
        for (size_t j = 0, k = 0, p = 0; j < 33; j++)
        {
            for (size_t i = 0; i < 5; i++, k++)
            {
                if (j < 10) 
                {
                    storageEncryptionCode.digitals_crypto[j][i]=bufferForDigitals[k];
                }
                if (j < 26)
                {
                    storageEncryptionCode.english_crypto[j][i]=bufferForEng[k];             //write to global Alphabets
                    storageEncryptionCode.english_crypto_up[j][i]=bufferForEngUp[k]; 
                }
                if(j < 33)  
                {
                    storageEncryptionCode.symbols_crypto[j][i]=bufferForSymbols[k]; 
                }
            }
            if (j < 10)
            {
                for (size_t i = 0; i < 3; i++)
                {
                    for (size_t l = 0; l < 2; l++, p++)
                    {
                        storageEncryptionCode.fst_[j][i][l]  = bufferForFirstLevel[p];              //write to global Alphabets
                        storageEncryptionCode.snd_[j][i][l]  = bufferForSecondLevel[p];
                        storageEncryptionCode.thrd_[j][i][l] = bufferForThirdLevel[p];
                    }
                }
            }
        }
        storageEncryptionCode.len_eng   = strlen(bufferForEng);
        storageEncryptionCode.len_engUp = strlen(bufferForEngUp);
        storageEncryptionCode.len_sym   = strlen(bufferForSymbols);
        storageEncryptionCode.len_dig   = strlen(bufferForDigitals);
        storageEncryptionCode.len_fst   = strlen(bufferForFirstLevel);
        storageEncryptionCode.len_snd   = strlen(bufferForSecondLevel);
        storageEncryptionCode.len_thrd  = strlen(bufferForThirdLevel);
        return 0;
    }

    void append(int lvl, int index, int descript)  //function for append Alphabets in local variable
    {
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
            switch (randomSelect)
            {
            case 0:
                for (size_t i = 0; i < 2; i++)  
                    storageIOText.outputText += storageEncryptionCode.fst_[index][randomColumn][i];
                break;
            case 1:
                for (size_t i = 0; i < 2; i++)  
                    storageIOText.outputText += storageEncryptionCode.snd_[index][randomColumn][i];
                break;
            case 2:
                for (size_t i = 0; i < 2; i++)  
                    storageIOText.outputText += storageEncryptionCode.thrd_[index][randomColumn][i];
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
