#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void intercambioCadenas(char*ptr1,char*ptr2);
int main(){
    char cadena1[20]="Examen facil";
    char cadena2[20]="Directo al ordi";
    char *ptr1=cadena1;
    char *ptr2=cadena2;
    intercambioCadenas(ptr1,ptr2);
    printf("%s\n%s",cadena1,cadena2);
}
void intercambioCadenas(char*cadena1,char*cadena2){
    int longitud = strlen(cadena1),longitud2 = strlen(cadena2);
    char temp,temp2;
    int longitudF;
    if(longitud>=longitud2){
        longitudF =longitud;
    }
    else if(longitud2>=longitud){
        longitudF=longitud2;
    }
    for(int i=0;i<longitudF;i++){
        temp =*cadena1;
        temp2 =*cadena2;
        *cadena2= temp;
        *cadena1= temp2;
        *cadena1++;
        *cadena2++;
    }
}
