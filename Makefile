CFLAGS := -std=c99 -g -static
CC := gcc
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c = .o)

main: $(OBJS)
		$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): main.h const.h

clean:
	$(RM) main
