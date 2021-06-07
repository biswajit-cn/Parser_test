all: main
main: parser.o caller.c	gcc	
	parser.o caller.c -o main
parser.o: C:\Users\Biswajit\Desktop\Parser_test\parse_mw.go
	gccgo -c C:\Users\Biswajit\Desktop\Parser_test\parse_mw.go -o parser.o -fgo-prefix=parse_test
clean: rm -f main *.o