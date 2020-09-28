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
        //printf("Pi=%.10Lf\n",quater_pi*4);
    }
    printf("num=%ld, ",i);
    pi = 4*quater_pi;
    return pi;
}

long double pi_euler_calc(long double pi,int lim){
    long double euler_pi=0;
    long double exp=powl(10,-(lim));
    unsigned long int i;
    for(i = 1;fabsl(sqrtl(1/powl(i,2)*6))>=exp;i++){
        euler_pi=euler_pi+1/powl(i,2);
        //printf("Pi=%.10Lf\n",sqrtl(euler_pi*6));
    }
    printf("num=%ld, ",i);
    pi = sqrtl(euler_pi*6);
    printf("Pi=%.10Lf\n",pi);
    return pi;
}

/*void pi_raman_calc(mpfr_t pi,unsigned long int lim){
    long double pi_1 = 0;
    int i;
    long double sign;   
    for(i = 0 ;1;i++){
        sign = ((pi_1+(fact(4*i)*(1103+26390*i))/(powl(fact(i),4)*powl(396,4*i)))*sqrtl(8)/(99*99))-(pi_1*sqrtl(8)/(99*99));
        pi_1=pi_1+(fact(4*i)*(1103+26390*i))/(powl(fact(i),4)*pow(396,4*i));
        if((1/sign)>powl(10,lim)){
            break;
        }
    }
    printf("num=%d ",i);
    pi_1=pi_1*sqrtl(8)/(99*99);
    return 1/pi_1;
}*/

/*int main(int argc,char *argv[]){
    int N = 6;
    //int method = atoi(argv[1]);
    mpfr_t pi;
    long double pi_ld;
    pi_ld = pi_euler_calc(pi_ld,N);
    printf("Pi=%.10Lf\n",pi_ld);
    mpfr_init_set_ld(pi,pi_ld,MPFR_RNDN);
    printf("Pi=");
    mpfr_out_str(stdout,10,N+1,pi,MPFR_RNDN);
    printf("\n");
    mpfr_printf("Pi=%.10Rf\n",pi);
    mpfr_clear(pi);
    return 0;
}*/