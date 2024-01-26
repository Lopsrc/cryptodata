struct ReadFromFile
{
    std::string inputText;  //Text from the file.
    int codeError = 0;          // 0 (no error),or 1(error).
};

const std::string   keyw = "_N0_";                                              //line separator.

ReadFromFile readFromFile(std::string& path, int cryptoAction)                      //read Alphabets from a file
{
    ReadFromFile        readFromFileDTO;        //       local variables
    std::string         txt2;       //  for storing temporary values.
    std::ifstream       fin;        // create stream for reading Alphabets from a file.     
    fin.open(path);          //open file
    if(fin.is_open())
    {
        if (cryptoAction==COND::ENCRYPTION)        //for encryption
        {
            while (!(fin.eof()))
            {
                std::getline(fin, txt2);        //get value
                readFromFileDTO.inputText += txt2 ;         //write Alphabets from a file
                readFromFileDTO.inputText += keyw;   //add keyword
            }
        }
        if (cryptoAction==COND::DECRYPTION)            //for encryption
        {
            while (!(fin.eof()))
            {
                std::getline(fin,txt2);     //get value
                readFromFileDTO.inputText += txt2;     //write Alphabets from a file
            }
        }
        fin.close();                    
    }
    else 
    {
        std::cout << ". File opening error, check the correct path.[Read text]" << '\n';
        readFromFileDTO.codeError = 1;
    }
    return readFromFileDTO;
}

int writeToFile(std::string& path, std::string& outputText)                         //write Alphabets to file
{
    int            size  =  outputText.length();   
    std::ofstream  fout;                // create stream for write Alphabets to file. 
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
            fout << outputText[i]; //write Alphabets to file
        }
        fout.close();
    }
    else
    {
        std::cout << ". File opening error, check the correct path.[Output text]" << '\n';
        return 1;
    }
    return 0;
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