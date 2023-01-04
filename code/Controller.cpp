

int Controller(std::string path)        //function for manage application
{
    std::cout << ST::enter_it << "\t" << ST::enter_wk << std::endl;
    std::string inputText;
    std::string outputText;
    CryptographyEnglish cryptography;
    cryptography.write_to_cache(path);
    if(ST::enter_wk==2)
    {
        std::cout << "Enter text: ";
        std::getline(std::cin, inputText);   //entering text using the keyboard  
        cryptography.Setter(&inputText);

    }
    else if(ST::enter_wk == 1){
        inputText = read_txt();                     //reading text from a file
        cryptography.Setter(&inputText);
    }
    // std::cout << cryptography.GetterIT() << std::endl;
    if      (ST::action_c==1)   {cryptography.encryption();}                   //encryption first level
    else if (ST::action_c==2)   {cryptography.decryption();}                   //decryption first level
    
    if (!(cryptography.checkSum()))
    {
        std::cout << "Входной и выходной тексты не эквивалентны" << std::endl;
        exit(1);
    }
    
    std::cout << cryptography.GetterOT() << std::endl;

    if (ST::enter_it == 1)
    {
        outputText = cryptography.GetterOT();
        write_txt(outputText);                    //writing Alphabets to a file
    }
    else if (ST::enter_it == 2)      //print in terminal
    {
        std::cout << "Output text:\n" << "Begin\n\n";
        printv(outputText);
        std::cout <<  "\nEnd\n";
    }
    return 0;
}
