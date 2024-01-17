enum COND                               //storage conditions
{
    RUS,
    RUS_UP,
    ENG,
    ENG_UP,
    SYM,
    DIG,
    FIRST_LVL,
    SECOND_LVL,
    NOT_ACTION = 0,
    ENCRYPTION = 1,
    DECRYPTION = 2
};

struct InputArgs
{
    int cryptoAction = COND::NOT_ACTION;   
    bool inputOfText = true;            //true - by keyboard, false - from a file.
    bool displayedText = true;          //true - writing to the file, false - printing in the terminal.
    std::string         pathForReadToFile;              // file path. Read.
    std::string         pathForWriteToFile;              // file path. Write.
    std::string pathToKey;
};

struct ReadFromFile
{
    std::string inputText;  //Text from the file.
    int codeError;          //true - 0 (no errors), false - 1.
};

struct StorageIOText{
    std::string         inputText;
    std::string         outputText;
};

namespace Alphabets                          //storage Alphabets
{       
    const char          english[27]      =   "abcdefghijklmnopqrstuvwxyz";           //alphabet.
    const char          english_up[27]   =   "ABCDEFGHIJKLMNOPQRSTUVWXYZ";           //alphabet up. 
    const char          symbols[34]      =   " .,:@!?;\"'()<>-[]{}#$^&+/\\|=~_%*`";  //symbols.
    const char          digitals[11]    =   "0123456789";                           //digitals.
    const std::string   keyw = "_N0_";  //line separator.
};

struct StorageEncryptionCodeNew {
    std::string                firstLayerForSecondLevel;       //
    std::string                secondLayerForSecondLevel;      //second level encryption.
    std::string                thirdLayerForSecondLevel;      //

    std::string                englishCryptoKey;       //first level encryption.
    std::string                englishUpCryptoKey;    //    
    std::string                symbolsCryptoKey;       //
    std::string                digitalsCryptoKey;     //
};

struct StorageEncryptionCode {
    char                fst_[10][3][2];       //
    char                snd_[10][3][2];       //second level encryption.
    char                thrd_[10][3][2];      //

    char                digitals_crypto[10][5];     //
    char                english_crypto[26][5];       //first level encryption.
    char                english_crypto_up[26][5];    //    
    char                symbols_crypto[33][5];       //
    int len_fst, len_snd, len_thrd, len_dig, len_eng, len_engUp, len_sym = 0; 
};



