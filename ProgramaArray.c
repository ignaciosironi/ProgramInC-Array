#include <stdio.h>

void cargar(int arreglo[8], int dim, int indice);
void mostrar(int arreglo[8],int dim, int indice, int min, int max);
void maxYMin(int arreglo[8], int dim, int indice, int min, int max);
void funcionPromedio (int arreglo [8], int dim, int indice, int suma, float promedio);
void ordenamiento(int arreglo[8], int dim, int indice);

int main()
{
    int dim=8, arreglo[8], indice=0, max, min, suma;
    float promedio;
    
    cargar(arreglo, dim, indice);
    mostrar(arreglo, dim, indice, min, max);
    maxYMin(arreglo, dim, indice, min, max);
    funcionPromedio (arreglo, dim, indice, suma, promedio);
    ordenamiento(arreglo, dim, indice);
    
    return 0;
}

void cargar(int arreglo[8], int dim, int indice){
    
    do{
        
        printf("Ingrese un número: ");
        scanf("%d",&arreglo[indice]);
        
        
       if(indice%2==0){
           while(arreglo[indice]%2==0||arreglo[indice]<0){
               printf("debe ingresar un número impar y positivo: ");
               scanf("%d",&arreglo[indice]);
           }
       }
       else if(indice%2!=0){
           while(arreglo[indice]>0){
               printf("debe ingresar un número negativo: ");
               scanf("%d", &arreglo[indice]);
           }
           
        }
        indice++;    
        
    }while(indice<dim);
}


void mostrar(int arreglo[8], int dim, int indice, int min, int max){
    while(indice<dim){
        printf("El número del arreglo, en la posición %d, es %d \n",indice,arreglo[indice]);
        indice++;
    }
}

void maxYMin(int arreglo[8], int dim, int indice, int min, int max){
    max=arreglo[indice];
    min=arreglo[indice];
    while(indice<dim){
        indice++;
        
        if(arreglo[indice]>max){
            max=arreglo[indice];
        }else if(arreglo[indice]<min){
            min=arreglo[indice];
        }
    }
    printf("El número mayor es %d. El número menor es %d \n", max, min);
}

void funcionPromedio (int arreglo [8], int dim, int indice, int suma, float promedio){
    suma=arreglo[indice];
    while(indice<dim){
        indice++;
        suma=suma+arreglo[indice];
    }
    
    printf("el valor del indice es: %d \n", indice);
    promedio=suma/indice;
    printf("el valor promedio es %f \n",promedio);
    
    indice=0;
    arreglo[indice]=promedio;
    
    printf("El array con el promedio de los números en el primero elemento es: \n");
    while(indice<dim){
        printf("El valor del arreglo en el elemento %d es %d \n",indice,arreglo[indice]);
        indice++;
    }
    
}

void ordenamiento(int arreglo[8], int dim, int indice){
    int cont=0;
    int mayor;
    int menor;
    
    while(cont<(dim-1)){
        mayor=arreglo[indice];
        while(indice<(dim-1)){
            indice++;
            if(arreglo[indice]<mayor){
                menor=arreglo[indice];
                arreglo[indice]=mayor;
                arreglo[indice-1]=menor;
            }
            mayor=arreglo[indice];
            
        }
        indice=0;
        cont++;
    }
    indice=0;
    printf("el arreglo ordenado de menor a mayor queda:");
    while(indice<dim){
        printf("%d, ",arreglo[indice]);    
        indice++;
    }
}