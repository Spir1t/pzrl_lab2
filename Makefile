oFiles = main.o numTypeConverter.o getType.o

compile: 1 2 3
	gcc  $(oFiles) -o test

1: main.c
	gcc -c main.c

2: numTypeConverter.c
	gcc -c numTypeConverter.c

3: getType.c
	gcc -c getType.c
 
run: compile
	./test

clean:
	rm -rf $(oFiles) test
