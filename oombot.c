#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE (1024*1024)

const char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_-";

void robots_txt_inf_lines(void) {
	const char *prefix = "Disallow: /";

	char buf[64];
	size_t len = strlen(chars);
	size_t prefix_len = strlen(prefix);
	size_t cnt = 0;

	strcpy(buf, prefix);

	while (1) {
		cnt = prefix_len;

		int l = 8 + (rand() % 16);

		for (int i = 1; i < l; i++) {
		 	buf[cnt++] = chars[rand() % len];
		}

		buf[cnt] = 0;

		puts(buf);
	}
}

void ascii_garbage(void) {
	char buf[64];
	size_t len = strlen(chars);

	while (1) {
		for (int i = 0; i < 63; i++) {
			buf[i] = chars[rand() % len];
		}
		buf[63] = 0;

		printf("%s", buf);
	}
}

int main(int argc, char **argv) {
	char outp_buf[BUF_SIZE];

	setbuffer(stdout, outp_buf, BUF_SIZE);

	if (argc < 2) {
		printf("usage: %s MODE\n\n"
		       "MODE is one of robots_txt, garbage\n", argv[0]);
		exit(0);
	}

	if (strcmp(argv[1], "robots_txt") == 0) {
		robots_txt_inf_lines();
	} else if (strcmp(argv[1], "garbage") == 0) {
		ascii_garbage();
	} else {
		printf("invalid mode\n");
		exit(1);
	}

	return 0;
}
