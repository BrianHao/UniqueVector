CC = g++
LFLAGS = -std=c++11
CFLAGS = -c -Wall

# Edit the following line when compiling
# SOURCES should include all the .cpp files to compile
SOURCES = 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE_NAME = UniqueVector

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS) 
	$(CC) -o $(EXECUTABLE_NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE_NAME)
