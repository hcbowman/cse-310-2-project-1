CC=g++ 
CPPFLAGS=--std=c++11 -Wall -pedantic

all: encode decode

encode: main.cpp encode.o
	$(CC) $(CPPFLAGS) main.cpp encode.o -o encode

encode.o: encode.cpp
	$(CC) $(CPPFLAGS) -c encode.cpp

decode: main.cpp decode.o
	$(CC) $(CPPFLAGS) main.cpp decode.o -D DECRYPT -o decode

decode.o: decode.cpp
	$(CC) $(CPPFLAGS) -c decode.cpp

clean:
	rm -f *.o *.exe *.out encode decode