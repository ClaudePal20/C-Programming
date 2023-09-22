#include <stdio.h>
#include <stdlib.h>
int numerospares(int n);
int imprimenumerospares(int n);
int main(){
    int n;
    printf("%d\n",numerospares(5));
    imprimenumerospares(5);
    return 0;
}
int numerospares(int n){
    if(n==0){
        return 0;
    }
    return(n+numerospares(n-1));
}
int imprimenumerospares(int n){
    if (n==0){
        return 0;
    }
    printf("%d",n*2);
    return(imprimenumerospares(n-1));
}
