enum COND                               //storage conditions
{
    NOT_ACTION,
    ENCRYPTION,
    DECRYPTION,
    CLI_IO,
    FILE_IO,
    ENG_UP,
    ENG,
    SYM,
    DIG
};
struct StorageIOText{
    std::string         inputText;
    std::string         outputText;
    void resettingTheValue()
    {
        inputText.clear();
        outputText.clear();
    }
};
struct StorageEncryptionCodeNew {
    std::string                firstLayerForSecondLevel;        //
    std::string                secondLayerForSecondLevel;      //second level encryption.
    std::string                thirdLayerForSecondLevel;      //

    std::string                englishCryptoKey;       //first level encryption.
    std::string                englishUpCryptoKey;    //    
    std::string                symbolsCryptoKey;     //
    std::string                digitalsCryptoKey;   //
};
struct IteratorsASCII
{
    std::vector<int> itEnglish;
    std::vector<int> itEnglishUp;
    std::vector<int> itSymbols;
    std::vector<int> itDigitals;
    IteratorsASCII() : itEnglish(26), itEnglishUp(26), itSymbols(33), itDigitals(10) 
    {
        int j = 32;
        for (size_t i = 0; i < 33; i++, j++)
        {
            if (j==48)
                j = 58;
            else if (j==65 || j==97)
                j+=26;
             
            itSymbols[i] = j;
        }

        j = 65;
        for (size_t i = 0; i < 26; i++, j++)
            itEnglishUp[i] = j;

        j = 97;
        for (size_t i = 0; i < 26; i++, j++)
            itEnglish[i] = j;

        j = 48;
        for (size_t i = 0; i < 10; i++, j++)         
            itDigitals[i] = j;
    }
};


class Cryptography{
protected:
    std::string         bufferClipboard;
    StorageIOText       storageIOText; 

public:
    virtual void appendForEncryption(int index, int descript)   = 0;
    virtual void appendForEncryption(int index)                 = 0;

    virtual bool appendForDecryption(int indexInputText)        = 0;
    virtual bool appendForDecryptionSecond(int indexInputText)  = 0;
    virtual bool checkLengthForKey()                            = 0;
    virtual bool checkSum(int cryptoAction)                     = 0;
    virtual bool checkEqualOfKey()                              = 0;

    virtual int encryptionSecondLevel()                         = 0;
    virtual int decryptionSecondLevel()                         = 0;
    virtual int write_to_cache(std::string& path)               = 0;
    virtual int decryption()                                    = 0;
    virtual int encryption()                                    = 0;

    std::string GetterIT()                  {return storageIOText.inputText;}
    std::string GetterOT()                  {return storageIOText.outputText;}
    void        Setter(std::string* value)  {storageIOText.inputText = *value;}
    void        resettingTheValue()
    {
        storageIOText.resettingTheValue();
        bufferClipboard.clear();
    }
    
};

class CryptographyEnglish:public Cryptography{
private:
    StorageEncryptionCodeNew storageEncryptionCodeN;
    IteratorsASCII itASCII;

    bool checkLengthForKey(){
        if (
            storageEncryptionCodeN.englishCryptoKey.length()           != 130 ||
            storageEncryptionCodeN.englishUpCryptoKey.length()         != 130 ||
            storageEncryptionCodeN.symbolsCryptoKey.length()           != 165 ||
            storageEncryptionCodeN.digitalsCryptoKey.length()          != 50  ||
            storageEncryptionCodeN.firstLayerForSecondLevel.length()   != 60  ||
            storageEncryptionCodeN.secondLayerForSecondLevel.length()  != 60  ||
            storageEncryptionCodeN.thirdLayerForSecondLevel.length()   != 60
            )
            return false;
        return true;
    }
    bool checkEqualOfKey(){
        for (size_t i = 0; i < storageEncryptionCodeN.symbolsCryptoKey.length(); i+=5)
        {
            if (storageEncryptionCodeN.symbolsCryptoKey.find(storageEncryptionCodeN.symbolsCryptoKey.substr(i, 5)) ||
                storageEncryptionCodeN.englishCryptoKey.find(storageEncryptionCodeN.symbolsCryptoKey.substr(i, 5)) ||
                storageEncryptionCodeN.englishUpCryptoKey.find(storageEncryptionCodeN.symbolsCryptoKey.substr(i, 5)) ||
                storageEncryptionCodeN.digitalsCryptoKey.find(storageEncryptionCodeN.symbolsCryptoKey.substr(i, 5)))
            {
                return false;
            }
        }
        for (size_t i = 0; i < storageEncryptionCodeN.englishCryptoKey.length(); i+=5)
        {
            if (storageEncryptionCodeN.englishCryptoKey.find(storageEncryptionCodeN.englishCryptoKey.substr(i, 5)) ||
                storageEncryptionCodeN.englishUpCryptoKey.find(storageEncryptionCodeN.englishCryptoKey.substr(i, 5)) ||
                storageEncryptionCodeN.digitalsCryptoKey.find(storageEncryptionCodeN.englishCryptoKey.substr(i, 5)))
            {
                return false;
            }
        }
        for (size_t i = 0; i < storageEncryptionCodeN.englishUpCryptoKey.length(); i+=5)
        {
            if (storageEncryptionCodeN.englishUpCryptoKey.find(storageEncryptionCodeN.englishUpCryptoKey.substr(i, 5)) ||
                storageEncryptionCodeN.digitalsCryptoKey.find(storageEncryptionCodeN.englishUpCryptoKey.substr(i, 5)))
            {
                return false;
            }
        }
        for (size_t i = 0; i < storageEncryptionCodeN.digitalsCryptoKey.length(); i+=5)
        {
            if (storageEncryptionCodeN.digitalsCryptoKey.find(storageEncryptionCodeN.digitalsCryptoKey.substr(i, 5)))
            {
                return false;
            }
        }
        return true;
    }
    
    void appendForEncryption(int index, int descript)  //function for append Alphabets in local variable
    {
        int indexBegin = index * 5;
        if      (descript==COND::ENG)           {bufferClipboard += storageEncryptionCodeN.englishCryptoKey.substr(indexBegin, 5);}
        else if (descript==COND::ENG_UP)        {bufferClipboard += storageEncryptionCodeN.englishUpCryptoKey.substr(indexBegin, 5);}
        else if (descript==COND::SYM)           {bufferClipboard += storageEncryptionCodeN.symbolsCryptoKey.substr(indexBegin, 5);}
        else if (descript==COND::DIG)           {bufferClipboard += storageEncryptionCodeN.digitalsCryptoKey.substr(indexBegin, 5);}
    }
    void appendForEncryption(int index){
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
    bool appendForDecryption(int indexInputText){
        for (size_t i = 0; i < 60; i+=2)
        {
            if ((storageIOText.inputText.substr(indexInputText, 2)==storageEncryptionCodeN.firstLayerForSecondLevel.substr(i, 2)) || 
                (storageIOText.inputText.substr(indexInputText, 2)==storageEncryptionCodeN.secondLayerForSecondLevel.substr(i, 2)) ||
                (storageIOText.inputText.substr(indexInputText, 2)==storageEncryptionCodeN.thirdLayerForSecondLevel.substr(i, 2) ))
            {
                bufferClipboard += char(itASCII.itDigitals[i/6]); 
                return true;
            }
        }
        return false;
    }
    bool appendForDecryptionSecond(int indexInputText){
        for (size_t i = 0; i < 165; i+=5)
        {
            if (bufferClipboard.substr(indexInputText, 5)==storageEncryptionCodeN.symbolsCryptoKey.substr(i, 5))
            {
                storageIOText.outputText += char(itASCII.itSymbols[i/5]);
                return true;
            }
            else if (i<130 && bufferClipboard.substr(indexInputText, 5)==storageEncryptionCodeN.englishCryptoKey.substr(i, 5))
            {
                storageIOText.outputText += char(itASCII.itEnglish[i/5]);
                return true;
            }
            else if (i<130 && bufferClipboard.substr(indexInputText, 5)==storageEncryptionCodeN.englishUpCryptoKey.substr(i, 5))
            {
                storageIOText.outputText += char(itASCII.itEnglishUp[i/5]);
                return true;
            }
            else if (i<50 && bufferClipboard.substr(indexInputText, 5)==storageEncryptionCodeN.digitalsCryptoKey.substr(i, 5))
            {
                storageIOText.outputText += char(itASCII.itDigitals[i/5]);
                return true;
            }
        }
        return false;
    }

    int encryptionSecondLevel()                     //encryption second level
    {
        for (size_t j = 0; j < bufferClipboard.length(); j++)   //search values
        {  
            for (size_t i = 0; i < 10; i++)
            {
                if (bufferClipboard[j]==char(itASCII.itDigitals[i]))
                {
                    appendForEncryption(i);
                    i = 0;
                    break;
                }
            }
        }
        return 0;
    }
    int decryptionSecondLevel()                    //decryption second level
    {
        int flag = 0;
        for (size_t j = 0; j < bufferClipboard.length(); j+=5)      //search values
        {
            if (!(appendForDecryptionSecond(j))) {return 1;}
            else {continue;}
        }
        return 0;
    }

public:
    int write_to_cache(std::string& path)   //write Alphabets to global variable
    {
        std::ifstream   fin;                // create stream for reading Alphabets from a file.
        fin.open(path);                     //open file
        if(fin.is_open())
        {
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
        return 0;
    }
    
    bool checkCryptoKey()  {return checkEqualOfKey() || checkLengthForKey();}
    bool checkSum(int cryptoAction){
        if(cryptoAction == COND::ENCRYPTION && (storageIOText.inputText.length() != storageIOText.outputText.length()/10))
        {
            return false;
        }
        else if(cryptoAction == COND::DECRYPTION && (storageIOText.inputText.length() != storageIOText.outputText.length()*10))
        {
            return false;
        }
        return true;
    }

    int decryption()                           //decryption first level
    {
        for (size_t y = 0; y < storageIOText.inputText.length(); y+=2)
        { 
            if (!(appendForDecryption(y)))
            {
                std::cout << "The wrong from the decryption first Level. It from the appendForDecryption().";
                return 1;
            }
            else
                continue;
        }
        decryptionSecondLevel();       //decryption second level
        return 0;
    }
    int encryption()                          //encryption first level
    {  
        for (size_t j = 0; j < storageIOText.inputText.length(); j++)      //search values
        {
            for (size_t i = 0; i < 33; i++)
            {
                if (storageIOText.inputText[j]==char(itASCII.itSymbols[i]))
                {
                    appendForEncryption(i , COND::SYM);
                    i = 0;
                    break;
                }
                if (i < 10)
                {
                    if (storageIOText.inputText[j]==char(itASCII.itDigitals[i]))
                    {
                        appendForEncryption(i , COND::DIG);
                        i = 0;
                        break;
                    }
                }
                if (i < 26) {
                    if (storageIOText.inputText[j]==char(itASCII.itEnglish[i]))
                    {
                        appendForEncryption(i , COND::ENG);
                        i = 0;
                        break;
                    }
                    if (storageIOText.inputText[j]==char(itASCII.itEnglishUp[i]))
                    {
                        appendForEncryption(i , COND::ENG_UP);
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
