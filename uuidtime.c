#include <stdio.h>
#include <time.h>
#include <sys/time.h>

//d94deb38-e066-11e9-9324-001b77c4af72
int main (int argc, char **argv) {
	struct timeval tv0;
	gettimeofday(&tv0, NULL);
	time_t t0 = (time_t)tv0.tv_sec;
	struct tm *tm0 = gmtime(&t0);
	// 00000000-yyyy-mmmm-dddd-hhhhhhnnnnnn
	printf("%08x-%04x-%04x-%04x-%06x%06x\n", 0,
		(int)tm0->tm_year, (int)tm0->tm_mon, (int)tm0->tm_mday,
		(int)tv0.tv_sec, (int)tv0.tv_usec);

	return 0;
}

