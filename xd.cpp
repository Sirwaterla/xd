#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumnos
{
    char matricula[20];
	char nombre[20];
	char appat[20];
	char apmat[20];
	int edad;
	char carrera[50];
	char grupo[20];
	float calif;
	
    
} ALUMNOS;


void ingresar(ALUMNOS *L,int n);

void imprimir(ALUMNOS *L,int n);

void most_uno(ALUMNOS *L,int n);

void modificar(ALUMNOS *L,int n);

void baja(ALUMNOS *L,int n);

void promedio(ALUMNOS *L,int n);

void reporte(ALUMNOS *L,int n);


int main()
{
	int n,i;   
	         
    ALUMNOS *L ;
    FILE *archivo;
	               
    L = (ALUMNOS *)malloc(sizeof(ALUMNOS));
    

  
    puts("Digite el numero de alumnos a ingresar:");
    scanf("%d",&n);
    
    int opcion;
	do
	{
		puts("1. Alta de alumnos");
		puts("2. Buscar alumno");
		puts("3. Consulta general");
		puts("4. Modificar un dato");
		puts("5. Baja de alumno");
		puts("6. Promedio general");
		puts("7. Imprimir reporte");
		puts("8. Salir");
		scanf(" %d",&opcion);
		
		switch(opcion)
		{
		case 1:  
	        ingresar(L,n); 
	        break;
	    case 2:  
	        most_uno(L,n); 
	        break;
	    case 3:  
	        imprimir(L,n);
	        break;
		case 4:  
	        modificar(L,n);
	        break;
	    case 5:  
	        baja(L,n);
	        break;		
		case 6:  
	        promedio(L,n);
	        break;	
	    case 7:
	    	archivo = fopen("alumnos.txt","w");
	    	if(archivo==NULL)
	    	{
	    		fprintf(stderr,"No es posible abrir");
	    		exit(1);
			}
			for(i=0;i<n;i++)
			{
				fwrite(&L[i],sizeof(struct alumnos),1,archivo);
			}
			if(feof(archivo))
				printf("Error al escribir el archivo\n");
			else
				printf("Es posible escribir\n");
			fclose(archivo);
	    	break;
		case 8:
	        printf("El sistema de gestión de inventario de productos básicos se retirará pronto ...");
	        exit(0);
        default:
            printf("La instrucción que ingresó es incorrecta, vuelva a ingresar");       
		}
	}while(opcion!=8);
}




void ingresar(ALUMNOS *L, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Introduzca la matricula:");
	    scanf(" %[^\n]", L[i].matricula);
	    printf("Introduzca el nombre del alumno:");
	    scanf(" %[^\n]", L[i].nombre);
	    printf("Introduzca el apellido paterno:");
	    scanf(" %s", L[i].appat);
	    printf("Introduzca el apellido materno:");
	    scanf(" %s", L[i].apmat);
	    printf("Introduzca la edad:");
	    scanf(" %d", &L[i].edad);
	    printf("Introduzca la carrera en curso:");
	    scanf(" %[^\n]", L[i].carrera);
	    printf("Introduzca el grupo:");
	    scanf(" %s", L[i].grupo);
	    printf("Introduzca la calificacion:");
	    scanf(" %f", &L[i].calif);
	}
	
}

void most_uno(ALUMNOS *L,int n)
{
	puts("Esta seccion busca a un alumno por su matricula");
	puts("DIGITE LA MATRICULA");
	
	int i;
	char matri[20];
	int comp;
	puts("En esta seccion se imprimen los datos de un alumno");
	puts("MEDIANTE SU MATRICULA PERSONAL");
	puts("Digite la Matricula");
	scanf(" %[^\n]",matri);
	
	for(i=0;i<n;i++)
	{
		comp=strcmp(L[i].matricula,matri);
		if(comp==0)
		{
			printf("---------------------------\n");
			printf("Matricula: %s Nombre: %s %s %s\n",L[i].matricula,L[i].nombre,L[i].appat,L[i].apmat);
			printf("Edad: %d Carrera: %s Grupo: %s\n",L[i].edad,L[i].carrera,L[i].grupo);
			printf("Calificacion: %.2f \n",L[i].calif); 
			printf("---------------------------\n");
		}
	}
}
void imprimir(ALUMNOS *L,int n)
{
	
	
	
    char temporal[20];
    int x, indiceActual;
    for (x = 0; x < n; x++)
    {
        for (indiceActual = 0; indiceActual < n - 1;
             indiceActual++)
        {
            int indiceSiguienteElemento = indiceActual + 1;
            
            if (strcmp(L[indiceActual].matricula, L[indiceSiguienteElemento].matricula) > 0)
            {
                memcpy(temporal, L[indiceActual].matricula, 20);
                
                memcpy(L[indiceActual].matricula, L[indiceSiguienteElemento].matricula, 20);
                // Y en el siguiente elemento, lo que había antes en el actual pero ahora está en temporal
                memcpy(L[indiceSiguienteElemento].matricula, temporal, 20);
            }
        }
    }
    int i;
    for (i = 0;i < n; i++)
    {
       printf("---------------------------\n");
		printf("Matricula: %s Nombre: %s %s %s\n",L[i].matricula,L[i].nombre,L[i].appat,L[i].apmat);
		printf("Edad: %d Carrera: %s Grupo: %s\n",L[i].edad,L[i].carrera,L[i].grupo);
		printf("Calificacion: %.2f \n",L[i].calif); 
		printf("---------------------------\n");
    }
}
       
          
	



void modificar(ALUMNOS *L,int n)
{
	int i;
	char matri[20];
	int comp;
	puts("En esta seccion se modifican los datos de un alumno");
	puts("MEDIANTE SU MATRICULA PERSONAL");
	puts("Digite la Matricula");
	scanf(" %[^\n]",matri);
	
	for(i=0;i<n;i++)
	{
		comp=strcmp(L[i].matricula,matri);
		if(comp==0)
		{
			printf("Digite el matricula\n");
			scanf(" %[^\n]",L[i].matricula);
			printf("Digite el nombrer\n");
			scanf(" %[^\n]",L[i].nombre);
			printf("Digite el apellido paterno\n");
			scanf(" %[^\n]",L[i].appat);
			printf("Digite el apellido materno\n");
			scanf(" %[^\n]",L[i].apmat);
			printf("Digite la edad\n");
			scanf(" %d",&L[i].edad);
			printf("Digite la carrera \n");
			scanf(" %[^\n]",L[i].carrera);
			printf("Digite el grupo\n");
			scanf(" %[^\n]",L[i].grupo);
			printf("Digite la calificacion \n");
			scanf(" %f",&L[i].calif);
		}
	}
}

void baja(ALUMNOS *L,int n)
{
	  
   
}

void promedio(ALUMNOS *L,int n)
{
	float suma=0;
	float prom=0;
	int i;
	for(i=0;i<n;i++)
	{
		suma=suma+L[i].calif;
	}
	prom=suma/n;
	printf("El promedio es: %.2f\n",prom);
}

void reporte(ALUMNOS *L,int n)
{
	
	
	FILE *fichero;

	/* Abrimos "fichero1.txt" en modo texto y
	 * guardamos su direccion en el puntero. */
	fichero = fopen("fichero1.txt", "rt");

	/* Imprimimos la direccion para este ejemplo. */
	printf("%S\n",fichero);

	/* Cerramos "fichero1.txt". */
	fclose(fichero);
	
}
