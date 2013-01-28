CC = gcc
CFLAGS = 
OBJS = arbol.o treesLevel.o utiles.o amplitud.o

treesLevel: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@

treesLevel.o: treesLevel.c arbol.h
	$(CC) $(CFLAGS) -c treesLevel.c

arbol.o: arbol.c arbol.h
	$(CC) $(CFLAGS) -c arbol.c

utiles.o: utiles.c utiles.h
	$(CC) $(CFLAGS) -c utiles.c

recorridos.o: recorridos.c recorridos.h
	$(CC) $(CFLAGS) -c recorridos.c

amplitud.o: amplitud.c amplitud.h
	$(CC) $(CFLAGS) -c amplitud.c

clean:
	/bin/rm *.o treesLevel
