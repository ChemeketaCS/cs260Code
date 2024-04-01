# compiler options
CXXFLAGS = -g -Wall -Wextra -I. -I../..
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion -Wno-deprecated-copy

PROGRAM_FILES = *.cpp

.PHONY: all
all: program.exe

#PHONY to force recompilation despite not knowing the dependencies
.PHONY: program.exe
program.exe: 
	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) -o $@

.PHONY: clean
clean:
	-rm -f program.exe   