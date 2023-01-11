struct StorageGenerate
{
    std::string                bufferFirst;             //second level
    std::string                bufferSecond;             //
    std::string                bufferThird;             //
    std::string                bufferSecondFirst;             //second level
    std::string                bufferSecondSecond;             //
    std::string                bufferSecondThird;

    // int                 buff1[Alphabets::eng];                     //first level
    // int                 buff2[Alphabets::eng];                     //
    // int                 buff3[Alphabets::sym];                     //
    // int                 buff4[Alphabets::dig];                     //
    std::vector<int>    FirstEncryptionLevel;                             //storage buffer
    std::vector<int>    ThirdEncryptionLevel;                             //storage buffer
};

//написать проверку двух векторов, внедрив ее в функцию четвертого шифрования

class GenerateEncryptionCode {
private:
    StorageGenerate storageCode;
    // int                 ar_check[91][2];
    int                 gen_tmp;                        //variable for generate first level
    
    bool check(int& size, int codeStation)
    {
        unsigned i = 0;
        
        if(codeStation == 1){
            while (i<size)
        {
            if (storageCode.FirstEncryptionLevel[i]==gen_tmp)         //equality check
                return false;
            i++;
        }
        }
        if(codeStation == 2){
            while (i<size)
            {
                if ((storageCode.FirstEncryptionLevel[i]==gen_tmp) || (storageCode.ThirdEncryptionLevel[i] == gen_tmp))         //equality check
                return false;
                i++;
            }
        }
        
        return true;
    }
    // bool check(int& firstEncryptionCode, int& secondEncryptionCode)
    // {
    //     int counter = 0;
    //     for (size_t i = 0; i < strleny(); i++)
    //     {
    //         if (storageCode.buffer_frst[i][0]==firstEncryptionCode)
    //         {
    //             if (storageCode.buffer_frst[i][1]==secondEncryptionCode)    //equality check
    //                 return false;
    //         }
    //         if (i == strleny()-1)
    //         {
    //             ar_check[i][0] == 100;        //keyword adding (for counting numbers)
    //             return true;
    //         }   
    //     }
    //     return false;
    // }
    // int strleny()
    // {
    //     int counter = 0;
    //     while (true)
    //     {
    //         if (ar_check[counter][0]==100)
    //             break;
    //         counter++;
    //     }
    //     return counter;
    // }

public:
    void Printer(){
        std::cout << "bufferFirst  = " <<  storageCode.bufferFirst << std::endl;
        std::cout << "bufferSecond = " << storageCode.bufferSecond << std::endl;
        std::cout << "bufferThird  = " << storageCode.bufferThird << std::endl;
        std::cout << "bufferSecondFirst  = " <<  storageCode.bufferSecondFirst << std::endl;
        std::cout << "bufferSecondSecond = " << storageCode.bufferSecondSecond << std::endl;
        std::cout << "bufferSecondThird  = " << storageCode.bufferSecondThird << std::endl;
        std::cout << "FirstEncryptionLevel" << std::endl;
        for (size_t i = 0; i < storageCode.FirstEncryptionLevel.size(); i++)
        {
            std::cout << storageCode.FirstEncryptionLevel[i];
        }
        std::cout << "ThirdEncryptionLevel" << std::endl;
        for (size_t i = 0; i < storageCode.ThirdEncryptionLevel.size(); i++)
        {
            std::cout << storageCode.ThirdEncryptionLevel[i];
        }
        std::cout << std::endl;
        // std::cout << "bufferSecondSecond = " << storageCode.bufferSecondSecond << std::endl;
        // std::cout << "bufferSecondThird  = " << storageCode.bufferSecondThird << std::endl;
    }
    StorageGenerate& Getter(){
        return storageCode;
    }

    int GenerateFirstEncryptionCode(){
    const int quantity = 95;                        //number of characters
    int i = 0;
    int size = 0;
    while (i < quantity)
    {
        const int min = 10000, max = 99999;         //range numbers
        size = storageCode.FirstEncryptionLevel.size(); 
        START:
        gen_tmp = min + rand() % (max - min); //generate random number
        if (storageCode.FirstEncryptionLevel.empty())                       
        {
            storageCode.FirstEncryptionLevel.push_back(gen_tmp);      
            i++;
            continue;
        }
        else if (check(size, 1))                            //true - not equal
        {
            storageCode.FirstEncryptionLevel.push_back(gen_tmp);
        }
        else
            goto START;
        i++;
    }
    return 0;
    }

int GenerateSecondEncryptionCode()
{
    int             generateIndex;                //variables for generate
    int             generateIndexSecond;               //
    // int             size = 0;
    std::string     buffer;
    const int       quantity = 181;         //quantity characters
    
    for (size_t i = 0; i < 30; i++)
    {
        START: 
        generateIndex  = rand() % 95;
        generateIndexSecond= rand() % 95;
        
        buffer.clear();
        buffer.push_back(Alphabets::symbols[generateIndex]);
        buffer.push_back( Alphabets::symbols[generateIndexSecond]);
    
        if (i==0)
        {
            storageCode.bufferFirst.append(buffer);
            continue;
        }
        if (storageCode.bufferFirst.find(buffer)!=-1)   {
            std::cout << "Найден символ " << buffer  << std::endl;
            goto START;
        }
        storageCode.bufferFirst.append(buffer);
    }
    
    for (size_t i = 0; i < 30; i++)
    {
        START2:
        generateIndex  = rand() % 95;
        generateIndexSecond= rand() % 95;
        
        buffer.clear();
        buffer.push_back(Alphabets::symbols[generateIndex]);
        buffer.push_back(Alphabets::symbols[generateIndexSecond]);
        
        if (i==0)
        {
            storageCode.bufferSecond.append(buffer);
            continue;
        }
        if (storageCode.bufferFirst.find(buffer)!=-1)   
        {
            std::cout << "Найден символ "<< buffer  << std::endl;
            goto START2;
        }
        if (storageCode.bufferSecond.find(buffer)!=-1)  {
            std::cout << "Найден символ "<< buffer  << std::endl;
            goto START2;}

        storageCode.bufferSecond.append(buffer);
    }
    for (size_t i = 0; i < 30; i++)
    {
        START3: 
        generateIndex  = rand() % 95;
        generateIndexSecond= rand() % 95;
        
        buffer.clear();
        buffer.push_back(Alphabets::symbols[generateIndex]);
        buffer.push_back( Alphabets::symbols[generateIndexSecond]);
        
        if (i==0)
        {
            storageCode.bufferThird.append(buffer);
            continue;
        }
        if (storageCode.bufferFirst.find(buffer)!=-1)   {
            std::cout << "Найден символ " << buffer << std::endl;
            goto START3;}
        if (storageCode.bufferSecond.find(buffer)!=-1)  {
            std::cout << "Найден символ "<< buffer  << std::endl;
            goto START3;}
        if (storageCode.bufferThird.find(buffer)!=-1)   {
            std::cout << "Найден символ "<< buffer  << std::endl;
            goto START3;}
        storageCode.bufferThird.append(buffer);
    }
    return 0;
    }
int GenerateThirdEncryptionCode(){
    int             generateIndex;                //variables for generate
    int             generateIndexSecond;               //
    // int             size = 0;
    std::string     buffer;
    const int       quantity = 181;         //quantity characters
    
    for (size_t i = 0; i < 30; i++)
    {
        START5: 
        generateIndex  = rand() % 95;
        generateIndexSecond= rand() % 95;
        
        buffer.clear();
        buffer.push_back(Alphabets::symbols[generateIndex]);
        buffer.push_back( Alphabets::symbols[generateIndexSecond]);
    
        if (i==0)
        {
            storageCode.bufferSecondFirst.append(buffer);
            continue;
        }
        if (storageCode.bufferSecondFirst.find(buffer)!=-1)   {
            std::cout << "Найден символ " << buffer  << std::endl;
            goto START5;
        }
        storageCode.bufferSecondFirst.append(buffer);
    }
    
    for (size_t i = 0; i < 30; i++)
    {
        START6:
        generateIndex  = rand() % 95;
        generateIndexSecond= rand() % 95;
        
        buffer.clear();
        buffer.push_back(Alphabets::symbols[generateIndex]);
        buffer.push_back(Alphabets::symbols[generateIndexSecond]);
        
        if (i==0)
        {
            storageCode.bufferSecondSecond.append(buffer);
            continue;
        }
        if (storageCode.bufferSecondSecond.find(buffer)!=-1)   
        {
            std::cout << "Найден символ "<< buffer  << std::endl;
            goto START6;
        }
        if (storageCode.bufferSecondFirst.find(buffer)!=-1)  {
            std::cout << "Найден символ "<< buffer  << std::endl;
            goto START6;}

        storageCode.bufferSecondSecond.append(buffer);
    }
    for (size_t i = 0; i < 30; i++)
    {
        START7: 
        generateIndex  = rand() % 95;
        generateIndexSecond= rand() % 95;
        
        buffer.clear();
        buffer.push_back(Alphabets::symbols[generateIndex]);
        buffer.push_back( Alphabets::symbols[generateIndexSecond]);
        
        if (i==0)
        {
            storageCode.bufferSecondThird.append(buffer);
            continue;
        }
        if (storageCode.bufferSecondFirst.find(buffer)!=-1)   {
            std::cout << "Найден символ " << buffer << std::endl;
            goto START7;}
        if (storageCode.bufferSecondSecond.find(buffer)!=-1)  {
            std::cout << "Найден символ "<< buffer  << std::endl;
            goto START7;}
        if (storageCode.bufferSecondThird.find(buffer)!=-1)   {
            std::cout << "Найден символ "<< buffer  << std::endl;
            goto START7;}
        storageCode.bufferSecondThird.append(buffer);
    }
    return 0;
}

int GenerateFourthEncryptionCode(){
    const int quantity = 95;                        //number of characters
    int i = 0;
    int size = 0;
    while (i < quantity)
    {
        const int min = 10000, max = 99999;         //range numbers
        size = storageCode.ThirdEncryptionLevel.size(); 
        START:
        gen_tmp = min + rand() % (max - min); //generate random number
        if (storageCode.ThirdEncryptionLevel.empty())                       
        {
            storageCode.ThirdEncryptionLevel.push_back(gen_tmp);      
            i++;
            continue;
        }
        else if (check(size, 2))                            //true - not equal
        {
            storageCode.ThirdEncryptionLevel.push_back(gen_tmp);
        }
        else
            goto START;
        i++;
    }
    return 0;
    }

};


