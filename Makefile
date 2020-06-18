#Constants, can be changed by user

CC=c99
OBJECTFILES=gamewindow.o resourcemanager.o gamewindow.o time.o camera2d.o camera3d.o object.o projection.o model.o shader.o texture.o
LIBS=-lSDL2 -lGLEW -lGL

#Rules for compiling

default: client

client: main.c $(OBJECTFILES)
	$(CC) main.c $(OBJECTFILES) -o TheFourthAge_Client.out $(LIBS)

gamewindow.o: engine/gamewindow.c engine/gamewindow.h
	$(CC) -c engine/gamewindow.c -o $@

resourcemanager.o: libs/resourcemanager.c libs/resourcemanager.h
	$(CC) -c libs/resourcemanager.c -o $@

gamewindow.o: engine/gamewindow.c engine/gamewindow.h
	$(CC) -c engine/gamewindow.c -o $@

time.o: engine/time.c engine/time.h
	$(CC) -c engine/time.c -o $@

camera2d.o: engine/graphics/camera2d.c engine/graphics/camera2d.h
	$(CC) -c engine/graphics/camera2d.c -o $@

camera3d.o: engine/graphics/camera3d.c engine/graphics/camera3d.h
	$(CC) -c engine/graphics/camera3d.c -o $@

object.o: engine/graphics/object.c engine/graphics/object.h
	$(CC) -c engine/graphics/object.c -o $@

projection.o: engine/graphics/projection.c engine/graphics/projection.h
	$(CC) -c engine/graphics/projection.c -o $@

model.o: engine/graphics/loaders/model.c engine/graphics/loaders/model.h
	$(CC) -c engine/graphics/loaders/model.c -o $@

shader.o: engine/graphics/loaders/shader.c engine/graphics/loaders/shader.h
	$(CC) -c engine/graphics/loaders/shader.c -o $@

texture.o: engine/graphics/loaders/texture.c engine/graphics/loaders/texture.h
	$(CC) -c engine/graphics/loaders/texture.c -o $@

#Other Rules

clean:
	rm *.o
	rm *.out
