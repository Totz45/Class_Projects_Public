# Define the compiler, assembler, linker, and flags
CC = aarch64-linux-gnu-gcc
LD = aarch64-linux-gnu-ld
CFLAGS = -g -pedantic -Wall -Wextra -fPIC -std=gnu2x -MMD
ASFLAGS = -g -MMD
LDFLAGS = -g -N -Ttext=0x10000

# Define the source files and object files
C_SRCS = queue.c process.c kernel.c 
ASM_SRCS = boot.S box.S process_asm.S timer_asm.S
C_OBJS = $(C_SRCS:.c=.o)
ASM_OBJS = $(ASM_SRCS:.S=.o)
OBJS = $(C_OBJS) $(ASM_OBJS)

# Define the executable name
EXEC = kernel.elf

# Default target to build the executable
all: $(EXEC)

# Rule to compile C source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to assemble ARMv8 assembly files into object files
%.o: %.S
	$(CC) $(ASFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(EXEC): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ libos.a

# Clean target to remove object files and executables
clean:
	rm *.o *.d *.elf

# Run target to execute the kernel using QEMU
run: $(EXEC)
	qemu-system-aarch64 -machine raspi3b -kernel $(EXEC)
	
debug:
	qemu-system-aarch64 -machine raspi3b  -S -s -kernel kernel.elf &
	ddd --debugger 'gdb-multiarch -ex "target remote localhost:1234" -ex "break main" -ex "continue"' kernel.elf

# Phony targets
.PHONY: all clean run debug
