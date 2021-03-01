
CC = gcc
CFLAGS = -Iciphers/

SRCS = src/scytale.c
OBJS = $(SRCS:.c=.o)


scytale: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) scytale