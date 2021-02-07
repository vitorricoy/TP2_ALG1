CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -Wno-unused-parameter
EXEC=tp2

$(EXEC): src/main.cpp valor_aresta.o union_find.o
	$(CC) $(CFLAGS) src/main.cpp valor_aresta.o union_find.o -o $(EXEC)

valor_aresta.o: src/headers/valor_aresta.cpp
	$(CC) $(CFLAGS) -c src/headers/valor_aresta.cpp -o valor_aresta.o

union_find.o: src/headers/union_find.cpp
	$(CC) $(CFLAGS) -c src/headers/union_find.cpp -o union_find.o

clean:
	rm -rf *.o