#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void initArray(int* arr,int num,int lgtd);
void toUpperCase(char* arr);
void swap(int* num1,int* num2);
void mergeStrings(char* string);
int main()
{
    int arr1[10],arr2[6],arr3[8],longitud,num1=1,num2=2;
    char cadena[50]="hola cambiare todas estas letras a mayusculas";
    longitud = sizeof(arr1)/sizeof(int);
    initArray(arr1,4,longitud);
    longitud = sizeof(arr2)/sizeof(int);
    initArray(arr2,6,longitud);
    longitud = sizeof(arr3)/sizeof(int);
    initArray(arr3,7,longitud);
    toUpperCase(cadena);
    swap(&num1,&num2);
    return 0;
}
void initArray(int* arr,int numv, int longi){
    int i;
    for(i=0;i<longi;i++){
        arr[i]=numv;
        printf("%d\n",arr[i]);
        numv+=1;
    }
    printf("\n");
}
void toUpperCase(char* arr){
    int i,nletras;
    char c;
    nletras = strlen(arr);
    printf("%s\nAqui estan:\n",arr);
    for(i=0;i<nletras;i++){
        c=arr[i];
        if(c>96 && c<123){
            arr[i]=c-32;
            }
    }
    printf("%s",arr);
}
void swap(int* n1, int* n2){
    int loc1, loc2;
    printf("Tomamos los valores %d y %d",*n1,*n2);
    loc1 = *n1;
    loc2 = *n2;
    *n1 = loc2;
    *n2=loc1;
    printf("Ahora los cambiamos de lugar\nvalor 1:%d\nvalor 2:%d",*n1,*n2);
}
void mergeStrings(char* str){

}
