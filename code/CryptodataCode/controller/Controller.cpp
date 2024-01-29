
struct InputArgs
{
    int                 cryptoAction  = COND::NOT_ACTION;   
    int                 inputOfText   = COND::CLI_IO;         
    int                 displayedText = COND::CLI_IO;         
    std::string         pathForReadToFile;                    
    std::string         pathForWriteToFile;                   
    std::string         pathToKey;
};

InputArgs processingArgs(int argc, char** argv){
    InputArgs inputArgs;
    if (argc==1 || (argc==2 && argv[1]!="-h"))        
    {
        printErr(argv[0]);
        exit(1);
    }
    else if (argc==2)
    {
        printh();
        exit(1);
    }
    else if (argc >= 3)
    {
        if(std::string(argv[2])=="-e")  inputArgs.cryptoAction = COND::ENCRYPTION;                      
        if(std::string(argv[2])=="-d")  inputArgs.cryptoAction = COND::DECRYPTION;
        
        if (argc == 5)
        {
            if((std::string(argv[3])=="--wf"))
            {   
                inputArgs.pathForWriteToFile = std::string(argv[4]);   
                inputArgs.displayedText      = COND::FILE_IO;
            }
            if((std::string(argv[3])=="--rf"))
            {   
                inputArgs.pathForReadToFile = std::string(argv[4]);    
                inputArgs.inputOfText       = COND::FILE_IO;
            }
        }
        else if (argc == 7)
        {
            if((std::string(argv[3])=="--rf"))
            {   
                inputArgs.pathForReadToFile = std::string(argv[4]);    
                inputArgs.displayedText     = COND::FILE_IO;
            }
            if(std::string(argv[5])=="--wf")
            {
                inputArgs.pathForWriteToFile = std::string(argv[6]);   
                inputArgs.inputOfText        = COND::FILE_IO;
            }
        }
        inputArgs.pathToKey = argv[1];
        return inputArgs;
    }
    return inputArgs;
}

int Controller(InputArgs inputArgs)        
{
    StorageIOText storageIOText;
    CryptographyEnglish cryptography;

    cryptography.writeToCache(inputArgs.pathToKey);
    if (!(cryptography.checkCryptoKey()))
    {
        std::cout << "Key not valid." << std::endl;
        exit(1);
    }

    if(inputArgs.inputOfText == COND::CLI_IO)
    {
        std::cout << "Enter text: ";
        std::getline(std::cin, storageIOText.inputText);   
        cryptography.Setter(&storageIOText.inputText);

    }
    else if(inputArgs.inputOfText == COND::FILE_IO) {
        ReadFromFile readFromFile = readFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
        if (readFromFile.codeError==1)
        {
            std::cout << "Data reading error. Check the path." << std::endl;
            exit(1); 
        }
        storageIOText.inputText = readFromFile.inputText;                     
        cryptography.Setter(&storageIOText.inputText);
    }
    if      (inputArgs.cryptoAction==COND::ENCRYPTION)   {cryptography.encryption();}                   
    else if (inputArgs.cryptoAction==COND::DECRYPTION)   {cryptography.decryption();}                   
    
    if (!(cryptography.checkSum(inputArgs.cryptoAction)))
    {
        std::cout << "Input and output text not equal." << std::endl;
        exit(1);
    }
    
    if (inputArgs.displayedText == COND::CLI_IO)
    {
        storageIOText.inputText = cryptography.GetterOT();
        std::cout << "Output text:\n" << std::endl;
        printResult(storageIOText.inputText);
        std::cout <<  "\nEnd\n";                   
    }
    else     
    {
        storageIOText.inputText = cryptography.GetterOT();
        if(!(writeToFile(inputArgs.pathForWriteToFile, storageIOText.inputText)))
        {
            std::cout << "Data writing error. Check the path." << std::endl;
            exit(1); 
        }
    }
    return 0;
}
