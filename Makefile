#Constants, can be changed by user


CC=c99
OBJECTFILES=gamewindow.o logger.o time.o resourcemanager.o maths.o
LIBS=-lSDL2 -lGLEW -lGL
FLAGS=-Wall -Wextra -fsanitize=address -g
FLAGSNS=-Wall -Wextra

#Rules for compiling


default: client

client: main.c $(OBJECTFILES)
	$(CC) main.c $(OBJECTFILES) -o TheFourthAge_Client.out $(FLAGSNS) $(LIBS)

gamewindow.o: graphics/gamewindow.c graphics/gamewindow.h
	$(CC) -c graphics/gamewindow.c -o $@

logger.o: libs/logger.c libs/logger.h
	$(CC) -c libs/logger.c -o $@

time.o: libs/time.c libs/time.h
	$(CC) -c libs/time.c -o $@

resourcemanager.o: libs/resourcemanager.c libs/resourcemanager.h
	$(CC) -c libs/resourcemanager.c -o $@

maths.o: libs/maths.c libs/maths.h
	$(CC) -c libs/maths.c -o $@

#Other Rules

clean:
	rm *.o
	rm *.out
