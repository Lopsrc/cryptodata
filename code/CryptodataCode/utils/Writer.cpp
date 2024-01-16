

ReadFromFile readFromFile(std::string& path, int cryptoAction)                      //read Alphabets from a file
{
    ReadFromFile        readFromFileDTO;        //       local variables
    std::string         txt2;       //  for storing temporary values.
    std::ifstream       fin;        // create stream for reading Alphabets from a file.     
    fin.open(path);          //open file
    if(fin.is_open())
    {
        if (cryptoAction==1)        //for encryption
        {
            while (!(fin.eof()))
            {
                std::getline(fin, txt2);        //get value
                readFromFileDTO.inputText += txt2 ;         //write Alphabets from a file
                readFromFileDTO.inputText += Alphabets::keyw;   //add keyword
            }
        }
        if (cryptoAction==2)            //for encryption
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

int writeToFile(std::string& outputText, std::string& path)                         //write Alphabets to file
{

    int            size  =  outputText.length();   
    std::ofstream  fout;                // create stream for write Alphabets to file. 
    fout.open(path);
    if(fout.is_open())
    {
        for (size_t i = 0; i < size; i++)
        {
            if (outputText[i]==Alphabets::keyw[0])
            {
                if (outputText[i+1]==Alphabets::keyw[1])
                {
                    if (outputText[i+2]==Alphabets::keyw[2])
                    {
                        if (outputText[i+3]==Alphabets::keyw[3])
                        {
                            fout << "\n";
                            i+=3;
                            continue;
                        }
                    }
                }
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
        if (outputText[i]==Alphabets::keyw[0])
            if (outputText[i+1]==Alphabets::keyw[1])
                if (outputText[i+2]==Alphabets::keyw[2])
                    if (outputText[i+3]==Alphabets::keyw[3])      //keyword checking
                    {
                        std::cout << "\n";
                        i+=3;
                        continue;
                    }
        std::cout << outputText[i];
    }
    std::cout << "\n";
}