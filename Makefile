PROJ_NAME := attrs

INC_DIR := inc
GEN_DIR := gen
OUT_DIR := out

DOXYFILE := Doxyfile

CFLAGS := -pedantic -Wall -Wextra
CPPFLAGS := -I$(INC_DIR)

TEST_EXEC := $(OUT_DIR)/test_$(PROJ_NAME)


all:
	@mkdir -p $(OUT_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) test.c -o$(TEST_EXEC)
	./$(TEST_EXEC)

cpp:
	@mkdir -p $(GEN_DIR)
	$(CPP) $(CPPFLAGS) test.c -o$(GEN_DIR)/test.preprocessed.c

doc:
	doxygen $(DOXYFILE)

clean:
	rm -rf $(GEN_DIR) $(OUT_DIR)
