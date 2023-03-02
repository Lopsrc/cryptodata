
int Controller(std::string path){   
    GenerateEncryptionCode generateCode;        
    generateCode.GenerateFirstEncryptionCode();                       //generating first level
    generateCode.GenerateSecondEncryptionCode();                       //generating second level
    generateCode.GenerateThirdEncryptionCode();
    generateCode.GenerateFourthEncryptionCode();
    generateCode.Printer();
    Writer(path, generateCode.Getter());                               //write Alphabets to file
    return 0;
}