OPT = -Wall -O0

all:   libfilter.c
		gcc $(OPT) -shared -o libfilter.so  -fPIC libfilter.c

clean:
		rm *.so *.o 


