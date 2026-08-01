#ifndef DESTINO_H
#define DESTINO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==========================
    ESTRUCTURAS ADELANTADAS
===========================*/

typedef struct Pasajero Pasajero;
typedef struct Viaje Viaje;

/*==========================
        COLA FIFO
===========================*/

typedef struct{

    Pasajero *frente;
    Pasajero *final;

}ColaPasajeros;

/*==========================
      ESTRUCTURA DESTINO
===========================*/

typedef struct Destino{

    int codigo;
    char nombre[50];
    char empresa[50];

    ColaPasajeros cola;

    Viaje *raizAVL;

    int pasajerosEmbarcados;

    struct Destino *siguiente;

}Destino;

/*==========================
     LISTA DE DESTINOS
===========================*/

typedef struct{

    Destino *frente;
    Destino *final;

}ListaDestinos;

/*==========================
      FUNCIONES GENERALES
===========================*/

void inicializarListaDestinos(ListaDestinos *lista);

int listaVacia(ListaDestinos *lista);

void registrarDestino(ListaDestinos *lista);

Destino *buscarDestinoCodigo(ListaDestinos *lista,int codigo);

void buscarDestino(ListaDestinos *lista);

void mostrarDestinos(ListaDestinos *lista);

void modificarDestino(ListaDestinos *lista);

void liberarDestinos(ListaDestinos *lista);

#endif