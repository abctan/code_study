CFILES:= $(wildcard *.c)
COBJS := $(CFILES:.c=.o)
OBJS  := $(addprefix $(OUTPUT)/, $(COBJS))

all: $(OBJS)

$(OUTPUT)/%.o: %.c
	@$(CC) -c $(CFLAGS) $^ -o $@
	@echo "CC $^"