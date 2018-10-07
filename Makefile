PROJ_NAME := attrs

INC_DIR := inc
GEN_DIR := gen

CFLAGS := -pedantic -Wall -Wextra
CPPFLAGS := -I$(INC_DIR)

TEST_EXEC := test_$(PROJ_NAME)


all:
	$(CC) $(CPPFLAGS) $(CFLAGS) test.c -o$(TEST_EXEC)
	./$(TEST_EXEC)

cpp:
	@mkdir -p $(GEN_DIR)
	$(CPP) $(CPPFLAGS) test.c -o$(GEN_DIR)/test.preprocessed.c

clean:
	rm -rf $(GEN_DIR) $(TEST_EXEC)
