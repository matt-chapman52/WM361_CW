# CC = g++
# CFLAGS = -Wall -g

# # Targets needed to bring the executable up to date

# main: main.o ITS.o Employee.o
# 	$(CC) $(CFLAGS) -o main main.o ITS.o Employee.o
	
# # The main.o target
# main.o: main.cpp ITS.h Employee.h

# ITS.o: ITS.h

# Employee.o: Employee.h ITS.h

CC = g++
CFLAGS = -Wall -g

# Targets needed to bring the executable up to date

main: main.o ITS.o Employee.o HumanResources.o
	$(CC) $(CFLAGS) -o main main.o ITS.o Employee.o HumanResources.o
	
# The main.o target
main.o: main.cpp ITS.h Employee.h HumanResources.h

ITS.o: ITS.h

HumanResources.o:: HumanResources.h

Employee.o: Employee.h ITS.h HumanResources.h
