CC = gcc
CFLAGS = 
OBJS = arbol.o treesLevel.o

treesLevel: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@

arbol.o: arbol.c arbol.h
	$(CC) $(CFLAGS) -c arbol.c

treesLevel.o: treesLevel.c arbol.h
	$(CC) $(CFLAGS) -c treesLevel.c

clean:
	/bin/rm *.o treesLevel
