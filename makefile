try: program.o mstring.o
	cc program.o mstring.o -o try
program.o: program.c mstring.h
	cc -c program.c
mstring.o: mstring.c mstring.h 
	cc -c mstring.c
clean:
	rm *.o

