
int Controller(std::string path){   
    GenerateEncryptionCode generateCode;        
    generateCode.GenerateFirstEncryptionCode();                       //generating first level
    generateCode.GenerateSecondEncryptionCode();                       //generating second level
    generateCode.GenerateThirdEncryptionCode();
    generateCode.Printer();
    // Writer();                               //write Alphabets to file
    return 0;
}