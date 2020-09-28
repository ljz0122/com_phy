#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>

#include"pi_calc.h"

int main(int argc,char *argv[]){
    long double pi_ld;
    int N = atoi(argv[2]);
    int method = atoi(argv[1]);
    mpfr_t pi;
    mpfr_init2(pi,(4*N+256));
    switch (method){
    case 1 :
        pi_ld = pi_lei_calc(pi_ld,N);
        mpfr_init_set_ld(pi,pi_ld,MPFR_RNDN);
        break;
    case 2 :
        pi_ld = pi_euler_calc(pi_ld,N);
        mpfr_init_set_ld(pi,pi_ld,MPFR_RNDN);
        break;
    case 3 :
        pi_raman_calc(pi,N);
        break;
    default:
        printf("Unrecognized Argument\n");
    }
    printf("\nPi=");
    mpfr_out_str(stdout,10,N+1,pi,MPFR_RNDN);
    printf("\n");
    mpfr_clear(pi);
    return 0;
}