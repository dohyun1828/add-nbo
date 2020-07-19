all: add-nbo

add-nbo: add.o
	gcc -o add-nbo add.o

add.o: add.c
	gcc -c -o add.o add.c

clean: 
	rm -f add-nbo *.o