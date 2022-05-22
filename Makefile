include config.mk

SUB_DIRS := $(wildcard $(SRC_DIR)/*)

.PHONY: all clean depends

all:
	@for subdir in $(SUB_DIRS); do \
		make -C $$subdir || exit 1; \
	done

clean:
	@for subdir in $(SUB_DIRS); do \
		make -C $$subdir clean; \
	done

depends:
	@for subdir in $(SUB_DIRS); do \
		make -C $$subdir depends; \
	done