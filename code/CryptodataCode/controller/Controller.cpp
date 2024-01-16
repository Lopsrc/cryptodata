
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
        if(std::string(argv[2])=="-e")  inputArgs.cryptoAction = 1;                       //variable that stores the state(-e - encryption (=1))
        if(std::string(argv[2])=="-d")  inputArgs.cryptoAction = 2;
        
        if (argc == 5)
        {
            std::cout << 0001 << std::endl;
            if((std::string(argv[3])=="--wf"))
            {   
                inputArgs.pathForWriteToFile = std::string(argv[4]);     //path for writing a Alphabets from file
                inputArgs.displayedText = false;
            }
            if((std::string(argv[3])=="--rf"))
            {   
                inputArgs.pathForReadToFile = std::string(argv[4]);     //path for reading a Alphabets from file
                inputArgs.inputOfText = false;
            }
            
        }
        else if (argc == 7)
        {
            if((std::string(argv[3])=="--rf"))
            {   
                inputArgs.pathForReadToFile = std::string(argv[4]);     //path for reading a Alphabets from file
                inputArgs.displayedText = false;
            }
            if(std::string(argv[5])=="--wf")
            {
                inputArgs.pathForWriteToFile = std::string(argv[6]);     //path for write Alphabets to file
                inputArgs.inputOfText = false;
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
    if (!(cryptography.checkLengthForKey()))
    {
        std::cout << "Key not valid" << std::endl;
        exit(1);
    }
    
    if(inputArgs.inputOfText)
    {
        std::cout << "Enter text: ";
        std::getline(std::cin, storageIOText.inputText);   //entering text using the keyboard  
        cryptography.Setter(&storageIOText.inputText);

    }
    else {
        ReadFromFile buffer = readFromFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
        if (buffer.codeError==1)
        {
            exit(1); //TODO
        }
        
        storageIOText.inputText = buffer.inputText;                     //reading text from a file
        cryptography.Setter(&storageIOText.inputText);
    }
    if      (inputArgs.cryptoAction==1)   {cryptography.encryption();}                   //encryption first level
    else if (inputArgs.cryptoAction==2)   {cryptography.decryption();}                   //decryption first level
    
    if (!(cryptography.checkSum(inputArgs.cryptoAction)))
    {
        std::cout << "Входной и выходной тексты не эквивалентны" << std::endl;
        exit(1);
    }
    
    if (inputArgs.displayedText)
    {
        storageIOText.inputText = cryptography.GetterOT();
        std::cout << "Output text:\n" << "Begin\n\n";
        printResult(storageIOText.inputText);
        std::cout <<  "\nEnd\n";                   //writing Alphabets to a file
    }
    else     //print in terminal
    {
        storageIOText.inputText = cryptography.GetterOT();
        if(writeToFile(storageIOText.inputText, inputArgs.pathForWriteToFile)==1){
            exit(1); //TODO
        }
    }
    return 0;
}
