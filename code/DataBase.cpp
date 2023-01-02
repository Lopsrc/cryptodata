
// int write_to_cache(std::string& path)   //write Alphabets to global variable
// {
//     char            buff[130];          //
//     char            buff2[130];         //
//     char            buff3[165];         //          local variables  
//     char            buff4[50];          //                for
//     char            buff5[60];          //      storing temporary values.
//     char            buff6[60];          //
//     char            buff7[60];          //
//     std::ifstream   fin;                // create stream for reading Alphabets from a file.
//     fin.open(path);                     //open file
//     if(fin.is_open())
//     {
        
//         fin.getline(buff, 131);     //
//         fin.getline(buff2, 131);    //
//         fin.getline(buff3, 166);    //      reading 
//         fin.getline(buff4, 51);     //        Alphabets
//         fin.getline(buff5, 61);     //
//         fin.getline(buff6, 61);     //
//         fin.getline(buff7, 61);     //
//         fin.close();
    
//     }
//     else
//     {
//         std::cout << ". File opening error, check the correct path. [Read Alphabetsbase]" << '\n';
//         exit(1);
//     }
//     for (size_t j = 0, k = 0, p = 0; j < 33; j++)
//     {
//         for (size_t i = 0; i < 5; i++, k++)
//         {
//             if (j < 10) {Alphabets::digitals_crypto[j][i]=buff4[k];}
//             if (j < 26)
//             {
//                 Alphabets::english_crypto[j][i]=buff[k];             //write to global Alphabets
//                 Alphabets::english_crypto_up[j][i]=buff2[k]; 
//             }
//             if(j < 33)  {Alphabets::symbols_crypto[j][i]=buff3[k]; }
//         }
//         if (j < 10)
//         {
//             for (size_t i = 0; i < 3; i++)
//             {
//                 for (size_t l = 0; l < 2; l++, p++)
//                 {
//                     Alphabets::fst_[j][i][l]  = buff5[p];              //write to global Alphabets
//                     Alphabets::snd_[j][i][l]  = buff6[p];
//                     Alphabets::thrd_[j][i][l] = buff7[p];
//                 }
//             }
//         }
//     }
//     return 0;
// }
// int read_txt()                      //read Alphabets from a file
// {
//     std::string         txt;        //       local variables
//     std::string         txt2;       //  for storing temporary values.
//     std::ifstream       fin;        // create stream for reading Alphabets from a file.     
//     fin.open(PTHS::PATHR);          //open file
//     if(fin.is_open())
//     {
//         if (ST::action_c==1)        //for encryption
//         {
//             while (!(fin.eof()))
//             {
//                 std::getline(fin, txt2);        //get value
//                 Alphabets::input_text+=txt2;         //write Alphabets from a file
//                 Alphabets::input_text+=Alphabets::keyw;   //add keyword
//             }
//         }
//         if (ST::action_c==2)            //for encryption
//         {
//             while (!(fin.eof()))
//             {
//                 std::getline(fin,txt2);     //get value
//                 Alphabets::input_text+=txt2;     //write Alphabets from a file
//             }
//         }
//         fin.close();                    
//     }
//     else 
//     {
//         std::cout << ". File opening error, check the correct path.[Read text]" << '\n';
//         exit(1);
//     }
//     return 0;
// }
// int write_txt()                         //write Alphabets to file
// {
//     int            size  =  strleny(Alphabets::text2);   
//     std::ofstream  fout;                // create stream for write Alphabets to file. 
//     fout.open(PTHS::PATHW);
//     if(fout.is_open())
//     {
//         for (size_t i = 0; i < size; i++)
//         {
//             if (Alphabets::text2[i]==Alphabets::keyw[0])
//             {
//                 if (Alphabets::text2[i+1]==Alphabets::keyw[1])
//                 {
//                     if (Alphabets::text2[i+2]==Alphabets::keyw[2])
//                     {
//                         if (Alphabets::text2[i+3]==Alphabets::keyw[3])
//                         {
//                             fout << "\n";
//                             i+=3;
//                             continue;
//                         }
//                     }
//                 }
//             }
//             fout << Alphabets::text2[i]; //write Alphabets to file
//         }
//         fout.close();
//     }
//     else
//     {
//         std::cout << ". File opening error, check the correct path.[Output text]" << '\n';
//         exit(1);
//     }
//     return 0;
// }