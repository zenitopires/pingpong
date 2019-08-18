OUT = build

SEARCHPATH += src 
vpath %.c $(SEARCHPATH)
vpath %.h $(SEARCHPATH)

DEPS += structs.h common.h

_OBJS += main.o ball.o draw.o init.o input.o 

OBJS = $(patsubst %,$(OUT)/%,$(_OBJS))

all: $(PROG)

$(OUT)/%.o: %.c $(DEPS)
	@mkdir -p $(OUT)
	$(CC) -c -o $@ $<

clean:
	$(RM) -rf $(OUT) $(PROG)
