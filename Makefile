#Constants, can be changed by user


CC=c99
LIBS=-lSDL2 -lGLEW -lGL -lm
EVENTOBJ=eventmanager.o
GRAPHICOBJ=camera2d.o camera3d.o gamewindow.o object.o projection.o
LIBOBJ=logger.o maths.o resourcemanager.o time.o
LOADEROBJ=model.o shader.o texture.o
FLAGS=-Wall -Wextra -fsanitize=address -g
FLAGSNS=-Wall -Wextra

#Rules for compiling


default: client

client: main.c $(EVENTOBJ) $(GRAPHICOBJ) $(LIBOBJ) $(LOADEROBJ)
	$(CC) main.c $(EVENTOBJ) $(GRAPHICOBJ) $(LIBOBJ) $(LOADEROBJ) -o TheFourthAge_Client.out $(FLAGSNS) $(LIBS)

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

model.o: loaders/model.c loaders/model.h
	$(CC) -c loaders/model.c -o $@

shader.o: loaders/shader.c loaders/shader.h
	$(CC) -c loaders/shader.c -o $@

texture.o: loaders/texture.c loaders/texture.h
	$(CC) -c loaders/texture.c -o $@

object.o: graphics/object.c graphics/object.h
	$(CC) -c graphics/object.c -o $@

camera3d.o: graphics/camera3d.h graphics/camera3d.c
	$(CC) -c graphics/camera3d.c -o $@

camera2d.o: graphics/camera2d.h graphics/camera2d.c
	$(CC) -c graphics/camera2d.c -o $@

projection.o: graphics/projection.h graphics/projection.c
	$(CC) -c graphics/projection.c -o $@

eventmanager.o: events/eventmanager.h events/eventmanager.c
	$(CC) -c events/eventmanager.c -o $@

#Other Rules

clean:
	rm *.o
	rm *.out
