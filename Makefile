CC=gcc
CFLAGS=-I./headers -I./sources -Wall -g

DEPS = headers/rules.h headers/knowledge_base.h
OBJ = sources/main.o sources/rules.o sources/knowledge_base.o

%.o: %.c $(DEPS)
    $(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
    $(CC) -o $@ $^ $(CFLAGS)

clean:
    rm -f sources/*.o main
