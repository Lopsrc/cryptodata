
std::string read_txt()                      //read Alphabets from a file
{
    std::string         inputText;        //       local variables
    std::string         txt2;       //  for storing temporary values.

    std::ifstream       fin;        // create stream for reading Alphabets from a file.     
    fin.open(PTHS::PATHR);          //open file
    if(fin.is_open())
    {
        if (ST::action_c==1)        //for encryption
        {
            while (!(fin.eof()))
            {
                std::getline(fin, txt2);        //get value
                inputText = txt2 + Alphabets::keyw;         //write Alphabets from a file

                //Alphabets::input_text += Alphabets::keyw;   //add keyword
            }
        }
        if (ST::action_c==2)            //for encryption
        {
            while (!(fin.eof()))
            {
                std::getline(fin,txt2);     //get value
                inputText += txt2;     //write Alphabets from a file
            }
        }
        fin.close();                    
    }
    else 
    {
        std::cout << ". File opening error, check the correct path.[Read text]" << '\n';
        exit(1);
    }
    return 0;
}

int write_txt(std::string& outputText)                         //write Alphabets to file
{
    int            size  =  outputText.length();   
    std::ofstream  fout;                // create stream for write Alphabets to file. 
    fout.open(PTHS::PATHW);
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
        exit(1);
    }
    return 0;
}
void printv(std::string& outputText)                           //output text in terminal
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