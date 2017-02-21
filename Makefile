CFLAGS = -g -Wall

PA5: main.o rational.o
	g++ $(CFLAGS) main.o rational.o -lm -o PA5

main.o: main.h main.cpp
	g++ $(CFLAGS) -c main.cpp

rational.o: rational.h rational.cpp
	g++ $(CFLAGS) -c rational.cpp

clean:
	rm -f main.o rational.o PA5
	
all: PA5