# Makefile for simuino on OSX

simuino: simuino.c
	g++ -o simino simuino.c -lncurses

clean:
	rm -rf *.o simuino
