PROJ_NAME := attrs

CFLAGS := -pedantic -Wall -Wextra

TEST_EXEC := test_$(PROJ_NAME)


all:
	$(CC) $(CFLAGS) test.c
	./$(TEST_EXEC)

cpp:
	$(CPP) test.c -o test.preprocessed.c

clean:
	rm test.preprocessed.c $(TEST_EXEC)
