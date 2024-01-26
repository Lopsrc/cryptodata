#include <gtest/gtest.h>
#include "../CryptodataCode/cmd/headers.h"

namespace checkData
{
  std::string pathForReadData ;
  std::string pathForWriteData;
  std::string pathForReadKey;
  std::string data = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ  .,:@!?;\"'()<>-[]{}#$^&+/\\|=~_%*` 0123456789";
} 

int test1(){
  InputArgs inputArgs;
  inputArgs.pathToKey     = "/home/serpc/Projects/cpp/cryptodata/code/test/example/test.txt";
  inputArgs.cryptoAction  = COND::ENCRYPTION;

  std::cout << "TEST1.1 - encryption." << std::endl;

  CryptographyEnglish cryptography;
  cryptography.write_to_cache(inputArgs.pathToKey);
  EXPECT_TRUE(cryptography.checkCryptoKey());

  cryptography.Setter(&checkData::data);
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

  EXPECT_EQ(processingData1, checkData::data);
  return 0;
}
int test2(){
  InputArgs inputArgs;
  inputArgs.pathToKey           = "/home/serpc/Projects/cpp/cryptodata/code/test/example/test.txt";
  inputArgs.pathForReadToFile   = "/home/serpc/Projects/cpp/cryptodata/code/test/example/crypto.txt";
  inputArgs.pathForWriteToFile  = "/home/serpc/Projects/cpp/cryptodata/code/test/example/encry.txt";
  inputArgs.cryptoAction        = COND::ENCRYPTION;
  inputArgs.inputOfText         = COND::FILE_IO;
  inputArgs.displayedText       = COND::FILE_IO;

  std::cout << "TEST2.1 - encryption." << std::endl;

  CryptographyEnglish cryptography;
  cryptography.write_to_cache(inputArgs.pathToKey);
  EXPECT_TRUE(cryptography.checkCryptoKey());

  ReadFromFile readFile = readFromFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
  EXPECT_EQ(readFile.codeError, 0);

  cryptography.Setter(&readFile.inputText);
  cryptography.encryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  std::string encryptionData = cryptography.GetterOT();
  EXPECT_EQ(writeToFile(inputArgs.pathForWriteToFile, encryptionData), 0);

  std::cout << "TEST2.2 - decryprion." << std::endl;

  inputArgs.pathForReadToFile   = "/home/serpc/Projects/cpp/cryptodata/code/test/example/encry.txt";
  inputArgs.pathForWriteToFile  = "/home/serpc/Projects/cpp/cryptodata/code/test/example/decry.txt";
  inputArgs.cryptoAction        = COND::DECRYPTION;
  cryptography.resettingTheValue();

  readFile = readFromFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
  EXPECT_EQ(readFile.codeError, 0);

  cryptography.Setter(&readFile.inputText);
  cryptography.decryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  encryptionData = cryptography.GetterOT();
  EXPECT_EQ(writeToFile(inputArgs.pathForWriteToFile, encryptionData), 0);

  return 0;
}
int test3(){
  InputArgs inputArgs;
  inputArgs.pathToKey           = "/home/serpc/Projects/cpp/cryptodata/code/test/example/test.txt";
  inputArgs.pathForReadToFile   = "";
  inputArgs.pathForWriteToFile  = "/home/serpc/Projects/cpp/cryptodata/code/test/example/encry1.txt";
  inputArgs.cryptoAction        = COND::ENCRYPTION;
  inputArgs.inputOfText         = COND::CLI_IO;
  inputArgs.displayedText       = COND::FILE_IO;

  std::cout << "TEST3.1 - encryption." << std::endl;

  CryptographyEnglish cryptography;
  cryptography.write_to_cache(inputArgs.pathToKey);
  EXPECT_TRUE(cryptography.checkCryptoKey());

  cryptography.Setter(&checkData::data);
  cryptography.encryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  std::string encryptionData = cryptography.GetterOT();
  EXPECT_EQ(writeToFile(inputArgs.pathForWriteToFile, encryptionData), 0);

  std::cout << "TEST3.2 - decryption." << std::endl;

  inputArgs.pathForReadToFile   = "/home/serpc/Projects/cpp/cryptodata/code/test/example/encry1.txt";
  inputArgs.pathForWriteToFile  = "";
  inputArgs.cryptoAction        = COND::DECRYPTION;
  inputArgs.inputOfText         = COND::FILE_IO;
  inputArgs.displayedText       = COND::CLI_IO;
  cryptography.resettingTheValue();

  ReadFromFile readFile = readFromFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
  EXPECT_EQ(readFile.codeError, 0);

  cryptography.Setter(&readFile.inputText);
  cryptography.decryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  encryptionData = cryptography.GetterOT();

std::cout << "TEST3.3 - encryption." << std::endl;

  cryptography.resettingTheValue();
  inputArgs.pathForReadToFile   = "/home/serpc/Projects/cpp/cryptodata/code/test/example/crypto.txt";
  inputArgs.pathForWriteToFile  = "";
  inputArgs.cryptoAction        = COND::ENCRYPTION;
  inputArgs.inputOfText         = COND::FILE_IO;
  inputArgs.displayedText       = COND::CLI_IO;

  readFile = readFromFile(inputArgs.pathForReadToFile, inputArgs.cryptoAction);
  EXPECT_EQ(readFile.codeError, 0);

  cryptography.Setter(&readFile.inputText);
  cryptography.encryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  encryptionData = cryptography.GetterOT();

  std::cout << "TEST3.4 - decryption." << std::endl;

  inputArgs.pathForReadToFile   = "";
  inputArgs.pathForWriteToFile  = "/home/serpc/Projects/cpp/cryptodata/code/test/example/decry1.txt";
  inputArgs.cryptoAction        = COND::DECRYPTION;
  inputArgs.inputOfText         = COND::CLI_IO;
  inputArgs.displayedText       = COND::FILE_IO;
  cryptography.resettingTheValue();

  cryptography.Setter(&encryptionData);
  cryptography.decryption();
  EXPECT_TRUE(cryptography.checkSum(inputArgs.cryptoAction));

  encryptionData = cryptography.GetterOT();
  EXPECT_EQ(writeToFile(inputArgs.pathForWriteToFile, encryptionData), 0);

  return 0;
}

TEST(Test, BasicAssertions) 
{
  test1();
  test2();
  test3();
}


int main()
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}