bool check(int& size)
{
    unsigned i = 0;
    while (i<size)
    {
        if (Alphabets::ar[i]==Alphabets::gen_tmp)         //equality check
            return false;
        i++;
    }
    return true;
}
bool check(int& v1, int& v2)
{
    int counter = 0;
    for (size_t i = 0; i < strleny(); i++)
    {
        if (Alphabets::buffer_frst[i][0]==v1)
        {
            if (Alphabets::buffer_frst[i][1]==v2)    //equality check
                return false;
        }
        if (i == strleny()-1)
        {
            Alphabets::ar_check[i][0] == 100;        //keyword adding (for counting numbers)
            return true;
        }   
    }
    return false;
}
int strleny()
{
    int counter = 0;
    while (true)
    {
        if (Alphabets::ar_check[counter][0]==100)
            break;
        counter++;
    }
    return counter;
}
