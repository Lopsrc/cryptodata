

//Реализовать запись данных в кеш в виде класса WriteToCache

class Cryptography{
private:
    size_t size;

    std::string inputText;
    std::string buffer;
    std::string outputText; 
protected:
    char                fst_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //
    char                snd_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //second level encryption.
    char                thrd_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];      //

    char                digitals_crypto[Alphabets::var_d1th][Alphabets::var_col];     //
    char                english_crypto[Alphabets::var_eng][Alphabets::var_col];       //first level encryption.
    char                english_crypto_up[Alphabets::var_eng][Alphabets::var_col];    //    
    char                symbols_crypto[Alphabets::var_sym][Alphabets::var_col];       //
public:
    std::string Getter(){
        return inputText;
    }
    void Setter(std::string* value){
        inputText = *value;
    }
    Cryptography(std::string* value){
        inputText = *value;
    }
     Cryptography(std::string value){
        inputText = value;
    }
    void append(int lvl, int m, int descript)  //function for append Alphabets in local variable
    {
        if (lvl==COND::FIRST_LVL)
        {
            if      (descript==COND::ENG)           {for (size_t i = 0; i < 5; i++)  {buffer += english_crypto[m][i];}}
            else if (descript==COND::ENG_UP)        {for (size_t i = 0; i < 5; i++)  {buffer += english_crypto_up[m][i];}}
            else if (descript==COND::SYM)           {for (size_t i = 0; i < 5; i++)  {buffer += symbols_crypto[m][i];}}
            else if (descript==COND::DIG)           {for (size_t i = 0; i < 5; i++)  {buffer += digitals_crypto[m][i];}}
        }
        if (lvl==COND::SECOND_LVL)
        {
            int       n = rand() % 3;                //generating a value for randomly selecting an array element
            int slct_ar = rand() % 3;          //generating a value for a random array selection
            if      (slct_ar==0)    {for (size_t i = 0; i < 2; i++)  {outputText += fst_[m][n][i];}}
            else if (slct_ar==1)    {for (size_t i = 0; i < 2; i++)  {outputText += snd_[m][n][i];}}
            else if (slct_ar==2)    {for (size_t i = 0; i < 2; i++)  {outputText += thrd_[m][n][i];}}   
        }
    }
    int decryption_duble()                     //decryption second level
    {
        // int size = strleny(buffer);
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
    int encryption_duble()                     //encryption second level
    {
        // int size = strleny(buffer);
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
        return 0;
    }
    int decryption()                           //decryption first level
    {
        // int   size  =  strleny(inputText);
        //search values
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
        decryption_duble();       //decryption second level
        return 0;
    }
    int encryption()                           //encryption first level
    {
        // int  size  =  strleny();   
        for (size_t j = 0; j < size; j++)      //search values
        {
            for (size_t i = 0; i < 33; i++)
            {
                if (inputText[j]==Alphabets::symbols[i])
                {
                    append(COND::FIRST_LVL ,i , COND::SYM);
                    i = 0;
                    break;
                }
                if (i < 10)
                {
                    if (inputText[j]==Alphabets::digitals[i])
                    {
                        append(COND::FIRST_LVL ,i , COND::DIG);
                        i = 0;
                        break;
                    }
                }
                if (i < 26) {
                    if (inputText[j]==Alphabets::english[i])
                    {
                        append(COND::FIRST_LVL ,i , COND::ENG);
                        i = 0;
                        break;
                    }
                    if (inputText[j]==Alphabets::english_up[i])
                    {
                        append(COND::FIRST_LVL ,i , COND::ENG_UP);
                        i = 0;
                        break;
                    }
                }   
            }
        }
        encryption_duble(); //encryption second level
        return 0;
    }
};

class WriterToCache:public Cryptography{
private:

    
public:
    
    
};
