# compiler options
CXXFLAGS = -g -Wall -Wextra -I. -I../..
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion -Wno-deprecated-copy

#PHONY to force recompilation despite not knowing the dependencies
.PHONY: all
all: programA.exe programB.exe

programA.exe: problemA.cpp
	g++ -g -Wall -o programA.exe problemA.cpp

programB.exe: problemB.cpp bHelper.cpp bHelper.h
	g++ -g -Wall -o problemB.exe programB.cpp bHelper.cpp

.PHONY: clean
clean:                  
rm -f programA.exe programB.exe