#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lastOddNumber(int* arr,int longitud);
int hasCapitalizedWord(char* cadena,int longitud);
char* function(char* arr, char c,int longitud);
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10},longitud=sizeof(arr)/sizeof(int);
    char cadena[26]="Me gusta el free fire jaj.",cadenaB[20]="Tamales jaj";
    //1er ejercicio
    printf("Ultimo numero primo: %d",lastOddNumber(arr,longitud));
    //2do ejercicio
    longitud = strlen(cadena);
    printf("\nTiene alguna palabra iniciada con mayuscula? 1. Si 0. No:\n%d",hasCapitalizedWord(cadena,longitud));
    //3er ejercicio (Profe help el codigo no funciona xC )
    char* A = function(cadena, 'e',longitud);
    printf("\n%s",A);
    char* B = function(cadenaB, 't',longitud);
    printf("\n%s",B);
    return 0;
}
int lastOddNumber(int* arr, int longitud){
    int i,impar,b;
    for(i=0;i<longitud;i++){
        if(arr[i]%2!=0){
            impar = arr[i];
            b=1;
        }
    }
    if(b==1){
        return impar;
    }
    return -1;
}
int hasCapitalizedWord(char* arr,int longitud){
	int i;
	for(i=0;i<longitud;i++){
	    if((arr[i]>='A' && arr[i]<='Z')&&(i==0 || arr[i-1]==' ')){
			return 1;
		}
	}
	return 0;
}
char* function(char* cadena, char c,int longitud){
	char flag = 0;
	int cad2Long = 1;
	char* cadena2 = (char*)malloc(cad2Long*sizeof(char));
	for(int i=0, j=0; i<longitud; i++){
		if(cadena[i]==c){
			flag=1;
		}
		if(flag){
			cadena2[j++] = cadena[i];
			cadena2 = (char*)realloc(cadena2,++cad2Long);
		}
	if (flag){
		cadena2[cad2Long] = '\0';
    }
	else{
		free(cadena2);
		cadena2 = NULL;
    }
	return cadena2;
    }
}
