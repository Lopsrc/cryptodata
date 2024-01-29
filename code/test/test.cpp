#include <gtest/gtest.h>
#include "../CryptodataCode/cmd/headers.h"
#include "../GeneratorCode/pkg/Generate.cpp"

struct InputData
{
  std::string data;
  InputData(){
    for (size_t i = 32; i < 127; i++)
    {
      data.push_back(char(i));
    }
  }
} inputData;

std::string path        = "database.txt";
std::string pathCrypto  = "../example/crypto.txt";
std::string pathEncry   = "../example/encry.txt";
std::string pathEncry1  = "../example/encry1.txt";
std::string pathDecry   = "../example/decry.txt";
std::string pathDecry1  = "../example/decry1.txt";

void testGenerete()
{
  GenerateEnglishCode generateCode;   

  std::cout << "Generating a key." << std::endl;
  generateCode.generationCode();
  
  EXPECT_TRUE(generateCode.checkLengthOfKey());

  EXPECT_TRUE(generateCode.WriteKeyToFile(path));  
  std::cout << "Creating a file." << std::endl;
}

int test1(){
  InputArgs inputArgs;
  inputArgs.pathToKey     = path;
  inputArgs.cryptoAction  = COND::ENCRYPTION;

  std::cout << "TEST1.1 - encryption." << std::endl;

  CryptographyEnglish cryptography;
  EXPECT_TRUE(cryptography.writeToCache(inputArgs.pathToKey));
  EXPECT_TRUE(cryptography.checkCryptoKey());

  cryptography.Setter(&inputData.data);
  cryptography.encryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  std::string processingData = cryptography.GetterOT();

  std::cout << "TEST1.2 - decryption." << std::endl;
  
  inputArgs.cryptoAction = COND::DECRYPTION;

  cryptography.resettingTheValue();
  cryptography.Setter(&processingData);
  cryptography.decryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  std::string processingData1 = cryptography.GetterOT(); 

  EXPECT_EQ(processingData1, inputData.data);
  return 0;
}
int test2(){
  InputArgs inputArgs;
  inputArgs.pathToKey           = path; 
  inputArgs.pathForReadToFile   = pathCrypto;
  inputArgs.pathForWriteToFile  = pathEncry;
  inputArgs.cryptoAction        = COND::ENCRYPTION;
  inputArgs.inputOfText         = COND::FILE_IO;
  inputArgs.displayedText       = COND::FILE_IO;

  std::cout << "TEST2.1 - encryption." << std::endl;

  CryptographyEnglish cryptography;
  EXPECT_TRUE(cryptography.writeToCache(inputArgs.pathToKey));
  EXPECT_TRUE(cryptography.checkCryptoKey());

  ReadFromFile readFromFile = readFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
  EXPECT_EQ(readFromFile.codeError, 0);

  cryptography.Setter(&readFromFile.inputText);
  cryptography.encryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  std::string encryptionData = cryptography.GetterOT();
  EXPECT_TRUE(writeToFile(inputArgs.pathForWriteToFile, encryptionData));

  std::cout << "TEST2.2 - decryprion." << std::endl;

  inputArgs.pathForReadToFile   = pathEncry;
  inputArgs.pathForWriteToFile  = pathDecry;
  inputArgs.cryptoAction        = COND::DECRYPTION;
  cryptography.resettingTheValue();

  readFromFile = readFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
  EXPECT_EQ(readFromFile.codeError, 0);

  cryptography.Setter(&readFromFile.inputText);
  cryptography.decryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  encryptionData = cryptography.GetterOT();
  EXPECT_TRUE(writeToFile(inputArgs.pathForWriteToFile, encryptionData));

  return 0;
}
int test3(){
  InputArgs inputArgs;
  inputArgs.pathToKey           = path;
  inputArgs.pathForWriteToFile  = pathEncry1;
  inputArgs.cryptoAction        = COND::ENCRYPTION;
  inputArgs.inputOfText         = COND::CLI_IO;
  inputArgs.displayedText       = COND::FILE_IO;

  std::cout << "TEST3.1 - encryption." << std::endl;

  CryptographyEnglish cryptography;
  EXPECT_TRUE(cryptography.writeToCache(inputArgs.pathToKey));
  EXPECT_TRUE(cryptography.checkCryptoKey());

  cryptography.Setter(&inputData.data);
  cryptography.encryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  std::string encryptionData = cryptography.GetterOT();
  EXPECT_TRUE(writeToFile(inputArgs.pathForWriteToFile, encryptionData));

  std::cout << "TEST3.2 - decryption." << std::endl;

  inputArgs.pathForReadToFile   = pathEncry1;
  inputArgs.cryptoAction        = COND::DECRYPTION;
  inputArgs.inputOfText         = COND::FILE_IO;
  inputArgs.displayedText       = COND::CLI_IO;
  cryptography.resettingTheValue();

  ReadFromFile readFromFile = readFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
  EXPECT_EQ(readFromFile.codeError, 0);

  cryptography.Setter(&readFromFile.inputText);
  cryptography.decryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  encryptionData = cryptography.GetterOT();

std::cout << "TEST3.3 - encryption." << std::endl;

  cryptography.resettingTheValue();
  inputArgs.pathForReadToFile   = pathCrypto;
  inputArgs.cryptoAction        = COND::ENCRYPTION;
  inputArgs.inputOfText         = COND::FILE_IO;
  inputArgs.displayedText       = COND::CLI_IO;

  readFromFile = readFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
  EXPECT_EQ(readFromFile.codeError, 0);

  cryptography.Setter(&readFromFile.inputText);
  cryptography.encryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  encryptionData = cryptography.GetterOT();

  std::cout << "TEST3.4 - decryption." << std::endl;

  inputArgs.pathForWriteToFile  = pathDecry1;
  inputArgs.cryptoAction        = COND::DECRYPTION;
  inputArgs.inputOfText         = COND::CLI_IO;
  inputArgs.displayedText       = COND::FILE_IO;
  cryptography.resettingTheValue();

  cryptography.Setter(&encryptionData);
  cryptography.decryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  encryptionData = cryptography.GetterOT();
  EXPECT_TRUE(writeToFile(inputArgs.pathForWriteToFile, encryptionData));

  return 0;
}

TEST(Test, BasicAssertions) 
{
  testGenerete();
  test1();
  test2();
  test3();
}

int main()
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}