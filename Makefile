all: exec
main.o: head.h main.c
	gcc -c main.c -o main.o

avl.o: head.h avl.c
	gcc -c avl.c -o avl.o

exec: main.o avl.o
	gcc *.o -o exec
	
clear:
	rm -f *.o
	rm exec
