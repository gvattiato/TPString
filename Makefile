
all: main

main: 	main.o String.o
	g++ -Wall main.o String.o -o main -g

main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o -g

String.o: String.h String.cpp
	  g++ -Wall -c String.cpp -o String.o -g

clean:
	rm *.o

mrproper: clean
	rm main
