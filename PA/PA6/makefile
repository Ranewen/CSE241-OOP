CC := g++
CFLAGS := -Wall 
BLD := ./build
SRC := ./src
STD := c++11

SRCS := $(wildcard $(SRC)/*.cpp)

pa6: $(SRCS)
	$(CC) $(CFLAGS) --std=$(STD) $^ -o $@