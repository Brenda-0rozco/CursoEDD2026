#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include <stdio.h>
#include <stdlib.h>

#include "destino.h"

/*=========================================
        FUNCIONES ESTADISTICAS
=========================================*/

int totalPasajeros(ListaDestinos *lista);

int totalEmbarcados(ListaDestinos *lista);

float promedioPasajeros(ListaDestinos *lista);

float promedioEmbarcados(ListaDestinos *lista);

Destino *destinoMayorEspera(ListaDestinos *lista);

Destino *destinoMenorEspera(ListaDestinos *lista);

void mostrarEstadisticas(ListaDestinos *lista);

#endif