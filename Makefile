CXX = g++
CXXFLAGS = -Wall -g -std=c++14 -Ofast -ffast-math -mtune=native -Wpedantic \
		   -Wconversion -Wextra -Weffc++ -funroll-loops -flto

EXE = sparkle

SRC = main.cpp logic.cpp
OBJ = $(SRC:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXE)
