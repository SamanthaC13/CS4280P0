CC=gcc
CFLAGS = -g 
SOURCES = tree.c main.c
OBJECTS = tree.o main.o
DEP = tree.h node.h
TARGET = P0
$(TARGET) : $(OBJECTS)
	$(CC) $(CFALGS)-o $@ $^
main.o :  tree.c tree.h
	$(CC) $(CFALGS) -c -o $@ $<
tree.o : main.c tree.h
	$(CC) $(CFALGS) -c -o $@ $< 
clean:
	rm -f *.o  
