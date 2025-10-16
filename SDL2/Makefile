all:
	gcc -std=gnu17 -O2 -Wall -o ./build/sdl2.o -c ./src/sdl2.c -I./include
	gcc -std=gnu17 -O2 -Wall -o ./build/engine.o -c ./src/engine.c -I./include

	gcc -std=gnu17 -O2 -Wall -o ./build/basicEnemyHandler.o -c ./src/GameObject/basicEnemyHandler.c -I./include
	gcc -std=gnu17 -O2 -Wall -o ./build/basicEnemy.o -c ./src/GameObject/basicEnemy.c -I./include

	gcc -o ./build/main ./build/sdl2.o ./build/engine.o ./build/basicEnemyHandler.o ./build/basicEnemy.o -lm -lSDL2

	./build/main

dbg:
	gcc -std=gnu17 -O0 -ggdb3 -Wall -o ./build/sdl2.o -c ./src/sdl2.c -I./include
	gcc -std=gnu17 -O0 -ggdb3 -Wall -o ./build/engine.o -c ./src/engine.c -I./include

	gcc -std=gnu17 -O0 -ggdb3 -Wall -o ./build/basicEnemyHandler.o -c ./src/GameObject/basicEnemyHandler.c -I./include
	gcc -std=gnu17 -O0 -ggdb3 -Wall -o ./build/basicEnemy.o -c ./src/GameObject/basicEnemy.c -I./include

	gcc -o ./build/main ./build/sdl2.o ./build/engine.o ./build/basicEnemyHandler.o ./build/basicEnemy.o -lm -lSDL2

	./build/main

cls:
	rm ./build/*.o

