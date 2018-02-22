# no need to change anything (if you want a different .exe change name under EXECUTABLE)
# for make tar to work make file must be in src directory
# final output after make neat
# assignment#
# 	src
# 		readme.txt
# 		Makefile
# 		*.cpp
# 	include
# 		*.h
# make- normal compile and execution
# make allS- allows for normal compile without immediate execution, hack for my batch file and sublime
# make clean- remove .o and .exe
# make neat- put cpp and h files into appropriate folders
# make neattar- put cpp and h files into appropriate folders and tar folder
# make tar- tar folder

CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES := $(wildcard *.cpp)
OBJECTS := $(addprefix ,$(notdir $(SOURCES:.cpp=.o)))
EXECUTABLE=main
ASSIGNMENT= $(notdir $(shell cd .. && pwd))
INCLUDES= -I ../include

all: $(SOURCES) $(EXECUTABLE)
	./$(EXECUTABLE)

allS: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(INCLUDES) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o
	$(RM) *.exe

neat:
	make clean
	-mkdir src
	-mkdir include
	-mv *.txt src
	mv *.cpp src
	mv Makefile src
	-mv *.h include

neattar:
	make clean
	-mkdir src
	-mkdir include
	-mv *.txt src
	mv *.cpp src
	mv Makefile src
	-mv *.h include
	cd src && make tar

tar:
	cd .. && cd .. && tar cvzf $(ASSIGNMENT).tgz $(ASSIGNMENT)


	
	