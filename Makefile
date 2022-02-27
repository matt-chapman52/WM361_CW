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

main: main.o ITS.o Employee.o HumanResources.o Login.o Manager.o
	$(CC) $(CFLAGS) -o main main.o ITS.o Employee.o HumanResources.o Login.o Manager.o
	
# The main.o target
main.o: main.cpp ITS.h Employee.h HumanResources.h Login.h Manager.h

ITS.o: ITS.h

HumanResources.o: HumanResources.h

Manager.o: Manager.h

Employee.o: Employee.h ITS.h HumanResources.h

Login.o: Login.h 

# Phony target (type: make clean, to delete .o and executible files)
clean: 
	rm *.o main 
