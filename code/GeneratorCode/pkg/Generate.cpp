const char ALL_SYMBOLS[96]  =  "a b.c:d,e@f!g?h;i\"j'k(l)m<n>o-p[q]r{s}t#u$v^w&x+y/zA\\B|C=D~E_F*G`H0I1J2K3L4M5N6O7P8Q9%RSTUVWXYZ";
const int MIN = 10000, MAX = 99999;         //range numbers

struct StorageGenerate
{
    std::string                bufferFirst;             //second level
    std::string                bufferSecond;             //
    std::string                bufferThird;             //
    
    std::vector<int>    FirstEncryptionLevel;                             //storage buffer
};
struct StorageGenerateIndexes
{
    int             generateIndex;                //variables for generate
    int             generateIndexSecond;               //
};


class GenerateEncryptionCode {
private:
    StorageGenerate storageKeys;
    StorageGenerateIndexes storageIndexes;
    int                 gen_tmp;                        //variable for generate first level
    int                 quantity = 96;
    std::string     buffer;
    void generateIndexes(){
        storageIndexes.generateIndex  = rand() % 95;
        storageIndexes.generateIndexSecond= rand() % 95;
    }
    bool checkSame()
    {
        for(int i = 0; i<storageKeys.FirstEncryptionLevel.size(); i++)
        {
            if (storageKeys.FirstEncryptionLevel[i]==gen_tmp)         //equality check
                return false;
        }
        return true;
    }
    void pushToBuffer(){
        buffer.clear();
        buffer.push_back(ALL_SYMBOLS[storageIndexes.generateIndex]);
        buffer.push_back(ALL_SYMBOLS[storageIndexes.generateIndexSecond]);
    }
    int equals(){
        return storageKeys.bufferFirst.find(buffer)!=-1 || storageKeys.bufferSecond.find(buffer)!=-1 || storageKeys.bufferThird.find(buffer)!=-1;
    }
public:
    StorageGenerate& Getter(){
        return storageKeys;
    }

    int GenerateFirstEncryptionCode()
    {
        for(int i = 0;i < quantity; i++)
        {
            gen_tmp = MIN + rand() % (MAX - MIN); //generate random number
            if (storageKeys.FirstEncryptionLevel.empty())                       
            {
                storageKeys.FirstEncryptionLevel.push_back(gen_tmp);      
                i++;
                continue;
            }
            if (checkSame())                            //true - not equal
                storageKeys.FirstEncryptionLevel.push_back(gen_tmp);
                continue;
            i--;
        }
        return 0;
    }

    int GenerateSecondEncryptionCode()
    {
        for (size_t i = 0; i < 30; i++)
        {
            generateIndexes();
            pushToBuffer();

            if (i==0)
            {
                storageKeys.bufferFirst.append(buffer);
                continue;
            }
            if (equals())
                i--;
            storageKeys.bufferFirst.append(buffer);
        }
        for (size_t i = 0; i < 30; i++)
        {
            generateIndexes();   
            pushToBuffer();
            
            if (i==0)
            {
                storageKeys.bufferSecond.append(buffer);
                continue;
            }
            if (equals())   
                i--;

            storageKeys.bufferSecond.append(buffer);
        }
        for (size_t i = 0; i < 30; i++)
        {
            generateIndexes();
            pushToBuffer();
            
            if (i==0)
            {
                storageKeys.bufferThird.append(buffer);
                continue;
            }
            if (equals())   
                i--;
            storageKeys.bufferThird.append(buffer);
        }
        return 0;
    }

    int WriteKeyToFile(std::string& path){
        std::ofstream fout;
        fout.open(path);      //open file
        if(fout.is_open())
        {
            for (size_t i = 0; i < 95; i++)
            {
                if ((i==26) || (i==52) || (i==85))
                    fout << "\n";
                fout << storageKeys.FirstEncryptionLevel[i];                    //write Alphabets first level
            }
            fout << "\n";
        
            fout << storageKeys.bufferFirst;        //write Alphabets second level
            fout << "\n";
            
            fout << storageKeys.bufferSecond;        //write Alphabets second level
            fout << "\n";
            
            fout << storageKeys.bufferThird;        //write Alphabets second level
        
            fout.close();
        }
        else
        {
            std::cout << ". File opening error, check the correct path.[Read Alphabetsbase]" << '\n';
            exit(1);
        }
        return 0;
    }
};