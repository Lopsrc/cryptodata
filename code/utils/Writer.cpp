int Writer()
{
    std::ofstream fout;
    fout.open(Alphabets::path);      //open file
    if(fout.is_open())
    {
        for (size_t i = 0; i < 95; i++)
        {
            if ((i==26) || (i==52) || (i==85))
                fout << "\n";
            fout << Alphabets::ar[i];                    //write Alphabets first level
        }
        fout << "\n";
        for (size_t i = 0; i < 30; i++)
        {
            fout << Alphabets::buffer_frst[i][0];        //write Alphabets second level
            fout << Alphabets::buffer_frst[i][1];
        }
        fout << "\n";
        for (size_t i = 0; i < 30; i++)
        {
            fout << Alphabets::buffer_scnd[i][0];        //write Alphabets second level
            fout << Alphabets::buffer_scnd[i][1];
        }
        fout << "\n";
        for (size_t i = 0; i < 30; i++)
        {
            fout << Alphabets::buffer_thrd[i][0];        //write Alphabets second level
            fout << Alphabets::buffer_thrd[i][1];
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