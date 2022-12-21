oFiles = main.o numTypeConverter.o getType.o

run: $(oFiles)
	gcc  $(oFiles) -o test

main.o: main.c
	gcc -c main.c

numTypeConverster.o: numTypeConverter.c
	gcc -c numTypeConverter.c

getType.o: getType.c
	gcc -c getType.c
 
clean:
	rm -rf $(oFiles) test
