![alt text](info/ico.jpg)

# Cryptodata

Encryption and decryption data.

# Usage

To build in docker, run the following command.
```
sudo docker build -t cryptodata . 
```

Launching the container:
```
sudo docker run -it cryptodata
```
Testing the code:
```
./test
```

To run the code, go to the /app/build directory and run 2 commands. The first command creates a key that is used for encryption. The second command encrypts the data:
```
cd app/build
./generate database.txt
./cryptodata database.txt -e 
```

For information:
```
./generate -h
./cryptodata -h 
```
