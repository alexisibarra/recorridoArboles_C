CC = gcc
CFLAGS = 
OBJS = arbol.o treesLevel.o utiles.o

treesLevel: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@

arbol.o: arbol.c arbol.h
	$(CC) $(CFLAGS) -c arbol.c

treesLevel.o: treesLevel.c arbol.h
	$(CC) $(CFLAGS) -c treesLevel.c

utiles.o: utiles.c utiles.h
	$(CC) $(CFLAGS) -c utiles.c

clean:
	/bin/rm *.o treesLevel
