CC := gcc
OBJ_OPTS := -c
LINK_OPTS := -o

bubblesort.o: 
	${CC} ${OBJ_OPTS} bubblesort.c

selectionsort.o:
	${CC} ${OBJ_OPTS} selectionsort.c

quicksort.o:
	${CC} ${OBJ_OPTS} quicksort.c

main.o:
	${CC} ${OBJ_OPTS} main.c

bubble: main.o bubblesort.o
	${CC} main.o bubblesort.o ${LINK_OPTS} bubble.out

selection: main.o selectionsort.o
	${CC} main.o selectionsort.o ${LINK_OPTS} selection.out

quick: main.o quicksort.o
	${CC} main.o quicksort.o ${LINK_OPTS} quick.out

all: bubble selection quick

clean:
	@echo "Cleaning objects and executables!"
	@rm *.o *.out