CC = g++
CCFLAGS = -g 
CCLIBS = -lncurses
mygame: main.o Gui.o Game.o Item.o Animal.o Predator.o Grass.o Rabbit.o Wolf.o Tiger.o
	$(CC) $(CCFLAGS) -o mygame main.o Gui.o Game.o Item.o Animal.o Predator.o Grass.o Rabbit.o Wolf.o Tiger.o $(CCLIBS)

Gui.o: Gui.h Gui.C
	$(CC) $(CCFLAGS) -c -o Gui.o Gui.C

Game.o: Game.h Game.C
	$(CC) $(CCFLAGS) -c -o Game.o Game.C

main.o: main.C
	$(CC) $(CCFLAGS) -c -o main.o main.C

Item.o: Item.C Item.h
	$(CC) $(CCFLAGS) -c -o Item.o Item.C

Animal.o: Animal.h Animal.C
	$(CC) $(CCFLAGS) -c -o Animal.o Animal.C

Predator.o: Predator.h Predator.C
	$(CC) $(CCFLAGS) -c -o Predator.o Predator.C

Grass.o: Grass.h Grass.C
	$(CC) $(CCFLAGS) -c -o Grass.o Grass.C

Rabbit.o: Rabbit.h Rabbit.C
	$(CC) $(CCFLAGS) -c -o Rabbit.o Rabbit.C

Wolf.o: Wolf.h Wolf.C
	$(CC) $(CCFLAGS) -c -o Wolf.o Wolf.C

Tiger.o: Tiger.h Tiger.C
	$(CC) $(CCFLAGS) -c -o Tiger.o Tiger.C

clean:
	rm -rf mygame *.o
