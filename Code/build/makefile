# Variables
TIME =$(LOGPATH)$(shell date)
# Variable objetos
OBJECTS = main.o Partition.o FileHandler.o
# Flags de compilacion
CFLAGS = -c -std=c++17 -Wall

partition: $(OBJECTS)
	g++  $(OBJECTS) -o partition
	mv partition ../bin

main.o: ../src/main.cpp 
	g++ $(CFLAGS) ../src/main.cpp 

Partition.o: ../src/Partition.cpp ../include/Partition.hpp
	g++ $(CFLAGS) ../src/Partition.cpp

FileHandler.o: ../src/FileHandler.cpp ../include/FileHandler.hpp
	g++ $(CFLAGS) ../src/FileHandler.cpp


.PHONY: clean
clean:
	rm -rf ../bin/*
	rm -rf ../build/*.o


run:
	../bin/partition


git:
	git add ../.
	git commit -m "Upload $(TIME)"
	git push
