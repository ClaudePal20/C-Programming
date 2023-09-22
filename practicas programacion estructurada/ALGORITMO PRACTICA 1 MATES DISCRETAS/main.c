#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[14][14];
    char nodos[17]={"ABCDEFGHIJKLMNOPQ"};
    for (int i=0;i<14;i++){
        printf("\nIntroduce con que nodos esta conectado el nodo [%c]",nodos[i]);
        for(int j=0;j<14;j++){
            do{
                printf("El nodo [%c] esta conectado con el nodo [%c]?\n1. Si\n0. No",nodos[i],nodos[j]);
                scanf("%d",&A[i][j]);
            }while(A[i][j]!=0&&A[i][j]!=1);
        }
    }
    return 0;
}
