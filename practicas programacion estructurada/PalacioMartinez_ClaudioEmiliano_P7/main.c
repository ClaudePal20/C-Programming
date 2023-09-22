#include<stdio.h>
#include<stdlib.h>
int fibonacci(int n,int nc);
int buscar(int n,int *arr,int longitud);
int numdigitos(int n);
int invertir(int *arr,int longitud);
int ArregloRandom(int );
int main(void){
    int arr[10]={0,1,2,3,4,5,6,7,8,9},i;
    int arr2[13]={14,1,2,5,6,5,5,3,4,10,17,23,56};
    int arr3[15]={14,57,3,27,6,8,5,3,2,3,17,88,56,123,24};
    int arr4[15]={4,5,32,7,68,5,2,35,1,4,17,18,67,143,14};
    int exito,nc,longitud=sizeof(arr)/sizeof(int),numdigs;
    printf("Serie de fibonacci. Posicion con elemento a calcular: ");
    scanf("%d",&nc);
    fibonacci(0,nc);
    exito = buscar(1,arr,longitud);
    printf("Exito: %d\n",exito);
    numdigs = numdigitos(123);
    printf("El numero 123 tiene: %d digitos",numdigs);
    *arr = invertir(arr,longitud);
    printf("Arreglo invertido: ");
    for(i = 0;i<longitud;i++){
        printf("%d ",arr[i]);//Por que aqui me saca la direccion y no el numero 9 en el espacio cuando se regresa el arreglo invertido????
    }
    //Prueba
    printf("\n\n");
    fibonacci(0,10);
    printf("\n");
    fibonacci(0,24);
    printf("\n");
    fibonacci(0,15);
    exito = buscar(3,arr,longitud);
    printf("Exito: %d",exito);
    exito = buscar(-1234,arr,longitud);
    printf("Exito: %d",exito);
    exito = buscar(10948,arr4,longitud);
    printf("Exito: %d",exito);
    numdigitos(1244);
    numdigitos(124478);
    numdigitos(498376);
    printf("\n");
    longitud=sizeof(arr2)/sizeof(int);
    invertir(arr2,longitud);
    longitud=sizeof(arr3)/sizeof(int);
    invertir(arr3,longitud);
    longitud=sizeof(arr4)/sizeof(int);
    invertir(arr4,longitud);
    return 0;
}
int fibonacci(int n,int nc){
    static int n1=0,n2=1,n3;
    if(n==0||n==1){
        printf("%d ",n);
    }
    else if(n<nc){
         n3 = n1+n2;
         n1 = n2;
         n2 = n3;
         printf("%d ",n3);
    }
    else if(n>nc){
        n1=0;
        n2=1;
        n3=0;
        return 0;//Para detener la recursion y evitar que haga stack overflow
    }
    fibonacci(n+1,nc);
}
int buscar(int n,int *arr,int i){
    if(arr[i]==n){
        printf("\n");
        return n;
    }
    else if(i == -1){
        printf("\n");
        return -1;
    }
    else{
        i--;
        buscar(n,arr,i);
    }
}
int numdigitos(int n){
    int static sum=1;
    if(n>1){
        n = n / 10; //Lo dividimos entre 10 y a la siguiente nos dejara el residuo del otro digito
        sum++;
        numdigitos(n);
    }
    else{
        return sum;
    }
}
int invertir(int *arr,int longitud){
    static int i=0,a;
    if(i<longitud/2){
        a=arr[i];
        arr[i]=arr[longitud-i-1];
        arr[longitud-i-1]=a;
        i++;
        *arr = invertir(arr,longitud);
    }
    else{
        printf("\nArreglo invertido: ");
        for(i = 0;i<longitud;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return *arr;
    }
}
