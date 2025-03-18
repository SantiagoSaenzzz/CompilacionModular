GCC = gcc
CFLAGS = -Wall -Wextra -std=c11
EXEC = matrizm

all: $(EXEC)

$(EXEC): matrizm.o modulo.o
	$(GCC) $(CFLAGS) -o $(EXEC) matrizm.o modulo.o

matrizm.o: matrizm.c modulo.h
	$(GCC) $(CFLAGS) -c matrizm.c

modulo.o: modulo.c modulo.h
	$(GCC) $(CFLAGS) -c modulo.c

clean:
	rm -f $(EXEC) *.o

