OBJS	= robot.o bulldozer.o roomba.o humanic.o optimusprime.o robocop.o main.o
SOURCE	= robot.cpp bulldozer.cpp roomba.cpp humanic.cpp optimusprime.cpp robocop.cpp main.cpp
HEADER	= robot.h bulldozer.h roomba.h humanic.h optimusprime.h robocop.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

robot.o: robot.cpp
	$(CC) $(FLAGS) robot.cpp -std=c++11

Bulldozer.o: bulldozer.cpp
	$(CC) $(FLAGS) bulldozer.cpp -std=c++11

Roomba.o: roomba.cpp
	$(CC) $(FLAGS) roomba.cpp -std=c++11

Humanic.o: humanic.cpp
	$(CC) $(FLAGS) humanic.cpp -std=c++11

Optimusprime.o: optimusprime.cpp
	$(CC) $(FLAGS) optimusprime.cpp -std=c++11

Robocop.o: robocop.cpp
	$(CC) $(FLAGS) robocop.cpp -std=c++11

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)
