GXX=g++
GXXFLAGS=-Wall -g

rbnode: rbnode.h rbnode.cpp
	$(GXX) $(GXXFLAGS) rbnode.cpp -c
	
redblacktree: redblacktree.h redblacktree.cpp
	$(GXX) $(GXXFLAGS) redblacktree.cpp -c
	