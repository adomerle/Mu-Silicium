ARCH              = arm64
TARGET            = aarch64-linux-gnu
CROSS_COMPILE     = $(TARGET)-
CC                = $(CROSS_COMPILE)gcc
OBJCOPY           = $(CROSS_COMPILE)objcopy

all: BootShim.elf BootShim.bin BootShim.quirky.elf BootShim.quirky.bin

BootShim.bin: BootShim.elf
	$(OBJCOPY) -O binary $< $@

BootShim.elf: BootShim.S
	$(CC) -c $< -o $@ -DCREATE_FDT_POINTER=$(CREATE_FDT_POINTER) -DFDT_POINTER_ADDRESS=$(FDT_POINTER_ADDRESS) -DUEFI_BASE=$(UEFI_BASE) -DUEFI_SIZE=$(UEFI_SIZE)

BootShim.quirky.bin: BootShim.quirky.elf
	$(OBJCOPY) -O binary $< $@

BootShim.quirky.elf: BootShim.quirky.S
	$(CC) -c $< -o $@ -DUEFI_BASE=$(UEFI_BASE) -DUEFI_SIZE=$(UEFI_SIZE)

BootShim.S:

BootShim.quirky.S:
