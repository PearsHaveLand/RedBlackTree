GXX=g++
GXXFLAGS=-Wall -g

pow.o: pow.h pow.cpp
	$(GXX) $(GXXFLAGS) pow.cpp -c

rbnode.o: rbnode.h rbnode.cpp
	$(GXX) $(GXXFLAGS) rbnode.cpp -c

redblacktree.o: redblacktree.h redblacktree.cpp pow.o rbnode.o
	$(GXX) $(GXXFLAGS) redblacktree.cpp -c

run1: test1.cpp redblacktree.o rbnode.o pow.o
	$(GXX) $(GXXFLAGS) rbnode.o pow.o redblacktree.o test1.cpp -o run1

clean:
	rm *.o run*

	I am stinky