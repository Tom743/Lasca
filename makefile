CC := g++
TARGET := Lasca

SRC_DIR := src
OBJ_DIR := obj
INLCUDE_DIR := include
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
# TODO make with debug flags only on debugging
CPPFLAGS := -g -Wall -I$(INLCUDE_DIR)
CXXFLAGS := -g -lsfml-graphics -lsfml-window -lsfml-system

$(TARGET): $(OBJ_FILES)
	$(CC) $(CPPFLAGS) -o $@ $^ $(CXXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $< $(CXXFLAGS) 

clean:
	rm -fv $(OBJ_FILES) $(TARGET)
