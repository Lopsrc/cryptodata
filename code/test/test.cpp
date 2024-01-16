#include <gtest/gtest.h>
#include "../CryptodataCode/cmd/headers.h"
// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 4);
}

void test1(){
  StorageIOText storageIOText;
  CryptographyEnglish cryptography;

  cryptography.write_to_cache(inputArgs.pathToKey);
  if (!(cryptography.checkLengthForKey()))
  {
    std::cout << "Key not valid" << std::endl;
    exit(1);
  }
  
  if(inputArgs.inputOfText)
  {
    std::cout << "Enter text: ";
    std::getline(std::cin, storageIOText.inputText);   //entering text using the keyboard  
    cryptography.Setter(&storageIOText.inputText);

  }
  else {
      ReadFromFile buffer = readFromFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
      if (buffer.codeError==1)
      {
        exit(1); //TODO
      }
      
      storageIOText.inputText = buffer.inputText;                     //reading text from a file
      cryptography.Setter(&storageIOText.inputText);
  }
  if      (inputArgs.cryptoAction==1)   {cryptography.encryption();}                   //encryption first level
  else if (inputArgs.cryptoAction==2)   {cryptography.decryption();}                   //decryption first level
  
  if (!(cryptography.checkSum(inputArgs.cryptoAction)))
  {
    std::cout << "Входной и выходной тексты не эквивалентны" << std::endl;
    exit(1);
  }
  
  if (inputArgs.displayedText)
  {
    storageIOText.inputText = cryptography.GetterOT();
    std::cout << "Output text:\n" << "Begin\n\n";
    printResult(storageIOText.inputText);
    std::cout <<  "\nEnd\n";                   //writing Alphabets to a file
}
  else     //print in terminal
  {
    storageIOText.inputText = cryptography.GetterOT();
    if(writeToFile(storageIOText.inputText, inputArgs.pathForWriteToFile)==1){
        exit(1); //TODO
    }
  }
}




int main(){
    CryptographyEnglish cr;
    cr.GetterIT();
    EXPECT_STRNE("hello", "world");
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}