CC = gcc
CFLAGS = 
OBJS = arbol.o treesLevel.o utiles.o cola.o recorridos.o

treesLevel: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@

arbol.o: arbol.c arbol.h
	$(CC) $(CFLAGS) -c arbol.c

treesLevel.o: treesLevel.c arbol.h
	$(CC) $(CFLAGS) -c treesLevel.c

utiles.o: utiles.c utiles.h
	$(CC) $(CFLAGS) -c utiles.c

cola.o: cola.c cola.h
	$(CC) $(CFLAGS) -c cola.c

recorridos.o: recorridos.c recorridos.h
	$(CC) $(CFLAGS) -c recorridos.c

clean:
	/bin/rm *.o treesLevel
