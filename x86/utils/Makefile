CXX = i686-elf-g++
export CXX

CXXFLAGS = -Wall -O2
export CXXFLAGS

LD = i686-elf-g++
export LD

LDFLAGS = -O2 -ffreestanding -nostdlib -lgcc -fno-rtti -fno-exceptions
export LDFLAGS

ARCH = x86
export ARCH

INCDIRS = . ../ ../../$(ARCH)
export INCDIRS

DEPSFLAGS = -MD -MP
INCFLAGS = $(addprefix -I, $(INCDIRS))

UTILS_BASE_DIR = ../../base/utils

OUTPUT_DIR = ../../output
OUTPUT = $(OUTPUT_DIR)/$(ARCH)/utils

CPP_FILES := $(shell find ./ -name '*.cpp')
OBJ_FILES := $(CPP_FILES:%.cpp=%.o)
OUTPUT_OBJS := $(patsubst %, $(OUTPUT)/%, $(OBJ_FILES:./%=%))
OUTPUT_DEPS := $(OUTPUT_OBJS:%.o=%.d)
ALL_OUTPUT_OBJS = $(shell find $(OUTPUT) -name '*.o')

DIR_GUARD = @mkdir -p $(@D)

all: utils

utils: utils_base utils_arch

utils_base:
	$(MAKE) -C $(UTILS_BASE_DIR) CXX=$(CXX) CXXFLAGS="$(CXXFLAGS)" ARCH=$(ARCH)

utils_arch: $(OUTPUT_OBJS)

$(OUTPUT)/%.o: %.cpp
	$(DIR_GUARD)
	$(CXX) $(CXXFLAGS) $(DEPSFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	rm -r $(OUTPUT)

.PHONY: all clean utils utils_base utils_arch

-include $(OUTPUT_DEPS)
