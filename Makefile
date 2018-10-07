PROJ_NAME := attrs

GEN_DIR := gen

CFLAGS := -pedantic -Wall -Wextra

TEST_EXEC := test_$(PROJ_NAME)


all:
	$(CC) $(CFLAGS) test.c
	./$(TEST_EXEC)

cpp:
	@mkdir -p $(GEN_DIR)
	$(CPP) test.c -o $(GEN_DIR)/test.preprocessed.c

clean:
	rm -rf $(GEN_DIR) $(TEST_EXEC)
