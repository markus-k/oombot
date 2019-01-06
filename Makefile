CC := gcc

CFLAGS = -O3

all: oombot

oombot: oombot.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f oombot
