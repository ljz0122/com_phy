#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>
#include<gmp.h>

#include"custom_math.h"
#include"pi_calc.h"

long double pi_lei_calc(long double pi,int lim){ 
    long double quater_pi=0;
    long double quater_pi_before=1;
    long double exp=powl(10,-(lim+1));
    unsigned long int i;         
    for(i = 0;fabsl((quater_pi - quater_pi_before)*4)>=exp;i++){
        quater_pi_before=quater_pi;
        quater_pi=quater_pi+powl((-1),i)*1/(2*i+1);
    }
    printf("num=%ld ",i-1);
    pi = 4*quater_pi;
    return pi;
}

long double pi_euler_calc(long double pi,int lim){
    long double euler_pi=0;
    long double exp=powl(10,-(lim));
    unsigned long int i;
    for(i = 1;fabsl(sqrtl(1/powl(i,2)*6))>=exp;i++){
        euler_pi=euler_pi+1/powl(i,2);
    }
    printf("num=%ld ",i-1);
    pi = sqrtl(euler_pi*6);
    return pi;
}

void pi_raman_calc(mpfr_t pi,int lim){
    long int i;
    mpz_t multi,exp;
    mpz_t pi_1;
    mpz_t sqrt_8;
    mpz_t item,up,down;
    mpz_t up_1,up_2,down_1,down_2;
    mpfr_t multi_f;;
    mpz_inits(multi,exp,NULL);
    mpz_init(pi_1);
    mpz_init(sqrt_8);
    mpz_inits(up,down,NULL);
    mpz_inits(up_1,up_2,down_1,down_2,NULL);
    mpz_ui_pow_ui(multi,10,(4*lim));
    mpz_ui_pow_ui(exp,10,(lim/2));
    mpz_init_set(item,multi);
    mpz_mul(sqrt_8,multi,multi);
    mpz_mul_ui(sqrt_8,sqrt_8,8);
    mpz_sqrt(sqrt_8,sqrt_8);
    for(i = 0;mpz_cmp(item,exp)>=0;i++){
        fact(up_1,(4*i));
        mpz_set_si(up_2,i);
        mpz_mul_ui(up_2,up_2,26390);
        mpz_add_ui(up_2,up_2,1103);
        fact(down_1,i);
        mpz_pow_ui(down_1,down_1,4);
        mpz_ui_pow_ui(down_2,396,(4*i));
        mpz_mul(up,up_1,up_2);
        mpz_mul(down,down_1,down_2);
        mpz_mul(up,up,sqrt_8);
        mpz_mul_ui(down,down,(99*99));
        mpz_cdiv_q(item,up,down);
        mpz_add(pi_1,pi_1,item);
    }
    mpfr_init2(multi_f,(4*lim+256));
    mpfr_set_z(multi_f,multi,MPFR_RNDN);
    mpfr_div_z(pi,multi_f,pi_1,MPFR_RNDN);
    printf("num=%ld ",i-1);
    mpfr_clear(multi_f);
    mpz_clears(multi,exp,NULL);
    mpz_clear(pi_1);
    mpz_clear(sqrt_8);
    mpz_clears(item,up,down,NULL);
    mpz_clears(up_1,up_2,down_1,down_2,NULL);
}
