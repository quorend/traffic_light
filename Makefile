CC = gcc -g -I lib

OBJFILES = \
build/main.o \
build/targ.o \
build/traffic_light_fsm.o \
build/CuTest.o

.PHONY: all
all: build/traffic_light

build/traffic_light: build $(OBJFILES)
	$(CC) -o build/traffic_light $(OBJFILES)

.PHONY: build
build:
	mkdir -p build

build/main.o: src/main.c
	$(CC) -o build/main.o -c src/main.c

build/targ.o: src/targ.c src/targ.h
	$(CC) -o build/targ.o -c src/targ.c

build/traffic_light_fsm.o: src/traffic_light_fsm.c src/traffic_light_fsm.h
	$(CC) -o build/traffic_light_fsm.o -c src/traffic_light_fsm.c

build/CuTest.o: lib/CuTest.c lib/CuTest.h
	$(CC) -o build/CuTest.o -c lib/CuTest.c

.PHONY: clean
clean:
	rm build/*

.PHONY: tidy
tidy:
	rm *~ src/*~
