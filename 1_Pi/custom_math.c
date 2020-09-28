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

void mpz_pow(mpz_t result,const mpz_t base,const mpz_t exp){
    mpz_t i;
    mpz_set_si(result,1);
    if(mpz_cmp_si(exp,0)>0){
        for(mpz_init_set_ui(i,1);mpz_cmp(i,exp)<=0;mpz_add_ui(i,i,1)){
            mpz_mul(result,base,result);
        }
    }
    else{
        mpz_set_si(result,1);
    }
}

void mpz_si_pow(mpz_t result,const long int base,const mpz_t exp){
    mpz_t i;
    mpz_set_si(result,1);
    if(mpz_cmp_si(exp,0)>0){
        for(mpz_init_set_ui(i,1);mpz_cmp(i,exp)<=0;mpz_add_ui(i,i,1)){
            mpz_mul_si(result,result,base);
        }
    }
    else{
        mpz_set_si(result,1);
    }
}

/*int main(int argc,char *argv[]){
    mpz_t base,exp,result;
    mpz_init_set_si(base,atoi(argv[1]));
    mpz_init_set_si(exp,atoi(argv[2]));
    mpz_init(result);
    mpz_pow(result,base,exp);
    gmp_printf("%Zd pow %Zd is %Zd\n",base,exp,result);
    mpz_clears(base,exp,result,NULL);
    return 0;
}*/
