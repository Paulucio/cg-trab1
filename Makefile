#MAKEFILE

#Compiler
CC=g++

#Compiler flags
FLAGS=-Wall

#Libs
OPENGL_LIB=-lGL -lGLU -lglut

#Sources variables
TINYXML2_SOURCE= $(wildcard tinyxml2/*.cpp)
SOURCES= $(wildcard sources/*.cpp)

#Executable name
EXECUTABLE_NAME=a.out

all: $(TINYXML2_SOURCE:.cpp=.o) $(SOURCES:.cpp=.o)
	@echo Compiling program
	@$(CC) main.cpp $^ $(FLAGS) $(OPENGL_LIB) -o $(EXECUTABLE_NAME)
	@echo Done

%.o: %.cpp
	@echo Making object file: $@
	@$(CC) -c $< $(FLAGS) -o $@

run:
	./$(EXECUTABLE_NAME)

zip: clean
	zip -r LeonardoPaulucio.zip main.cpp tinyxml2 sources

clean:
	@echo Cleaning object files
	@rm -f $(SOURCES:.cpp=.o) $(TINYXML2_SOURCE:.cpp=.o) $(EXECUTABLE)
	@echo Done
