SRC := $(wildcard *.c src/*.c)
OBJS := $(patsubst %.c, %.o, $(SRC))
DEP := $(patsubst %.c, %.d, $(SRC))
CFLAGS := -Wall -Werror \
		  -Wno-error=unused-variable -Wno-error=unused-function\
 		  -g $(INC)
LDFLAGS := $(LINKER_FLAGS)
RM := rm -rf
CC := gcc

.PHONY: all clean depends

all: $(OUTPUT_DIR)/$(BIN) depends
depends: $(DEP)

$(OUTPUT_DIR):
	@mkdir -p $@

$(OUTPUT_DIR)/$(BIN): $(OBJS) | $(OUTPUT_DIR)
	@echo "Generating $@"
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "$(BIN) Generated Successfully"

%.o:%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

%.d:%.c
	@echo "make depends of $<"
	@$(CC) $(CFLAGS) -MM $< > $@

clean:
	@-$(RM) $(OBJS) $(OUTPUT_DIR)/$(BIN) $(DEP)

include $(DEP)