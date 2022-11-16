
void append(int lvl, int m, int descript)  //function for append data in local variable
{
    if (lvl==COND::FIRST_LVL)
    {
        if      (descript==COND::ENG)           {for (size_t i = 0; i < 5; i++)  {data::text += data::english_crypto[m][i];}}
        else if (descript==COND::ENG_UP)        {for (size_t i = 0; i < 5; i++)  {data::text += data::english_crypto_up[m][i];}}
        else if (descript==COND::SYM)           {for (size_t i = 0; i < 5; i++)  {data::text += data::symbols_crypto[m][i];}}
        else if (descript==COND::DIG)           {for (size_t i = 0; i < 5; i++)  {data::text += data::digitals_crypto[m][i];}}
    }
    if (lvl==COND::SECOND_LVL)
    {
        int n = rand() % 3;                //generating a value for randomly selecting an array element
        int slct_ar = rand() % 3;          //generating a value for a random array selection
        if (slct_ar==0)         {for (size_t i = 0; i < 2; i++)  {data::text2 += data::fst_[m][n][i];}}
        else if (slct_ar==1)    {for (size_t i = 0; i < 2; i++)  {data::text2 += data::snd_[m][n][i];}}
        else if (slct_ar==2)    {for (size_t i = 0; i < 2; i++)  {data::text2 += data::thrd_[m][n][i];}}   
    }
}
int decryption_duble()                     //decryption second level
{
    int size = strleny(data::text);
    for (size_t j = 0; j < size; j++)      //search values
    {
        for (size_t k = 0; k < 26; k++)
        {
            if (data::text[j] == data::english_crypto[k][0])
            {   
                if(data::text[j+1] == data::english_crypto[k][1])
                {   
                    if(data::text[j+2] == data::english_crypto[k][2])
                    {   
                        if (data::text[j+3] == data::english_crypto[k][3])
                        {       
                            if (data::text[j+4] == data::english_crypto[k][4])
                            {
                                data::text2 += data::english[k];
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
            if (data::text[j] == data::english_crypto_up[k][0])
            {   
                if(data::text[j+1] == data::english_crypto_up[k][1])
                {   
                    if(data::text[j+2] == data::english_crypto_up[k][2])
                    {   
                        if (data::text[j+3] == data::english_crypto_up[k][3])
                        {       
                            if (data::text[j+4] == data::english_crypto_up[k][4])
                            {
                                data::text2 += data::english_up[k];
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
            if (data::text[j] == data::symbols_crypto[k][0])
            {   
                if(data::text[j+1] == data::symbols_crypto[k][1])
                {   
                    if(data::text[j+2] == data::symbols_crypto[k][2])
                    {   
                        if (data::text[j+3] == data::symbols_crypto[k][3])
                        {       
                            if (data::text[j+4] == data::symbols_crypto[k][4])
                            {
                                data::text2 += data::symbols[k];
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
            if (data::text[j] == data::digitals_crypto[k][0])
            {   
                if(data::text[j+1] == data::digitals_crypto[k][1])
                {   
                    if(data::text[j+2] == data::digitals_crypto[k][2])
                    {   
                        if (data::text[j+3] == data::digitals_crypto[k][3])
                        {       
                            if (data::text[j+4] == data::digitals_crypto[k][4])
                            {
                                data::text2 += data::digitals[k];
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
    int size = strleny(data::text);
    for (size_t j = 0; j < size; j++)   //search values
    {
        for (size_t i = 0; i < 10; i++)
        {
            if (data::text[j]==data::digitals[i])
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
    int   size  =  strleny(data::input_text);
    //search values
    for (size_t y = 0; y < size; y+=2)
    { 
        for (size_t i = 0; i < 10; i++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                if(data::input_text[y]==data::fst_[i][k][0])
                {
                    if (data::input_text[y+1]==data::fst_[i][k][1])
                    {
                        data::text += data::digitals[i]; 
                        i++;
                        break;
                    } 
                }
                if(data::input_text[y]==data::snd_[i][k][0])
                {
                    if (data::input_text[y+1]==data::snd_[i][k][1])
                    {
                        data::text += data::digitals[i]; 
                        i++;
                        break;
                    } 
                }
                if(data::input_text[y]==data::thrd_[i][k][0])
                {
                    if (data::input_text[y+1]==data::thrd_[i][k][1])
                    {
                        data::text += data::digitals[i]; 
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
    int  size  =  strleny(data::input_text);   
    for (size_t j = 0; j < size; j++)      //search values
    {
        for (size_t i = 0; i < 33; i++)
        {
            if (data::input_text[j]==data::symbols[i])
            {
                append(COND::FIRST_LVL ,i , COND::SYM);
                i = 0;
                break;
            }
            if (i < 10)
            {
                if (data::input_text[j]==data::digitals[i])
                {
                    append(COND::FIRST_LVL ,i , COND::DIG);
                    i = 0;
                    break;
                }
            }
            if (i < 26) {
                if (data::input_text[j]==data::english[i])
                {
                    append(COND::FIRST_LVL ,i , COND::ENG);
                    i = 0;
                    break;
                }
                if (data::input_text[j]==data::english_up[i])
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