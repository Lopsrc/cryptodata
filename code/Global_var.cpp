namespace PTHS                          //paths
{
    std::string         PATH;               // data base path.
    std::string         PATHR;              // file path. Read.
    std::string         PATHW;              // file path. Write.
};
namespace ST                            //action status
{
    unsigned int        action_c = 0;       // select action (1 - encryption, 2 -decryption, 0 - None).
    bool                enter_wk = true;    // true - keyboard input, false - file read. 
    bool                enter_it = true;    // true - console output, false - write to file.
    
};
enum COND                               //storage conditions
{
    RUS,
    RUS_UP,
    ENG,
    ENG_UP,
    SYM,
    DIG,
    FIRST_LVL,
    SECOND_LVL
};
namespace data                          //storage data
{
    const static int    var_eng                 =   26;       //symbols english length.
    const static int    var_sym                 =   33;       //symbols text length. 
    const static int    var_d1th                =   10;       //symbols digital length.
    const static int    var_col                 =   5;        
    const static int    var_2th                 =   3;         
    const static int    var_3th                 =   2;        
    const char          english[var_eng+1]      =   "abcdefghijklmnopqrstuvwxyz";           //alphabet.
    const char          english_up[var_eng+1]   =   "ABCDEFGHIJKLMNOPQRSTUVWXYZ";           //alphabet up. 
    const char          symbols[var_sym+1]      =   " .,:@!?;\"'()<>-[]{}#$^&+/\\|=~_%*`";  //symbols.
    const char          digitals[var_d1th+1]    =   "0123456789";                           //digitals.

    char                fst_[var_d1th][var_2th][var_3th];       //
    char                snd_[var_d1th][var_2th][var_3th];       //second level encryption.
    char                thrd_[var_d1th][var_2th][var_3th];      //

    char                digitals_crypto[var_d1th][var_col];     //
    char                english_crypto[var_eng][var_col];       //first level encryption.
    char                english_crypto_up[var_eng][var_col];    //    
    char                symbols_crypto[var_sym][var_col];       //

    std::string         text;           //for load crypto text.
    std::string         text2;          //

    std::string         input_text;     //input text.
    const std::string   keyw = "_N0_";  //line separator.
};
unsigned int strleny(std::string& str)  // calculating the length of an array.
{
    unsigned int  counter = 0;
    while(str[counter]!='\0'){counter++;}
    return counter;
}
void printv()                           //output text in terminal
{
    int size = strleny(data::text2);
    for (size_t i = 0; i < size; i++)
    {
        if (data::text2[i]==data::keyw[0])
            if (data::text2[i+1]==data::keyw[1])
                if (data::text2[i+2]==data::keyw[2])
                    if (data::text2[i+3]==data::keyw[3])      //keyword checking
                    {
                        std::cout << "\n";
                        i+=3;
                        continue;
                    }
        std::cout << data::text2[i];
    }
    std::cout << "\n";
}