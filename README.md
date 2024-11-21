gcc -c My_library/Node.c -o lib/Node.o

gcc -c My_library/LinkedList.c -o lib/LinkedList.o

ar rcs lib/libMyLibrary.a lib/LinkedList.o lib/Node.o

gcc test.c -Llib -lMyLibrary -o test

./test
