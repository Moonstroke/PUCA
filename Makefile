CFLAGS := -pedantic -Wall -Wextra

all:
	$(CC) $(CFLAGS) test.c
	./a.out

cpp:
	$(CPP) test.c -o test.preprocessed.c

clean:
	rm test.preprocessed.c a.out
