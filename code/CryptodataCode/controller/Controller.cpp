
struct InputArgs
{
    int cryptoAction    = COND::NOT_ACTION;   
    int inputOfText     = COND::CLI_IO;            //true - by keyboard, false - from a file.
    int displayedText   = COND::CLI_IO;          //true - writing to the file, false - printing in the terminal.
    std::string         pathForReadToFile;              // file path. Read.
    std::string         pathForWriteToFile;              // file path. Write.
    std::string         pathToKey;
};


InputArgs processingArgs(int argc, char** argv){
    InputArgs inputArgs;
    if (argc==1 || (argc==2 && argv[1]!="-h"))        //check input arguments
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
        if(std::string(argv[2])=="-e")  inputArgs.cryptoAction = COND::ENCRYPTION;                       //variable that stores the state(-e - encryption (=1))
        if(std::string(argv[2])=="-d")  inputArgs.cryptoAction = COND::DECRYPTION;
        
        if (argc == 5)
        {
            if((std::string(argv[3])=="--wf"))
            {   
                inputArgs.pathForWriteToFile = std::string(argv[4]);     //path for writing a Alphabets from file
                inputArgs.displayedText = COND::FILE_IO;
            }
            if((std::string(argv[3])=="--rf"))
            {   
                inputArgs.pathForReadToFile = std::string(argv[4]);     //path for reading a Alphabets from file
                inputArgs.inputOfText = COND::FILE_IO;
            }
            
        }
        else if (argc == 7)
        {
            if((std::string(argv[3])=="--rf"))
            {   
                inputArgs.pathForReadToFile = std::string(argv[4]);     //path for reading a Alphabets from file
                inputArgs.displayedText = COND::FILE_IO;
            }
            if(std::string(argv[5])=="--wf")
            {
                inputArgs.pathForWriteToFile = std::string(argv[6]);     //path for write Alphabets to file
                inputArgs.inputOfText = COND::FILE_IO;
            }
        }
        inputArgs.pathToKey = argv[1];
        return inputArgs;
    }
    return inputArgs;
}

int Controller(InputArgs inputArgs)        //function for manage application
{
    StorageIOText storageIOText;
    CryptographyEnglish cryptography;

    cryptography.write_to_cache(inputArgs.pathToKey);
    if (!(cryptography.checkCryptoKey()))
    {
        std::cout << "Key not valid" << std::endl;
        exit(1);
    }

    if(inputArgs.inputOfText == COND::CLI_IO)
    {
        std::cout << "Enter text: ";
        std::getline(std::cin, storageIOText.inputText);   //entering text using the keyboard  
        cryptography.Setter(&storageIOText.inputText);

    }
    else if(inputArgs.inputOfText == COND::FILE_IO) {
        ReadFromFile buffer = readFromFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
        if (buffer.codeError==1)
        {
            exit(1); //TODO
        }
        
        storageIOText.inputText = buffer.inputText;                     //reading text from a file
        cryptography.Setter(&storageIOText.inputText);
    }
    if      (inputArgs.cryptoAction==COND::ENCRYPTION)   {cryptography.encryption();}                   //encryption first level
    else if (inputArgs.cryptoAction==COND::DECRYPTION)   {cryptography.decryption();}                   //decryption first level
    
    if (!(cryptography.checkSum(inputArgs.cryptoAction)))
    {
        std::cout << "Входной и выходной тексты не эквивалентны" << std::endl;
        exit(1);
    }
    
    if (inputArgs.displayedText == COND::CLI_IO)
    {
        storageIOText.inputText = cryptography.GetterOT();
        std::cout << "Output text:\n" << "Begin\n\n";
        printResult(storageIOText.inputText);
        std::cout <<  "\nEnd\n";                   //writing Alphabets to a file
    }
    else     //print in terminal
    {
        storageIOText.inputText = cryptography.GetterOT();
        if(writeToFile(inputArgs.pathForWriteToFile, storageIOText.inputText)==1){
            exit(1); //TODO
        }
    }
    return 0;
}
