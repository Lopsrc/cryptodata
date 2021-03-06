namespace data
{
    const char          symbols[96]        =  "a b.c:d,e@f!g?h;i\"j'k(l)m<n>o-p[q]r{s}t#u$v^w&x+y/zA\\B|C=D~E_F*G`H0I1J2K3L4M5N6O7P8Q9%RSTUVWXYZ";
    const static int    eng                =  26;
    const static int    sym                =  33;
    const static int    dig                =  10;
    char                buffer_frst[30][2];             //second level
    char                buffer_scnd[30][2];             //
    char                buffer_thrd[30][2];             //
    int                 ar_check[91][2];
    int                 buff1[eng];                     //first level
    int                 buff2[eng];                     //
    int                 buff3[sym];                     //
    int                 buff4[dig];                     //
    int                 gen_tmp;                        //variable for generate first level
    std::vector<int>    ar;                             //storage buffer 
    std::string         path;                           //path for data base
};
bool check(int& size)
{
    unsigned i = 0;
    while (i<size)
    {
        if (data::ar[i]==data::gen_tmp)         //equality check
            return false;
        i++;
    }
    return true;
}

int generator_frst()
{
    const int quantity = 95;                        //number of characters
    int i = 0;
    int size = 0;
    while (i < quantity)
    {
        const int min = 10000, max = 99999;         //range numbers
        size = data::ar.size(); 
        START:
        data::gen_tmp = min + rand() % (max - min); //generate random number
        if (data::ar.empty())                       
        {
            data::ar.push_back(data::gen_tmp);      
            i++;
            continue;
        }
        else if (check(size))                            //true - not equal
        {
            data::ar.push_back(data::gen_tmp);
        }
        else
            goto START;
        i++;
    }
    return 0;
}
int strleny()
{
    int counter = 0;
    while (true)
    {
        if (data::ar_check[counter][0]==100)
            break;
        counter++;
    }
    return counter;
}
bool check(int& v1, int& v2)
{
    int counter = 0;
    for (size_t i = 0; i < strleny(); i++)
    {
        if (data::buffer_frst[i][0]==v1)
        {
            if (data::buffer_frst[i][1]==v2)    //equality check
                return false;
        }
        if (i == strleny()-1)
        {
            data::ar_check[i][0] == 100;        //keyword adding (for counting numbers)
            return true;
        }
        
    }
     
    return false;
}
int generator_scnd()
{
    int             gen_tmp;                //variables for generate
    int             gen_tmp2;               //
    int                k = 0;
    int             size = 0;
    const int       quantity = 181;         //quantity characters
    for (size_t i = 0; i < 30; i++)
    {
        START: 
        gen_tmp  = rand() % 95;
        gen_tmp2 = rand() % 95;
        if (k==0)
        {
            data::buffer_frst[i][0] = data::symbols[gen_tmp];
            data::buffer_frst[i][1] = data::symbols[gen_tmp2];
            data::ar_check[k][0]    = gen_tmp;                      //adding numbers
            data::ar_check[k][1]    = gen_tmp2;                     //
            data::ar_check[i+1][0]  = 100;                          //keyword adding (for counting numbers)
            k++;
            continue; 
        }
        else if (check(gen_tmp, gen_tmp2))                               //true - not equal
        {
            data::buffer_frst[i][0] = data::symbols[gen_tmp];
            data::buffer_frst[i][1] = data::symbols[gen_tmp2];
            k++;
        }
        else
            goto START;
    }
    for (size_t i = 0; i < 30; i++)
    {
        START2: 
        gen_tmp  = rand() % 95;
        gen_tmp2 = rand() % 95;
        if (i==0)
        {
            data::buffer_scnd[i][0] = data::symbols[gen_tmp];
            data::buffer_scnd[i][1] = data::symbols[gen_tmp2];
            data::ar_check[k][0]    = gen_tmp;
            data::ar_check[k][1]    = gen_tmp2;
            data::ar_check[i+1][0]  = 100;
            k++;
            continue; 
        }
        else if (check(gen_tmp, gen_tmp2))
        {
            data::buffer_scnd[i][0] = data::symbols[gen_tmp];
            data::buffer_scnd[i][1] = data::symbols[gen_tmp2];
            k++;
        }
        else
        {
            goto START2;
        }
    }
    for (size_t i = 0; i < 30; i++)
    {
        START3: 
        gen_tmp  = rand() % 95;
        gen_tmp2 = rand() % 95;
        if (i==0)
        {
            data::buffer_thrd[i][0] = data::symbols[gen_tmp];
            data::buffer_thrd[i][1] = data::symbols[gen_tmp2];
            data::ar_check[k][0]    = gen_tmp;
            data::ar_check[k][1]    = gen_tmp2;
            data::ar_check[i+1][0]  = 100;
            k++;
            continue; 
        }
        else if (check(gen_tmp, gen_tmp2))
        {
            data::buffer_thrd[i][0] = data::symbols[gen_tmp];
            data::buffer_thrd[i][1] = data::symbols[gen_tmp2];
            k++;
        }
        else
            goto START3;
    }
    return 0;
}