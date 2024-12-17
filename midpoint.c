/*
 * High Performance Computing - assignment #4
 *
 * Task: parallelize midpoint rule with OpenMPI
 *
 * Student: Farid Farajli
 *
 * Group: 604.22E
 */

#include <math.h>
#include <stdio.h>
#include <time.h>

#define PI 3.14159265358979323846
#define FILE_NAME "data.txt"
#define MIDPOINT(a, b) ((a + b) / 2)

double
integrand(double x)
{
	return sin(PI * x) * sin(PI * x);
}

double
midpoint_rule(double a, double b, size_t steps)
{
	double step_size, midpoint, area = 0;

	step_size = (b - a) / steps;
	midpoint = a + step_size / 2;

	for (; steps; steps--) {
		area += integrand(midpoint) * step_size;
		midpoint += step_size;
	}

	return area;
}

int
main(void)
{
	FILE *file = fopen(FILE_NAME, "w");

	if (file == NULL) {
		printf("Can't open file: '%s'\n", FILE_NAME);
		return 1;
	}

	printf("Midpoint rule gives us: %lf\n", midpoint_rule(0.0, 1.0, 100));

	for (size_t i = 1; i != 41; i++) {
		long steps;
		clock_t start, end;
		double elapsed_time;

		steps = i * 10000000;
		start = clock();
		midpoint_rule(0.0, 1.0, steps);
		end = clock();
		elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

		fprintf(file, "%zu %lf\n", steps, elapsed_time);
	}
	return 0;
}
