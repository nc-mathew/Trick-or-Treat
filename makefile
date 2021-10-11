#Nancy Mathew, ID: 1000873667
#makefile for C++ program, Code6 - trickortreating/multithreading with candy and toothbrush houses
SRC1 = Code6_1000873667.cpp
SRC2 = TrickOrTreater.cpp
SRC3 = House.cpp
SRC4 = CandyHouse.cpp
SRC5 = ToothbrushHouse.cpp
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
OBJ4 = $(SRC4:.cpp=.o)
OBJ5 = $(SRC5:.cpp=.o)
EXE = $(SRC1:.cpp=.e)

CFLAGS = -g -std=c++11 -pthread

all : $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) -o $(EXE)

$(OBJ1) : $(SRC1)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1)

$(OBJ2) : $(SRC2)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2)

$(OBJ3) : $(SRC3)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3)

$(OBJ4) : $(SRC4)
	g++ -c $(CFLAGS) $(SRC4) -o $(OBJ4)

$(OBJ5) : $(SRC5)
	g++ -c $(CFLAGS) $(SRC5) -o $(OBJ5)
