all: exec
sort.o: avl_struct.h head.h sort.c
	gcc -c sort.c -o sort.o

avl.o: avl_struct.h head.h avl.c
	gcc -c avl.c -o avl.o

exec: sort.o avl.o
	gcc *.o -o exec
