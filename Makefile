CFLAGS := -pedantic -Wall -Wextra

all:
	$(CC) $(CFLAGS) test.c
	./a.out

clean:
	rm a.out
