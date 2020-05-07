CXX = g++
EXE = build/boids
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)
DEP = $(OBJ:%.o=%.d)
CPPFLAGS = -Iinclude -Wfatal-errors -Wall -MMD
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

default: $(EXE)
all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $(OBJ) $(LDLIBS)

-include $(DEP)

build/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm $(EXE) $(OBJ)

