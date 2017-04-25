CC=gcc
CFLAGS= -lwiringPi
madmax: madmax.o 
	$(CC) -o madmax madmax.o  -lwiringPi

clean:
	rm -vf *.o
