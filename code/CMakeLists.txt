cmake_minimum_required(VERSION 3.25)
project(Cryptodata)

add_executable(cryptodata CryptodataCode/cmd/main.cpp )
add_executable(generate GeneratorCode/cmd/main.cpp)
