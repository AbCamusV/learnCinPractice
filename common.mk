SRC := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SRC))
DEP := $(patsubst %.c, %.d, $(SRC))
CFLAGS := -Wall -g
RM := rm -rf
CC := gcc

.PHONY: all clean depends

all: $(OUTPUT_DIR)/$(BIN)
depends: $(DEP)

$(OUTPUT_DIR):
	@mkdir -p $@

$(OUTPUT_DIR)/$(BIN): $(OBJS) | $(OUTPUT_DIR)
	@echo "Generating $@"
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(BIN) Generated Successfully"

%.o:%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

%.d:%.c
	$(CC) -MM $< > $@

clean:
	@-$(RM) $(OBJS) $(OUTPUT_DIR)/$(BIN)

include $(DEP)