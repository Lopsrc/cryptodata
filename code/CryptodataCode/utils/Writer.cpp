struct ReadFromFile
{
    std::string inputText;  //Text from the file.
    int codeError = 0;          // 0 (no error),or 1(error).
};

const std::string   keyw = "_N0_";            //The key word. Means the data is being moved to a new line.                                  //line separator.

ReadFromFile readFile(std::string& path, int cryptoAction)                      
{
    ReadFromFile        readFile; 
    std::string         buffer;      
    std::ifstream       fin;       
    fin.open(path);          
    if(fin.is_open())
    {
        if (cryptoAction==COND::ENCRYPTION)        
        {
            while (!(fin.eof()))
            {
                std::getline(fin, buffer);        
                readFile.inputText += buffer ;    
                readFile.inputText += keyw;   
            }
        }
        if (cryptoAction==COND::DECRYPTION)   
        {
            while (!(fin.eof()))
            {
                std::getline(fin,buffer);     
                readFile.inputText += buffer; 
            }
        }
        fin.close();                    
    }
    else 
    {
        readFile.codeError = 1;
    }
    return readFile;
}

bool writeToFile(std::string& path, std::string& outputText)
{
    int            size  =  outputText.length();   
    std::ofstream  fout;               
    fout.open(path);
    if(fout.is_open())
    {
        for (size_t i = 0; i < size; i++)
        {
            if (outputText.substr(i,4)==keyw){
                fout << "\n";
                i+=3;
                continue;
            }
            fout << outputText[i]; 
        }
        fout.close();
    }
    else
    {
        return false;
    }
    return true;
}
void printResult(std::string& outputText)                           //output text in terminal
{
    int size = outputText.length();
    for (size_t i = 0; i < size; i++)
    {
        if (outputText.substr(i,4)==keyw){
            std::cout << "\n";
            i+=3;
            continue;
        }
        std::cout << outputText[i];
    }
    std::cout << "\n";
}