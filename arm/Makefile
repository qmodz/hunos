CXX = arm-none-eabi-g++
export CXX

LD = arm-none-eabi-g++
export LD

ARCH = arm
export ARCH

OUTPUT_DIR = ../output
OUTPUT = $(OUTPUT_DIR)/$(ARCH)

EXCLUDES := system

SUBDIRS := $(wildcard */)
SUBDIRS_NAMES := $(SUBDIRS:%/=%)
SUBDIRS_NAMES := $(filter-out $(EXCLUDES), $(SUBDIRS_NAMES))

all: $(SUBDIRS_NAMES)

$(SUBDIRS_NAMES):
	$(MAKE) -C $@ ARCH=$(ARCH) CXX=$(CXX) LD=$(LD)

clean:
	rm -r $(OUTPUT)

.PHONY: all clean $(SUBDIRS_NAMES)
