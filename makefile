CC=gcc
CFLAGS = -g -Wall -std=c99
LDFLAGS = -lm
SOURCES = tree.c main.c
OBJECTS = $(SOURCES:.c=.o)
DEP = tree.h node.h
TARGET = P0
$(TARGET) : $(OBJECTS)
	$(CC) $(CFALGS)-o $@ $^ $(LDFLAGS) 
$(OBJECTS): $(SOURCES) $(DEP)
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)
clean:
	rm -f *.o  
