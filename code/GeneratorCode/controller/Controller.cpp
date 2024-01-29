

int processingArgs(int quantityArgs, char** argv){

    if (std::string(argv[1])=="-h" || quantityArgs==1)
    {
        printh();
        return 1;
    }
    return 0;
}

int Controller(std::string path)
{   
    GenerateEnglishCode generateCode;   
    generateCode.generationCode();
    
    if (!(generateCode.checkLengthOfKey()))
    {
        std::cout << "Key is not valid." << std::endl;
        exit(1);
    }
    
    if(!(generateCode.WriteKeyToFile(path)))
    {
        std::cout << "Error writing the key to the file." << std::endl;
        exit(1);
    }

    std::cout << "Creating new database." << std::endl;
    return 0;
}