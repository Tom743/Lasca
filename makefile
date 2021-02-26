TARGET=laska
CC=g++
SRC=SourceFiles
CPPFLAGS := -Wall -IHeaderFiles
CXXFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

all: Main.o App.o GameState.o Piece.o
	$(CC) $(CPPFLAGS) App.o Main.o GameState.o Piece.o $(CXXFLAGS) -o $(TARGET)

App.o: $(SRC)/App.cpp
	$(CC) -c $(CPPFLAGS) $(SRC)/App.cpp $(CXXFLAGS)

Main.o: $(SRC)/Main.cpp
	$(CC) -c $(CPPFLAGS) $(SRC)/Main.cpp $(CXXFLAGS) 

GameState.o: $(SRC)/GameState.cpp
	$(CC) -c $(CPPFLAGS) $(SRC)/GameState.cpp $(CXXFLAGS) 
	
Piece.o: $(SRC)/Piece.cpp
	$(CC) -c $(CPPFLAGS) $(SRC)/Piece.cpp $(CXXFLAGS) 

clean:
	rm -f *.o

andlaunch: all
	./laska

