CC = gcc
CFLAGS = 
OBJS = prueba.o arbol.o utiles.o

prueba: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@

arbol.o: arbol.c arbol.h
	$(CC) $(CFLAGS) -c arbol.c

utiles.o: utiles.c utiles.h
	$(CC) $(CFLAGS) -c utiles.c

clean:
	/bin/rm *.o prueba
