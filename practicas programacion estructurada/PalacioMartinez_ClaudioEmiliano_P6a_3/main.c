#include <stdio.h>
#include <stdlib.h>
int sumaArr(int* arr, int num);
int main(){
    int arr1[5]={1,2,3,4,5},arr2[5]={6,4,8,9,1},arr3[5]={5,7,4,8,9},success;
    success=sumaArr(arr1,4);
    printf("\n%d (Arreglo 1)",success);
    success=sumaArr(arr2,7);
    printf("\n%d (Arreglo 2)",success);
    success=sumaArr(arr3,5);
    printf("\n%d (Arreglo 3)",success);
    return 0;
}
int sumaArr(int* arr, int num){
    int i,j;
    for (i =0;i<5;i++){
        for(j=1;j<5;j++){
            if (arr[i]+arr[j]==num && i!=j){
                printf("\nLos numeros de la posicion [%d] y [%d] permiten sumar el numero introducido. (%d)",i,j,arr[i]+arr[j]);
                return 1;
            }
        }
    }
    printf("\nNo se pudo llegar al resultado con los numeros del arreglo");
    return 0;
}
