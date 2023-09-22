#include <stdio.h>
#include <stdlib.h>
void imprimir(int al, int m, int matriz[al][m]);
void capturar(int al, int m, int matriz[al][m]);
void promMayMen(int al,int m,int matriz[al][m]);
void alumno(int num,int al,int m,int matriz[al][m]);
int main(){
    int matriz[50][7],al,m,opc,opc2,b=0,b2=0,num;
    float suma;
    do{
        printf("Elige una opcion.\n1.Capturar cantidad de estudiantes y materias.\n2.Generar informacion del estudiante\n3.Imprimir matriz de estudiantes y materias\n4.Imprimir el promedio grupal, el mayor y el menor.\n5.Imprimir informacion de un estudiante.\n");
        scanf("%d",&opc2);
        if(opc2==1){
            do{
                printf("\nDame la cantidad de alumnos (Maximo de 50): ");
                scanf("%d",&al);
                if(al>50||al<0){
                    printf("\nIntroduciste un valor fuera del limite. Vuelve a introducirlo.");
                }
            }while(al>50||al<0);
            do{
                printf("\nDame la cantidad de materias (Maximo de 7): ");
                if(al>7||al<0){
                    printf("\nIntroduciste un valor fuera del limite. Vuelve a introducirlo.");
                }
            }while(al>7||al<0);
            scanf("%d",&m);
            b=1;
            b2 = 1;
        }
        else if(opc2 == 2){
            if(b2==1){
                printf("\nDimensiones: %d alumnos y %d materias.",al,m);
                capturar(al,m,matriz);
            }
            else{
                printf("\nUsaremos el tamano maximo para las dimensiones (50 alumnos y 7 materias).");
                capturar(50,7,matriz);
            }
            b = 1;
        }
        else if(opc2==3&&b==1){
            if(b2==1){
                imprimir(al,m,matriz);
            }
            else{
                imprimir(50,7,matriz);
            }
        }
        else if(opc2==4&&b==1){
            promMayMen(al,m,matriz);
        }
        else if(opc2==5&&b==1){
            printf("\nIntroduce el numero del alumno.\n");
            scanf("%d",&num);
            num-=1;
            alumno(num,al,m,matriz);
        }
        else if (b==0){
            printf("No haz capturado algun dato para formar la matriz. Utiliza la opcion 1 o 2.\n");
        }
        printf("\nDeseas usar otra opcion?\n1. Si\nCualquier otro numero. No\n");
        scanf("%d",&opc);
        printf("\n");
    }while(opc==1);
    return 0;
}
void capturar(int al, int m, int matriz[al][m]){
    int num;
    printf("\nIntroduce solo numeros del 0 al 10");
    for (int i =0;i<al;i++){
        printf("\nCalificaciones del alumno [%d]",i+1);
        for(int j =0;j<m;j++){
            do{
                printf("\nCalificacion de la materia [%d]: ",j+1);
                scanf("%d",&matriz[i][j]);
                if(matriz[i][j]>10 || matriz[i][j]<0){
                    printf("\nIntroduciste un numero fuera del rango permitido. Vuelvelo a introducir.");
                }
            }while(matriz[i][j]>10 || matriz[i][j]<0);
        }
    }
}
void imprimir(int al, int m, int matriz[al][m]){
    for (int i =0;i<al;i++){
        printf("\nCalificaciones del alumno [%d]",i+1);
        for(int j =0;j<m;j++){
            printf("\nCalificacion de la materia [%d]: %d",j+1,matriz[i][j]);
        }
    }
    printf("\n");
}
void promMayMen(int al,int m,int matriz[al][m]){
    float prom=0,suma=0,promtemp,menor,mayor;
    int menorI,mayorI;
    for (int i = 0;i<al;i++){
        for(int j =0;j<m;j++){
            suma = suma + matriz[i][j];
        }
    }
    prom = suma/(al*m);
    printf("\nPromedio grupal: %f",prom);
    menor = prom;
    mayor = prom;
    for (int i = 0;i<al;i++){
        suma=0;
        for(int j =0;j<m;j++){
            suma = suma + matriz[i][j];
        }
        suma = suma/(m);
        if(suma<menor){
            menor = suma;
            menorI = i;
        }
        else if(suma > mayor){
            mayor = suma;
            mayorI = i;
        }
    }
    printf("\nEl promedio mas bajo fue de %f del alumno %d \ny el mas alto fue de %f del alumno %d",menor,menorI+1,mayor,mayorI+1);
}
void alumno(int num,int al,int m,int matriz[al][m]){
    float suma = 0;
    for(int i = 0;i<m;i++){
        printf("\nCalificacion [%d]",matriz[num][i]);
        suma = suma + matriz[num][i];
    }
    suma = suma/m;
    printf("\nPromedio de: %f",suma);
    if(suma<6){
        printf("\nNo aprobado (menor a 6)\n");
    }
    else{
        printf("\nAprobado\n");
    }
}
