# Variables
TIME =$(LOGPATH)$(shell date)
# Variable objetos
OBJECTS = main.o Partition.o FileHandler.o Chrono.o triplet.o 3dm.o bitNumber.o
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

Chrono.o: ../src/Chrono.cpp ../include/Chrono.hpp
	g++ $(CFLAGS) ../src/Chrono.cpp

triplet.o: ../src/triplet.cpp ../include/triplet.hpp
	g++ $(CFLAGS) ../src/triplet.cpp

3dm.o: ../src/3dm.cpp ../include/3dm.hpp
	g++ $(CFLAGS) ../src/3dm.cpp

bitNumber.o: ../src/bitNumber.cpp ../include/bitNumber.hpp
	g++ $(CFLAGS) ../src/bitNumber.cpp


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
