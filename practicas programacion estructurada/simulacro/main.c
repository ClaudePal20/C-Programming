#include <stdio.h>
#include <stdlib.h>
int funcion(int*num);
int main(){
    int a[20];
    int n = 5,*nPtr = &n,*aPtr = a;
    *(aPtr+10) = *nPtr;
    printf("%d",a[10]);//Inciso a
    //Inciso b = 3292 (int = 4 bytes, char = 1 byte, short (short int)= 2 bytes, long (long int)= 4 bytes)
    //Inciso c
    printf("\n%d",*nPtr = funcion(nPtr));
    //Inciso d
    for (int i = 0;i<20;i++){
        if(i!=10){
            *(aPtr+i) = funcion(&n);
        }
        printf("\n%d Direccion: %p",*(aPtr+i),aPtr+i);
    }

    return 0;
}
int funcion(int*num){
    return *num = 3*(*num)*(*num)-15*(*num)-5;
}



