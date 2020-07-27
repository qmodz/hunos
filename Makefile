ARCHITECTURES=x86 arm
OUTPUT_DIR=./output

all: $(ARCHITECTURES)

$(ARCHITECTURES):
	$(MAKE) -C $@

clean:
	rm -r $(OUTPUT_DIR)

.PHONY: all clean $(ARCHITECTURES)
