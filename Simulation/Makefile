all:
	gcc -std=gnu11 -O2 -o .main.o -c ./src/main.c -I./include/
	gcc -std=gnu11 -O2 -o .glad.o -c ./src/glad.c -I./include/
	gcc -o .main .glad.o .main.o -lGL -lglfw
	./.main
