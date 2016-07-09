###############################################################################
#	makefile taken from Alex Chadwick
#
#	A makefile script for generation of raspberry pi kernel images.
###############################################################################

ARMGNU ?= arm-none-eabi
BUILD = obj/
DEBUG = debug/
SOURCE = src/
TARGET = kernel.img
LIST = $(DEBUG)kernel.list
MAP = $(DEBUG)kernel.map
LINKER = kernel.ld

# The names of all object files that must be generated. Deduced from the 
# assembly code files in source.
OBJECTS := $(patsubst $(SOURCE)%.s,$(BUILD)%.o,$(wildcard $(SOURCE)*.s))

all: $(TARGET) $(LIST)

rebuild: all

$(LIST) : $(DEBUG)output.elf
	$(ARMGNU)-objdump -d $(DEBUG)output.elf > $(LIST)

# Image file.
$(TARGET) : $(DEBUG)output.elf
	$(ARMGNU)-objcopy $(DEBUG)output.elf -O binary $(TARGET) 

$(DEBUG)output.elf : $(DEBUG) $(OBJECTS) $(LINKER)
	$(ARMGNU)-ld --no-undefined $(OBJECTS) -Map $(MAP) -o $(DEBUG)output.elf -T $(LINKER)

# Rule to make the object files.
$(BUILD)%.o: $(SOURCE)%.s $(BUILD)
	$(ARMGNU)-as -I $(SOURCE) $< -o $@

$(BUILD):
	mkdir $@

$(DEBUG):
	mkdir $@

# Rule to clean files.
clean : 
	-rm -rf $(BUILD)
	-rm -rf $(DEBUG)
	-rm -f $(TARGET)
	-rm -f $(LIST)
	-rm -f $(MAP)
