
CC = gcc
CFLAGS = -Isrc/ciphers

SRCS = src/scytale.c src/ciphers/ciphers.c src/ciphers/caesar.c \
       src/ciphers/polybius.c
OBJS = $(SRCS:.c=.o)


scytale: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) scytale