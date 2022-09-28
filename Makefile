
$(p): $(p).o
	$(CC) -o $(p) $(p).o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm *.o
