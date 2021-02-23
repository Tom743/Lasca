TARGET=laska
CC=g++
SRC=SourceFiles
CPPFLAGS := -Wall -IHeaderFiles
CXXFLAGS := `wx-config --cxxflags --libs`

all: App.o MainWindow.o
	$(CC) $(CPPFLAGS) App.o MainWindow.o $(CXXFLAGS) -o $(TARGET)

App.o: $(SRC)/App.cpp
	$(CC) -c $(CPPFLAGS) $(SRC)/App.cpp $(CXXFLAGS)

MainWindow.o: $(SRC)/MainWindow.cpp
	$(CC) -c $(CPPFLAGS) $(SRC)/MainWindow.cpp $(CXXFLAGS) 

clean:
	rm -f *.o

andlaunch: all
	./laska

