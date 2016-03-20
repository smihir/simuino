# Makefile for simuino on OSX

simuino: simuino.cpp
	clang -o $@ $^ -lncurses

clean:
	rm -rf *.o simuino

run: simuino
	./$^
