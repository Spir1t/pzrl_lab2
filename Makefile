oFiles = main.o numTypeConverter.o getType.o

test: main.o numTypeConverter.o getType.o
	gcc  $(oFiles) -o test

main.o: main.c
	gcc -c main.c

numTypeConverter.o: numTypeConverter.c
	gcc -c numTypeConverter.c

getType.o: getType.c
	gcc -c getType.c
 
run:
	./test

clean:
	rm -rf $(oFiles) test
