
struct StorageGenerate
{
    std::string                 secondLevelFirstVersion;             //second level
    std::string                 secondLevelSecondVersion;             //
    std::string                 secondLevelThirdVersion;             //
    
    std::vector<int>            firstLevelCode;                             //storage buffer
};
struct StorageGenerateIndexes
{
    int             generateIndexFirst;                //variables for generate
    int             generateIndexSecond;               //
};
struct LengthOfAllSymbols
{
    int lenOfDownLetters, lenOfUpLetters, lenOfSymbols, lenOfDigitals;
};

class Generate
{
protected:
    StorageGenerate         storageKeys;
    StorageGenerateIndexes  storageIndexes;
    LengthOfAllSymbols      LengthOfSymbols;
    
    std::string             buffer;                         //Storing intermediate calculations.
    int                     quantityAllSymbols;
    const int               MIN = 10000, MAX = 99999;       //The range of values for generating the first key.
    int                     gen;                            //For generating the first key.

public:
    virtual void            generateIndexes()               = 0;
    virtual void            pushToBuffer()                  = 0;

    virtual bool            checkSameFirstLevel()           = 0;
    virtual bool            checkLengthOfKey()              = 0;

    virtual bool            checkSameSecondLevel()          = 0;
    virtual int             GenerateFirstEncryptionCode()   = 0;
    virtual int             GenerateSecondEncryptionCode()  = 0;

    StorageGenerate&        Getter()     {return storageKeys;}
    bool                     WriteKeyToFile(std::string& path)
    {
        std::ofstream fout;
        fout.open(path);      //open file
        if(fout.is_open())
        {
            //Writing the first key to the file.
            for (size_t i = 0; i < quantityAllSymbols; i++)
            {
                if ((i==LengthOfSymbols.lenOfDownLetters) || 
                    (i==LengthOfSymbols.lenOfDownLetters+LengthOfSymbols.lenOfUpLetters) || 
                    (i==LengthOfSymbols.lenOfDownLetters+LengthOfSymbols.lenOfUpLetters+LengthOfSymbols.lenOfSymbols)
                    )
                    fout << "\n";                         //Move to the next line if the key has ended.
                fout << storageKeys.firstLevelCode[i];                    
            }
            fout << "\n";
            
            //Writing the second key to the file. 
            fout << storageKeys.secondLevelFirstVersion;        
            fout << "\n";
            
            fout << storageKeys.secondLevelSecondVersion;       
            fout << "\n";
            
            fout << storageKeys.secondLevelThirdVersion;        
            fout.close();
        }
        else
        {
            std::cout << ". File opening error, check the correct path.[Read Alphabetsbase]" << '\n';
            return false;
        }
        return true;
    }
};


class GenerateEnglishCode:public Generate
{
private:
    void generateIndexes()
    {
        storageIndexes.generateIndexFirst   = 32 +(rand() % 95);    //range (32-126) 
        storageIndexes.generateIndexSecond  = 32 +(rand() % 95);    //for ASCII table.
    }
    void pushToBuffer()
    {
        buffer.clear();
        buffer.push_back(char(storageIndexes.generateIndexFirst));
        buffer.push_back(char(storageIndexes.generateIndexSecond));
    }
    
    bool checkSameFirstLevel()
    {
        for(int i = 0; i<storageKeys.firstLevelCode.size(); i++)
        {
            if (storageKeys.firstLevelCode[i]==gen)         
                return false;
        }
        return true;
    }
    
    int GenerateFirstEncryptionCode()
    {
        for(int i = 0;i < quantityAllSymbols; i++)
        {
            gen = MIN + rand() % (MAX - MIN);           //random number generation
            if (storageKeys.firstLevelCode.empty())                       
            {
                storageKeys.firstLevelCode.push_back(gen);      
                continue;
            }
            if (checkSameFirstLevel())           
            {                         
                storageKeys.firstLevelCode.push_back(gen);
                continue;
            }
            i--;
        }
        return 0;
    }

    int GenerateSecondEncryptionCode()
    {
        for (size_t i = 0; i < 30; i++)
        {
            generateIndexes();                  
            pushToBuffer();

            if (i==0)
            {
                storageKeys.secondLevelFirstVersion.append(buffer);
                continue;
            }
            if (checkSameSecondLevel())
            {
                i--;
                continue;
            }
            storageKeys.secondLevelFirstVersion.append(buffer);
        }
        for (size_t i = 0; i < 30; i++)
        {
            generateIndexes();   
            pushToBuffer();
            
            if (i==0)
            {
                storageKeys.secondLevelSecondVersion.append(buffer);
                continue;
            }
            if (checkSameSecondLevel())
            {
                i--;
                continue;
            }
            storageKeys.secondLevelSecondVersion.append(buffer);
        }
        for (size_t i = 0; i < 30; i++)
        {
            generateIndexes();
            pushToBuffer();
            
            if (i==0)
            {
                storageKeys.secondLevelThirdVersion.append(buffer);
                continue;
            }
            if (checkSameSecondLevel())
            {   
                i--;
                continue;
            }
            storageKeys.secondLevelThirdVersion.append(buffer);
        }
        return 0;
    }
    
    bool checkSameSecondLevel()
    {
        return storageKeys.secondLevelFirstVersion.find(buffer)!=-1 || storageKeys.secondLevelSecondVersion.find(buffer)!=-1 || storageKeys.secondLevelThirdVersion.find(buffer)!=-1;
    }
public:
    GenerateEnglishCode(){
        quantityAllSymbols                  = 95;
        LengthOfSymbols.lenOfDownLetters    = 26;
        LengthOfSymbols.lenOfUpLetters      = 26;
        LengthOfSymbols.lenOfSymbols        = 33;
        LengthOfSymbols.lenOfDigitals       = 10;
    };
    
    bool checkLengthOfKey(){
        if (storageKeys.secondLevelFirstVersion.length() != 60 ||
            storageKeys.secondLevelSecondVersion.length()!= 60 ||
            storageKeys.secondLevelThirdVersion.length() != 60 ||
            storageKeys.firstLevelCode.size() != quantityAllSymbols
            )
        {
            return false;
        }
        return true;
    }
    
    void generationCode()
    {
        GenerateFirstEncryptionCode();
        GenerateSecondEncryptionCode();
    }
};