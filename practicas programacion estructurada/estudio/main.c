#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int CantidadLetrasDiferentes(char arr[]);
int main(){
    char arr[]="cuantas letras diferentes hay aqui";
    int cant;
    printf("\nHay %d letras diferentes",cant = CantidadLetrasDiferentes(arr));
    return 0;
}
int CantidadLetrasDiferentes(char arr[]){
    int cant=0,i,j,l=strlen(arr),b;
    for(i = 0;i<l;i++){
        j=0;
        do{
            b=0;
            if(arr[i]==arr[j]){
                break;
            }
            else{
                b=1;
                j++;
            }
        }while(j<i);
        if(b==1){
            printf("%c",arr[i]);
            cant++;
        }
    }
    return cant;
}
