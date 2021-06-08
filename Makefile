all: main

main: parser.o caller.c	gcc	
	parser.o caller.c -o main
	
parser.o: parse_mw.go
	gccgo -c parse_mw.go -o parser.o -fgo-prefix=parse_test
clean: rm -f main *.o