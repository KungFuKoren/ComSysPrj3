StrList:	StrList.o main.o

StrList.o:	StrList.c StrList.h
	gcc -Wall -c StrList.c

main.o:	main.c StrList.h
	gcc -Wall -c main.c

clean:
	rm *.o StrList