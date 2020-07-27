CXX = i686-elf-g++
export CXX

CXXFLAGS = -Wall -O2
export CXXFLAGS

LD = i686-elf-g++
export LD

LDFLAGS = -O2 -ffreestanding -nostdlib -lgcc -fno-rtti -fno-exceptions
export LDFLAGS

IMAGE_NAME = kernel.img
export IMAGE_NAME

ARCH = x86
export ARCH

INCDIRS = . ../ ../../$(ARCH)
export INCDIRS

DEPSFLAGS = -MD -MP
INCFLAGS = $(addprefix -I, $(INCDIRS))

KERNEL_BASE_DIR = ../../base/kernel
UTILS_DIR = ../../$(ARCH)/utils
KERNEL_IMAGE = $(OUTPUT)/$(IMAGE_NAME)

OUTPUT_DIR = ../../output
OUTPUT = $(OUTPUT_DIR)/$(ARCH)/kernel
OUTPUT_UTILS = $(OUTPUT_DIR)/$(ARCH)/utils

CPP_FILES := $(shell find ./ -name '*.cpp')
OBJ_FILES := $(CPP_FILES:%.cpp=%.o)
OUTPUT_OBJS := $(patsubst %, $(OUTPUT)/%, $(OBJ_FILES:./%=%))
OUTPUT_DEPS := $(OUTPUT_OBJS:%.o=%.d)

ALL_KERNEL_OUTPUT_OBJS = $(shell find $(OUTPUT) -name '*.o')
ALL_UTILS_OUTPUT_OBJS = $(shell find $(OUTPUT_UTILS) -name '*.o')
ALL_OUTPUT_OBJS = $(ALL_KERNEL_OUTPUT_OBJS) $(ALL_UTILS_OUTPUT_OBJS)

DIR_GUARD = @mkdir -p $(@D)

all: kernel

kernel: kernel_base kernel_utils kernel_arch kernel_image

kernel_base:
	$(MAKE) -C $(KERNEL_BASE_DIR) CXX=$(CXX) CXXFLAGS="$(CXXFLAGS)" ARCH=$(ARCH)

kernel_utils:
	$(MAKE) -C $(UTILS_DIR) CXX=$(CXX) CXXFLAGS="$(CXXFLAGS)" ARCH=$(ARCH)

kernel_arch: $(OUTPUT_OBJS)

kernel_image:
	$(LD) $(LDFLAGS) $(ALL_OUTPUT_OBJS) -o $(KERNEL_IMAGE)

$(OUTPUT)/%.o: %.cpp
	$(DIR_GUARD)
	$(CXX) $(CXXFLAGS) $(DEPSFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	rm -r $(OUTPUT)

.PHONY: all clean kernel kernel_base kernel_utils kernel_arch kernel_image

-include $(OUTPUT_DEPS)
