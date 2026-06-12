#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTENEDORES 40 // Máximo 40 contenedores【271164038037519427149†L7-L8】

int pesos[MAX_CONTENEDORES];
int cantidad = 0;
int ordenado = 0; // 0 = no ordenado, 1 = ordenado【251521347900069864407†L13-L14】

// Funciones que vas a usar
void registrarManual();
void generarAleatorio();
void mostrarContenedores();
void ordenarQuickSort(int arr[], int bajo, int alto);
void buscarBinaria(int arr[], int n, int objetivo);
void intercambiar(int* a, int* b);

// Menú principal
int main() {
    srand(time(NULL)); // Semilla para números aleatorios【251521347900069864407†L7-L8】
    int opcion;

    do {
        printf("\n========================================\n");
        printf("SISTEMA DE ORGANIZACIÓN DE CONTENEDORES\n");
        printf("MUELLE DE CARGA\n");
        printf("========================================\n");
        printf("1. Registrar peso de contenedores manualmente\n");
        printf("2. Generar pesos aleatorios de contenedores\n");
        printf("3. Mostrar contenedores registrados\n");
        printf("4. Ordenar contenedores - QuickSort\n");
        printf("5. Buscar contenedor\n");
        printf("6. Salir\n");
        printf("========================================\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: registrarManual(); ordenado = 0; break;
            case 2: generarAleatorio(); ordenado = 0; break;
            case 3: mostrarContenedores(); break;
            case 4:
                ordenarQuickSort(pesos, 0, cantidad - 1);
                ordenado = 1;
                printf("Ordenado correctamente!\n");
                break;
            case 5:
                if(ordenado == 0) {
                    printf("Primero debes ordenar el arreglo!\n");
                } else {
                    int objetivo;
                    printf("Ingrese peso a buscar: ");
                    scanf("%d", &objetivo);
                    buscarBinaria(pesos, cantidad, objetivo);
                }
                break;
            case 6: printf("Saliendo...\n"); break;
            default: printf("Opción inválida\n");
        }
    } while(opcion!= 6);
    return 0;
}

void registrarManual() {
    printf("¿Cuántos contenedores vas a registrar? ");
    scanf("%d", &cantidad);
    for(int i = 0; i < cantidad; i++) {
        printf("Peso del contenedor %d en kg: ", i+1);
        scanf("%d", &pesos[i]);
    }
}

void generarAleatorio() {
    printf("¿Cuántos contenedores generar? ");
    scanf("%d", &cantidad);
    for(int i = 0; i < cantidad; i++) {
        pesos[i] = rand() % 30001; // Números entre 0 y 30000【261342692968794645778†L1-L2】
    }
    printf("Pesos generados aleatoriamente!\n");
}

void mostrarContenedores() {
    printf("\nContenedores registrados:\n");
    for(int i = 0; i < cantidad; i++) {
        printf("Contenedor %d: %d kg\n", i+1, pesos[i]);
    }
}

// QuickSort - Método 1
void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;
    for(int j = bajo; j < alto; j++) {
        if(arr[j] < pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i+1], &arr[alto]);
    return i+1;
}

void ordenarQuickSort(int arr[], int bajo, int alto) {
    if(bajo < alto) {
        int pi = particion(arr, bajo, alto);
        ordenarQuickSort(arr, bajo, pi - 1);
        ordenarQuickSort(arr, pi + 1, alto);
    }
}

// Búsqueda binaria
void buscarBinaria(int arr[], int n, int objetivo) {
    int inicio = 0, fin = n - 1;
    while(inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if(arr[medio] == objetivo) {
            printf("Encontrado en la posición %d\n", medio+1);
            return;
        }
        if(arr[medio] < objetivo) inicio = medio + 1;
        else fin = medio - 1;
    }
    printf("No encontrado\n");
}

