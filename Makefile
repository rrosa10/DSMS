# Compiler
CC = g++  # Change this to 'gcc' if you're using C

# Target executable name
TARGET = my_program  # Change this to your desired executable name

# Source files
SRCS = main.cpp Spider.cpp  # List all your source files here

# Header files (optional)
HEADERS = Spider.h  # List your header files here if needed

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)  # The default target to build

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^  # Compile and link

# Compile source files into object files
%.o: %.cpp
	$(CC) -c $<

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)  # Remove object files and the executable

# Run the program
run: $(TARGET)
	./$(TARGET)  # Execute the program
