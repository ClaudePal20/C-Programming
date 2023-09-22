#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Alumno{
    char *nombre;
    int matricula;
    int *materias;
    int *calificaciones;
    int cantidadMaterias;
}Alumno;
void RegistrarAlumno(Alumno **alumnos, int *cantidadAlumnos);
struct Alumno* buscarAlumno(Alumno *alumno, int cantidadAlumnos,int matricula);
void capturaCalificaciones(Alumno *alumno);
int main(){
    int opc,cantidadAlumnos=1,matricula,opc2;
    Alumno *Alumnos=NULL;// inciso a)
    do{
        printf("\nElige opcion: \n1.Registrar alumno\n2.Capturar calificaciones\n3.Buscar alumno\n4.Dar de baja");
        scanf("%d",&opc);
        switch(opc){
        case 1:
            RegistrarAlumno(&Alumnos,&cantidadAlumnos);
            break;
        case 2:
            printf("\nDame la matricula del alumno a capturar calificaciones:");
            scanf("%d",&matricula);
            capturaCalificaciones(buscarAlumno(Alumnos,cantidadAlumnos,matricula));
            break;
        case 3:
            printf("\nDame la matricula del alumno a buscar:");
            scanf("%d",&matricula);
            buscarAlumno(Alumnos,cantidadAlumnos,matricula);
            break;
        case 4:
            break;
        }
        printf("\nDeseas usar otra opcion? \n1. Si\n2. No");
        scanf("%d",&opc2);
    }while(opc2==1);
    return 0;
}
void RegistrarAlumno(Alumno **alumnos, int *cantidadAlumnos){
    int matricula = rand()%10000;
    *alumnos = (Alumno*)realloc(*alumnos,sizeof(Alumno)*(*cantidadAlumnos));
    Alumno a;
    a.nombre=(char*)malloc(30);
    printf("\nIntroduce nombre: ");
    fflush(stdin);
    gets(a.nombre);
    fflush(stdin);
    a.nombre=(char*)realloc(a.nombre,strlen(a.nombre)+1);//Desocupamos espacio no usado
    printf("Introduce cantidad de materias; ");
    scanf("%d",&a.cantidadMaterias);
    printf("Introduce matricula; ");
    scanf("%d",&a.matricula);
    a.materias=(int*)malloc(a.cantidadMaterias*sizeof(int));
    a.calificaciones=(int*)malloc(a.cantidadMaterias*sizeof(int));
    for(int i=0;i<a.cantidadMaterias;i++){
        printf("\nIngresa la clave de la materia [%d]: ",i+1);
        scanf("%d",&a.materias);
    }
}
Alumno* buscarAlumno(Alumno *alumno, int cantidadAlumnos,int matricula){
    int i =0;
    do{
        if(alumno[i].matricula==matricula){
            printf("\nNombre: %s\nCantidad de materias: %d\nMatricula: %d",alumno->nombre,alumno->cantidadMaterias,alumno->matricula);
            for(int i=0;i<alumno[i].cantidadMaterias;i++){
                printf("\nMateria %d, calificacion: %d",alumno->materias,alumno->calificaciones);
            }
            return &alumno[i];
        }
        i++;
    }while(alumno->matricula!=matricula||i<cantidadAlumnos);
    return NULL;
}

void capturaCalificaciones(Alumno *alumno){
    if(alumno == NULL){
        printf("\nAlumno inexistente.");
    }
    for(int i=0;i<alumno->cantidadMaterias;i++){
        printf("\nIngresa calificacion de la materia[%d]: %d",i,alumno->materias[i]);
        scanf("%d",&alumno->calificaciones[i]);
    }
}
