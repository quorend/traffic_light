CC = gcc -g -I lib

OBJFILES = \
main.o \
fsm.o \
targ.o \
traffic_light_fsm.o \
CuTest.o

.PHONY: all
all: traffic_light

traffic_light: $(OBJFILES)
	$(CC) -o traffic_light $(OBJFILES)

main.o: src/main.c
	$(CC) -o main.o -c src/main.c

fsm.o: src/fsm.c
	$(CC) -o fsm.o -c src/fsm.c

targ.o: src/targ.c
	$(CC) -o targ.o -c src/targ.c

traffic_light_fsm.o: src/traffic_light_fsm.c
	$(CC) -o traffic_light_fsm.o -c src/traffic_light_fsm.c

CuTest.o: lib/CuTest.c
	$(CC) -o CuTest.o -c lib/CuTest.c

.PHONY: clean
clean:
	rm *.o traffic_light

.PHONY: tidy
tidy:
	rm *~ src/*~
