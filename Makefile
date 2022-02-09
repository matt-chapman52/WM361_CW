CC = g++
CFLAGS = -Wall -g

# Targets needed to bring the executable up to date
main: main.o ITS.o Employee.o
	$(CC) $(CFLAGS) -o main main.o ITS.o Employee.o

main.o: main.cpp ITS.h Employee.h

ITS.o: ITS.h

Employee.o: Employee.h ITS.h
