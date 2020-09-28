#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>

#include"pi_calc.h"

int main(int argc,char *argv[]){
    long double pi_ld;
    int N = atoi(argv[2]);
    int method = atoi(argv[1]);
    char * str_pi;
    mpfr_t pi;
    switch (method){
    case 1 :
        pi_ld = pi_lei_calc(pi_ld,N);
        mpfr_init_set_ld(pi,pi_ld,MPFR_RNDN);
        break;
    case 2 :
        pi_ld = pi_euler_calc(pi_ld,N);
        mpfr_init_set_ld(pi,pi_ld,MPFR_RNDN);
        break;
    /*case 3 :
        pi = pi_raman_calc(N);
        break;*/
    default:
        printf("Unrecognized Argument\n");
    }
    printf("Pi=");
    mpfr_out_str(stdout,10,N+1,pi,MPFR_RNDN);
    printf("\n");
    mpfr_clear(pi);
    return 0;
}