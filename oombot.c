#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE (1024*1024)

int main(int argc, char **argv) {
	const char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_-";
	const char *prefix = "Disallow: /";

	char buf[64];
	char outp_buf[BUF_SIZE];

	size_t len = strlen(chars);
	size_t prefix_len = strlen(prefix);
	size_t cnt = 0;

	setbuffer(stdout, outp_buf, BUF_SIZE);

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

	return 0;
}
