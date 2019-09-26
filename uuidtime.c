#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <getopt.h>

const char *uuidtime_version = "0.1.2";

static const struct option long_options[] = {
	{"help", no_argument, NULL, 'h'},
	{"version", no_argument, NULL, 'V'},
	{NULL, 0, NULL, 0}
};
static const char *short_options = "hV";

//d94deb38-e066-11e9-9324-001b77c4af72
int main (int argc, char **argv) {
	int opt;
	while (1) {
		opt = getopt_long(argc, argv, short_options, long_options, NULL);
		if (opt == -1)
			break;
		switch (opt) {
		case 'h':
			printf("Usage: uuidtime { -h/--help | -V/--version }\n");
			exit(1);
		case 'V':
			printf("uuidtime %s\n", uuidtime_version);
			exit(1);
		}
	}

	struct timeval tv0;
	gettimeofday(&tv0, NULL);
	time_t t0 = (time_t)tv0.tv_sec;
	struct tm *tm0 = gmtime(&t0);
	char buffer[32];
	// 00000000-yyyy-mmmm-dddd-hhhhhhnnnnnn
	sprintf(buffer,"%04x%04x%02x%02x%04x%06x%06x%02x", 0,
		(int)tm0->tm_year, (int)tm0->tm_mon, (int)tm0->tm_mday, 0,
		(int)tv0.tv_sec, (int)tv0.tv_usec, rand()%255);
	
	char *c = buffer;
	unsigned int cnt = 0;
	while (1) {
		fputc(*c, stdout);
		if (cnt == 7 || cnt == 11 || cnt == 15 || cnt == 19)
			fputc('-', stdout);

		++cnt;
		++c;
		if (*c == '\0')
			break;
	}
	fputc('\n', stdout);
	fflush(stdout);

	return 0;
}

