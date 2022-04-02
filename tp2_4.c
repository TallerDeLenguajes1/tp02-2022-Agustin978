#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Computadora
{
    int velocidad;
    int anio;
    int cantidad_nucleos;
    char *tipo_cpu; //valores almacenados en un arreglo
    struct Computadora* siguiente;
};

typedef struct Computadora* Compu;
//Declaracion de funciones
Compu creaListado(); //Crea listado de computadoras
Compu ingresaCompu(Compu C, int velocidad, int anio, int cantidad_nucleos, char *tipo); //Ingresa una nueva computadora
void caracteristicas(Compu C); //Presenta un listado con las caracteristicas de las computadoras
void masVieja(Compu C); //Print con la computadora mas vieja almacenada
void masVeloz(Compu C); //Print con la computadora con mas velocidad

int main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    Compu C = creaListado();
    int i, vel, year, cant, tip;
    srand((int)time(NULL));
    
    for(i=0; i<5; i++)
    {
        vel = 1 + rand() % 3;
        year = rand() %  8 + 2015;
        cant = 1 + rand() % 8;
        tip = rand() % 6;
        C = ingresaCompu(C, vel, year, cant, tipos[tip]);
    }

    caracteristicas(C);
    printf("\n\n=====Computadora mas Vieja=====\n");
    masVieja(C);
    printf("\n\n=====Computadora mas Veloz=====\n");
    masVeloz(C);
    //printf("\n%s\n\n", tipos[2]);
    printf("\n\n");
    return 0;
}

Compu creaListado()
{
    return NULL;
}

Compu ingresaCompu(Compu C, int velocidad, int anio, int cantidad_nucleos, char *tipo)
{
    Compu nueva = (Compu) malloc(sizeof(Compu));
    nueva->velocidad = velocidad;
    nueva->anio = anio;
    nueva->cantidad_nucleos = cantidad_nucleos;
    nueva->tipo_cpu = tipo;
    nueva->siguiente = C;
    C = nueva;
    return C;
}

void caracteristicas(Compu C)
{
    Compu seguidor = C;
    printf("\n=======Caracteristicas de las Computadoras=======\n");
    while (seguidor!=NULL)
    {
        printf("\nTipo de CPU: %s / Velocidad de procesador: %d GHz/ Cantidad de nucleos: %d / Año de fabricacion: %d.", seguidor->tipo_cpu, seguidor->velocidad, seguidor->cantidad_nucleos, seguidor->anio);
        seguidor = seguidor->siguiente;
    }
}

void masVieja(Compu C)
{
    int max = 20000;
    Compu auxiliar;
    while (C!=NULL)
    {
        if(C->anio < max)
        {
            max = C->anio;
            auxiliar = C;
        }
        C = C->siguiente;
    }
    printf("\nLa Computadora mas vieja es del año %d, y presenta las siguientes caracteristicas:\n", auxiliar->anio);
    printf("Tipo de CPU: %s / Velocidad de procesador: %d GHz/ Cantidad de nucleos: %d", auxiliar->tipo_cpu, auxiliar->velocidad, auxiliar->cantidad_nucleos);
}

void masVeloz(Compu C)
{
    int max = 0;
    Compu auxiliar;
    while (C!=NULL)
    {
        if(C->velocidad > max)
        {
            max = C->velocidad;
            auxiliar = C;
        }
        C = C->siguiente;
    }
    printf("\nLa Computadora mas veloz es del año %d, y presenta las siguientes caracteristicas:\n", auxiliar->anio);
    printf("Tipo de CPU: %s / Velocidad de procesador: %d GHz/ Cantidad de nucleos: %d", auxiliar->tipo_cpu, auxiliar->velocidad, auxiliar->cantidad_nucleos);
}
