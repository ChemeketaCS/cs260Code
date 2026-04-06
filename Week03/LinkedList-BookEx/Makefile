# force macs to use g++-15 to avoid clang mapped to g++
ifeq ($(OS),Windows_NT)
	CXX = g++
else
	OS_NAME := $(shell uname -s)
	ifeq ($(OS_NAME),Darwin)
		CXX = g++-15
	else
		CXX = g++
	endif
endif

# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++20 -fmodules-ts -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion -Wuninitialized

# search for .h files two levels up to allow for shared headers in the root directory
CXXFLAGS = -I../.. 

# list .h files here
HEADERS =

# list .cpp files here
PROGRAM_FILES = *.cpp
SHARED_FILES = 

.PHONY: all
all: program.exe

.PHONY: program.exe # Always force rebuild of program
program.exe:  $(SHARED_FILES) $(PROGRAM_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SHARED_FILES) $(PROGRAM_FILES) -o $@

.PHONY: clean
clean:
	rm -f program.exe
