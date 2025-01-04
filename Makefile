CC = gcc -g

OBJFILES = \
main.o

.PHONY: all
all: traffic_light

traffic_light: $(OBJFILES)
	$(CC) -o traffic_light $(OBJFILES)

main.o: src/main.c
	$(CC) -o main.o -c src/main.c

.PHONY: clean
clean:
	rm *.o traffic_light

.PHONY: tidy
tidy:
	rm *~ src/*~
