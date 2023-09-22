#include <stdio.h>
#include <stdlib.h>
void CrearTeatroyMenu(int r, int c);
void VaciarAsientos(int r, int c,int M[r][c]);
void ventaBoletos(int r,int c,int M[r][c]);//1)
void Disponibles(int r,int c, int M[r][c]);//2)
void Vendidos(int r, int c, int M[r][c]);//3)
float Totalvendido(int r, int c, int M[r][c], float sum);//4
void Teatro(int r, int c,int M[r][c]);//5)
void CancelarB(int r, int c, int M[r][c]);//6
int main(){
    int rows,cols;
    printf("Dame el numero filas: ");
    scanf("%d",&rows);
    printf("Dame el numero de asientos por fila: ");
    scanf("%d",&cols);
    CrearTeatroyMenu(rows,cols);//Quise hacer la formacion del teatro algo mas dinamico, la matriz sera formada siempre segun decida el usuario.
    return 0;
}
void CrearTeatroyMenu(int rows, int cols){
    int M[rows][cols],opc,b;
    float total=0;
    VaciarAsientos(rows, cols,M);//Esta parte la forme ya que ocurria un error cuando elegia cualquiera de las opciones del menu,
    // aparecian asientos vendidos que en realidad nunca se compraron, entonces para evitar eso llene todos los asientos con el valor 0.
    do{
        printf("-------ELIGE UNA OPCION-------\ni. Venta de boletos\nii. Asientos disponibles\niii. Asientos vendidos\niv. Total vendido\nv. Mostrar todos los asientos\nvi. Cancelar boleto\n");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                ventaBoletos(rows,cols,M);
                break;
            case 2:
                Disponibles(rows,cols,M);
                break;
            case 3:
                Vendidos(rows,cols,M);
                break;
            case 4:
                printf("Total vendido: %.2f$",total = Totalvendido(rows,cols,M,total));
                break;
            case 5:
                Teatro(rows,cols,M);
                break;
            case 6:
                CancelarB(rows,cols,M);
                break;
            default:
                printf("\nOpcion no existente.");
                break;
        }
        printf("\nDesea usar otra opcion? \n1. Si \nCualquier otro numero. No\n");
        scanf("%d",&b);
    }while(b==1);
}
void VaciarAsientos(int r, int c,int M[r][c]){
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            M[i][j] = 0;
        }
    }
}
void ventaBoletos(int r, int c, int M[r][c]){
    int f;
    char ch;
    printf("Fila 5: $2.50\nFila 4: $5.00\nFila 3: $7.50\nFila 2: $10.00\nFila 1: $12.50\n'X' = vendidos. '-' = disponibles.\n");
    Teatro(r,c,M);
    printf("\nIntroduce numero y letra del asiento.\n");
    do{
        scanf("%d %c",&f,&ch);
        if(M[f-1][ch-'A']==1){
            printf("Este asiento ya esta vendido, elige otro.");
        }
    }while(M[f-1][ch-'A']==1);
    M[f-1][ch-'A']=1;
    printf("Haz comprado el boleto [%d%c].\n",f,ch);
}
void Teatro(int r, int c, int M[r][c]){
    printf("\n'X' = vendidos. '-' = disponibles.\n");
    if (r>9){
        printf(" ");
    }
    for (int i =0;i<c;i++){
        printf("  %c",i+'A');
    }
    for (int i=0;i<r;i++){
        printf("\n%d",i+1);
        if (i<9){//Termina hasta 9, i=8 seria el indice maximo que representan los numeros del 1 al 9. (i=8 es indice de 9)
            printf(" ");//En caso de que sean mas de 10 asientos
        }
        for(int j=0;j<c;j++){
            printf("[");
            if(M[i][j]==1){
                printf("X");
            }
            else{
                printf("-");
            }
            printf("]");
        }
    }
    printf("\n");
}
void Disponibles(int r, int c, int M[r][c]){
    printf("\nAsientos disponibles:\n ");
    for (int i =0;i<c;i++){
        printf("   %c",i+'A');
        if (r>9){
            printf(" ");
        }
    }
    for (int i=0;i<r;i++){
        printf("\n%d ",i+1);
        if(r>9&&i<9){
            printf(" ");
        }
        for(int j=0;j<c;j++){
            if(M[i][j]==0){
                printf("[%d%c]",i+1,'A'+j);
            }
            else{
                printf("     ");
            }
            if(r>9&&i<9){
                printf(" ");
            }
        }
    }
}
void Vendidos(int r, int c, int M[r][c]){
    printf("\nAsientos vendidos:\n ");
    for (int i =0;i<c;i++){
        printf("   %c",i+'A');
        if (r>9){
            printf(" ");
        }
    }
    for (int i=0;i<r;i++){
        printf("\n%d ",i+1);
        if(r>9&&i<9){
            printf(" ");
        }
        for(int j=0;j<c;j++){
            if(M[i][j]==1){
                printf("[%d%c]",i+1,'A'+j);
            }
            else{
                printf("     ");
            }
            if(r>9&&i<9){
                printf(" ");
            }
        }
    }
}
float Totalvendido(int r, int c, int M[r][c], float sum){
    for (int i =0;i<r;i++){
        for(int j =0;j<c;j++){
            if(M[i][j]==1){
                sum +=2.5*(r-i);
            }
        }
    }
    return sum;
}
void CancelarB(int r, int c, int M[r][c]){
    int i;
    char ch;
    printf("\nDame el numero y la letra del asiento del boleto a cancelar.");
    scanf("%d %c",&i,&ch);
    if(M[i-1][ch-'A']==1){
        M[i-1][ch-'A']=0;
        printf("Boleto cancelado.");
    }
    else{
        printf("\nEste asiento no ha sido vendido.");
    }
}
