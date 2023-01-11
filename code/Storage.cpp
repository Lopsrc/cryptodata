namespace PTHS                          //*paths   MAKE STRUCT, NOT LOCAL VARIABLE!!!!!!!!!!!!!!!!!!
{
    std::string         PATHR;              // file path. Read.
    std::string         PATHW;              // file path. Write.
};
namespace ST                            //action status
{
    unsigned int       action_c = 0;       // select action (1 - encryption, 2 -decryption, 0 - None).
    int                enter_wk = 2;    // true - keyboard input, false - file read. 
    int                enter_it = 2;    // true - console output, false - write to file.
    
};
struct StorageIOText{
    std::string         inputText;
    std::string         outputText;
};
struct StorageEncryptionCode {
    char                fst_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //
    char                snd_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //second level encryption.
    char                thrd_[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];      //

    char                encryptionThirdLevelFirstCode[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //
    char                encryptionThirdLevelSecondCode[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];       //third level encryption.
    char                encryptionThirdLevelThirdCode[Alphabets::var_d1th][Alphabets::var_2th][Alphabets::var_3th];      //

    char                digitals_crypto[Alphabets::var_d1th][Alphabets::var_col];     //
    char                english_crypto[Alphabets::var_eng][Alphabets::var_col];       //first level encryption.
    char                english_crypto_up[Alphabets::var_eng][Alphabets::var_col];    //    
    char                symbols_crypto[Alphabets::var_sym][Alphabets::var_col];       //

    char                digitals_crypto_Fourth[Alphabets::var_d1th][Alphabets::var_col];     //
    char                english_crypto_Fourth[Alphabets::var_eng][Alphabets::var_col];       //Fourth level encryption.
    char                english_crypto_up_Fourth[Alphabets::var_eng][Alphabets::var_col];    //    
    char                symbols_crypto_Fourth[Alphabets::var_sym][Alphabets::var_col];       //
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

namespace Alphabets                          //storage Alphabets
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
    const std::string   keyw = "_N0_";  //line separator.
};
