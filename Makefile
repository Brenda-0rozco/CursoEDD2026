#=========================================
#       MAKEFILE
# Terminal Portuario Turístico
#=========================================

CC=gcc

CFLAGS=-Wall -Wextra

OBJ=main.o destino.o pasajero.o avl.o estadisticas.o

PROGRAMA=terminal

all: $(PROGRAMA)

$(PROGRAMA): $(OBJ)
	$(CC) $(OBJ) -o $(PROGRAMA)

main.o: main.c destino.h pasajero.h avl.h estadisticas.h
	$(CC) $(CFLAGS) -c main.c

destino.o: destino.c destino.h pasajero.h avl.h
	$(CC) $(CFLAGS) -c destino.c

pasajero.o: pasajero.c pasajero.h destino.h
	$(CC) $(CFLAGS) -c pasajero.c

avl.o: avl.c avl.h destino.h
	$(CC) $(CFLAGS) -c avl.c

estadisticas.o: estadisticas.c estadisticas.h destino.h pasajero.h
	$(CC) $(CFLAGS) -c estadisticas.c

clean:
	rm -f *.o $(PROGRAMA)