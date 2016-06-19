CC=g++

simuino: simuino.cpp
	$(CC) -o $@ $^ -lncurses

clean:
	rm -rf *.o simuino

run: simuino
	./$^
