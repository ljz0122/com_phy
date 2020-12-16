#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long double pi_lei_calc_count(int lim){ 
    long double pi,quater_pi=0;
    long double quater_pi_before=1;
    long double exp=powl(10,-(lim+1));
    unsigned long int i;         
    for(i = 0;fabsl((quater_pi - quater_pi_before)*4)>=exp;i++){
        quater_pi_before=quater_pi;
        quater_pi=quater_pi+powl((-1),i)*1/(2*i+1);
    }
    //printf("num=%ld ",i-1);
    pi = 4*quater_pi;
    return pi;
}

long double pi_lei_calc_n(int n){ 
    long double pi,quater_pi=0;
    unsigned long int i;         
    for(i = 0;i<=n;i++){
        quater_pi=quater_pi+powl((-1),i)*1/(2*i+1);
    }
    //printf("num=%ld ",i-1);
    pi = 4*quater_pi;
    return pi;
}

long double pi_euler_calc_count(int lim){
    long double pi,euler_pi=0;
    long double exp=powl(10,-(lim));
    unsigned long int i;
    for(i = 1;fabsl(sqrtl(1/powl(i,2)*6))>=exp;i++){
        euler_pi=euler_pi+1/powl(i,2);
    }
    //printf("num=%ld ",i);
    pi = sqrtl(euler_pi*6);
    return pi;
}

long double pi_euler_calc_n(int n){
    long double pi,euler_pi=0;
    unsigned long int i;
    for(i = 1;i<=n;i++){
        euler_pi=euler_pi+1/powl(i,2);
    }
    //printf("num=%ld ",i);
    pi = sqrtl(euler_pi*6);
    return pi;
}
