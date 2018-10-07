PROJ_NAME := PUCA

INC_DIR := inc
GEN_DIR := gen
OUT_DIR := out
DOC_DIR := doc

INST_DIR := /usr/local

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

distclean: clean
	rm -rf $(DOC_DIR)

install:
	@mkdir -p $(INST_DIR)/include/$(PROJECT_NAME)
	cp -u --target-directory=$(INST_DIR)/include/$(PROJECT_NAME) $(INC_DIR)/*.h

uninstall:
	@rm -rf $(INST_DIR)/include/$(PROJECT_NAME)
