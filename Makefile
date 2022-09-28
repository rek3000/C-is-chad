
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(proj):
	$(CC) -o $(proj) *.o

clean:
	rm *.o
