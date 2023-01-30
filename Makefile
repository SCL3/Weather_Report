all: exec
main.o: head.h main.c
	gcc -c main.c -o main.o

mto.o: head.h mto.c
	gcc -c mto.c -o mto.o
	
avl.o: head.h avl.c
	gcc -c avl.c -o avl.o
	
abr.o: head.h abr.c
	gcc -c abr.c -o abr.o
	
create_csv.o: head.h create_csv.c
	gcc -c create_csv.c -o create_csv.o

height.o: head.h height.c
	gcc -c height.c -o height.o

moisture.o: head.h moisture.c
	gcc -c moisture.c -o moisture.o

exec: mto.o avl.o abr.o create_csv.o height.o moisture.o main.o
	gcc *.o -o exec
	
clear:
	rm -f *.o
	rm exec
