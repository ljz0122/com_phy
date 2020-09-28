#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gmp.h>

#include"custom_math.h"

void fact(mpz_t result,const int num){          //此处定义一求阶乘函数fact()
    mpz_set_si(result,1);
    for(int i = 1;i<=num;i++){
            mpz_mul_si(result,result,i);
    }
}
