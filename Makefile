#Constants, can be changed by user

CC=c99
OBJECTFILES=gamewindow.o
LIBS=-lSDL2 -lGLEW -lGL

#Rules for compiling

default: client

client: main.c $(OBJECTFILES)
	$(CC) main.c $(OBJECTFILES) -o fourthageclient.out $(LIBS)

gamewindow.o: engine/gamewindow.c engine/gamewindow.h
	$(CC) -c engine/gamewindow.c -o $@

#Other Rules

clean:
	rm *.o
