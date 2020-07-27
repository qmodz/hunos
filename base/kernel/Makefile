CXX = g++
export CXX

CXXFLAGS = -Wall -O2
export CXXFLAGS

ARCH = x86
export ARCH

INCDIRS = . ../ ../../$(ARCH)
export INCDIRS

DEPSFLAGS = -MD -MP
INCFLAGS = $(addprefix -I, $(INCDIRS))

OUTPUT_DIR = ../../output
OUTPUT = $(OUTPUT_DIR)/$(ARCH)/kernel

CPP_FILES := $(shell find ./ -name '*.cpp')
OBJ_FILES := $(CPP_FILES:%.cpp=%.o)
OUTPUT_OBJS := $(patsubst %, $(OUTPUT)/%, $(OBJ_FILES:./%=%))
OUTPUT_DEPS := $(OUTPUT_OBJS:%.o=%.d)

DIR_GUARD = @mkdir -p $(@D)

all: kernel

kernel: $(OUTPUT_OBJS)

$(OUTPUT)/%.o: %.cpp
	$(DIR_GUARD)
	$(CXX) $(CXXFLAGS) $(DEPSFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	rm -r $(OUTPUT)

.PHONY: all clean kernel

-include $(OUTPUT_DEPS)
