namespace Alphabets
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
    std::string         path;                           //path for Alphabets base
};
