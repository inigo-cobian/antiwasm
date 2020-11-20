SRC=$(wildcard src/*.cpp)
GCC_FLAGS=-std=c++17

antiwasm:
	g++ $(SRC) $(GCC_FLAGS) -o $@

clean:
	rm antiwasm
