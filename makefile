CC=gcc
CFLAGS = -I
DEPS = node.h
OBJ = main.o tree.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
node : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm -f *.o  
