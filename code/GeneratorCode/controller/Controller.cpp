

int processingArgs(int quantityArgs, char** argv){
    if (quantityArgs==1)
        return 1;

    if (std::string(argv[1])=="-h")
        printh();

    return 0;
}

int Controller(std::string path){   
    GenerateEncryptionCode generateCode;   

    generateCode.GenerateFirstEncryptionCode();                       //generating first level
    generateCode.GenerateSecondEncryptionCode();                       //generating second level
    generateCode.WriteKeyToFile(path);                               //write Alphabets to file
    
    return 0;
}