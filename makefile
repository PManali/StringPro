project: project.o mstring.o
	cc project.o mstring.o -o project
project.o: project.c mstring.h mstringfunc.h
	cc -c project.c
mstring.o: mstring.c mstring.h 
	cc -c mstring.c
clean:
	rm *.o

