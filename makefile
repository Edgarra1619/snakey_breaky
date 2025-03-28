COMPILER = clang
CCFLAGS = -Wall -Wextra -g -std=gnu99 --pedantic
OBJECTS = ./bin/game.o ./bin/main.o ./bin/render.o


all: breakout.out

breakout.out: $(OBJECTS)
	$(COMPILER) $(CCFLAGS) $(OBJECTS) -lncurses -o breakout.out

$(OBJECTS) : ./bin/%.o : ./src/%.c
	mkdir -p bin
	$(COMPILER) $(CCFLAGS) ./src/$*.c -c -o $@

clean:
	rm $(OBJECTS) snake.out -f

re: clean snake.out
