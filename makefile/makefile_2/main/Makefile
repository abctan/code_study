CFILES:= $(wildcard *.c)
COBJS := $(CFILES:.c=.o)

all: $(OUTPUT)/$(COBJS)

$(OUTPUT)/%.o: %.c
	@$(CC) -c $(CFLAGS) $^ -o $@
	@echo "CC $^"