CC=g++ 
CPPFLAGS=--std=c++11 -Wall -pedantic

all: main.cpp encode.o
	$(CC) $(CPPFLAGS) main.cpp encode.o -o encode

encode.o: encode.cpp
	$(CC) $(CPPFLAGS) -c encode.cpp

clean:
	rm -f *.o *.exe
