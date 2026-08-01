# Terminal Portuario Turístico de Buenaventura

## Descripción

Este proyecto fue desarrollado en lenguaje C como trabajo de la asignatura **Estructura de Datos**.

El sistema permite administrar el funcionamiento básico del Terminal Portuario Turístico de Buenaventura utilizando estructuras dinámicas de datos, incluyendo colas FIFO y árboles AVL.

El programa gestiona:

- Destinos turísticos.
- Pasajeros en espera.
- Viajes programados.
- Empresas responsables.
- Estadísticas generales del sistema.

---

# Estructuras de Datos Utilizadas

## Cola FIFO

Cada destino posee una cola independiente de pasajeros.

El primer pasajero registrado será el primero en embarcar.

Operaciones implementadas:

- Registrar pasajero.
- Consultar primer pasajero.
- Embarcar pasajero.
- Mostrar pasajeros.
- Buscar pasajero.
- Contar pasajeros.
- Verificar cola vacía.

---

## Árbol AVL

Cada destino administra sus viajes mediante un Árbol AVL.

Los viajes se almacenan por código y el árbol se balancea automáticamente mediante rotaciones.

Rotaciones implementadas:

- Rotación simple izquierda.
- Rotación simple derecha.
- Rotación doble izquierda-derecha.
- Rotación doble derecha-izquierda.

---

# Funcionalidades

- Registrar destinos.
- Buscar destino.
- Modificar destino.
- Mostrar destinos.
- Registrar pasajeros.
- Mostrar pasajeros.
- Registrar viajes.
- Buscar viajes.
- Mostrar árbol AVL.
- Embarcar pasajeros.
- Consultar pasajero.
- Mostrar estadísticas.

---

# Archivos del Proyecto

```
TerminalPortuario
│
├── main.c
├── destino.h
├── destino.c
├── pasajero.h
├── pasajero.c
├── avl.h
├── avl.c
├── estadisticas.h
├── estadisticas.c
├── Makefile
└── README.md
```

---

# Compilación

Compilar utilizando GCC.

```
make
```

También puede compilarse manualmente con:

```
gcc main.c destino.c pasajero.c avl.c estadisticas.c -o terminal
```

---

# Ejecución

Linux

```
./terminal
```

Windows

```
terminal.exe
```

---

# Limpiar archivos objeto

```
make clean
```

---

# Requisitos

- Lenguaje C
- GCC
- Uso de memoria dinámica mediante malloc y free
- Uso de apuntadores
- Árbol AVL
- Cola FIFO

---

# Autores

BRENDA OROZCO

Universidad del Pacífico

Terminal Portuario Turístico de Buenaventura.

---

# Licencia

