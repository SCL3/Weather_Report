all: exec
sort.o: avl_struct.h head.h sort.c
	gcc -c sort.c -o sort.o

avl.o: avl_struct.h head.h avl.c
	gcc -c avl.c -o avl.o

exec: sort.o avl.o
	gcc *.o -o exec


/*
CC=gcc
CFLAGS=-W -h -t -p -std=c99 -g 
INC=-I include/
SRC=src/
EXEC=main
 
all: $(EXEC)
 
main: $(SRC)avl.c $(SRC)main.sh $(SRC)head.h
    $(CC) $(INC) -o $(SRC)$@ $^ $(CFLAGS) 
 
$(SRC)%.c : $(SRC)%.sh : $(SRC)%.h
    $(CC) $(INC) -o $@ -c $< $(CFLAGS) 
 
clean:
    rm -rf $(SRC)*.o

*/


CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c99 -g 
INC=-I include/
SRC=src/
EXEC=main
 
all: $(EXEC)
 
main: $(SRC)main.c $(SRC)article.o 
    $(CC) $(INC) -o $(SRC)$@ $^ $(CFLAGS) 
 
$(SRC)%.o : $(SRC)%.c
    $(CC) $(INC) -o $@ -c $< $(CFLAGS) 
 
clean:
    rm -rf $(SRC)*.o
    
