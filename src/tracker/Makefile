# help from https://stackoverflow.com/questions/43225401/how-to-compile-a-c-project-with-multiple-directories-using-makefiles

CC = g++
CFLAGS = -Ofast -std=c++11
TARGET = main

SRC_DIR := ./src
DEPS := ./include
ODIR := ./build
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(ODIR)/%.o,$(SRC_FILES))

# Compile dependencies
$(ODIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)/%.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(TARGET).cpp -o $@ $^


all: clean $(OBJS)

clean:
	$(RM) $(ODIR)/*
