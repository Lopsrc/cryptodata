int Writer(std::string& path, StorageGenerate& storageCode)
{
    std::ofstream fout;
    fout.open(path);      //open file
    if(fout.is_open())
    {
        for (size_t i = 0; i < 95; i++)
        {
            if ((i==26) || (i==52) || (i==85))
                fout << "\n";
            fout << storageCode.FirstEncryptionLevel[i];                    //write Alphabets first level
        }
        fout << "\n";
       
        fout << storageCode.bufferFirst;        //write Alphabets second level
        // fout << storageCode.bufferFirst[i][1];
        
        fout << "\n";
        
        fout << storageCode.bufferSecond;        //write Alphabets second level
            // fout << storageCode.bufferSecond[i][1];
        
        fout << "\n";
        
        
        fout << storageCode.bufferThird;        //write Alphabets second level
            // fout << storageCode.bufferThird[i][1];
        
        fout << "\n";
        fout << storageCode.bufferSecondFirst;        //write Alphabets second level
            // fout << storageCode.bufferFirst[i][1];
        
        fout << "\n";
        
        
        fout << storageCode.bufferSecondSecond;        //write Alphabets second level
            // fout << storageCode.bufferSecond[i][1];
        
        fout << "\n";
        
        fout << storageCode.bufferSecondThird;        //write Alphabets second level
            // fout << storageCode.bufferThird[i][1];
        fout << "\n";
        for (size_t i = 0; i < 95; i++)
        {
            if ((i==26) || (i==52) || (i==85))
                fout << "\n";
            fout << storageCode.ThirdEncryptionLevel[i];                    //write Alphabets first level
        }
        fout.close();
    }
    else
    {
        std::cout << ". File opening error, check the correct path.[Read Alphabetsbase]" << '\n';
        exit(1);
    }
    return 0;
}