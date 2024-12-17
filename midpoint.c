/*
 * High Performance Computing - assignment #4
 *
 * Task: parallelize midpoint rule with OpenMPI
 *
 * Student: Farid Farajli
 *
 * Group: 604.22E
 */

#include <mpi.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

double
integrand(double x)
{
	return sin(PI * x) * sin(PI * x);
}

double
midpoint_rule(double a, double b, size_t steps)
{
	double step_size, midpoint, area = 0.0;

	step_size = (b - a) / steps;
	midpoint = a + step_size / 2.0;

	for (; steps; steps--) {
		area += integrand(midpoint) * step_size;
		midpoint += step_size;
	}

	return area;
}

int
main(int argc, char *argv[])
{
	size_t steps = 1000000, local_steps;
	double a = 0.0, b = 1.0;
	double local_a, local_b;
	double local_area, area;
	double step_size;
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	local_steps = steps / size;
	step_size = (b - a) / steps;
	local_a = a + rank * local_steps * step_size;
	local_b = local_a + local_steps * step_size;

	local_area = midpoint_rule(local_a, local_b, local_steps);

	MPI_Reduce(&local_area, &area, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	if (rank == 0)
		printf("Estimated integral: %lf\n", area);

	MPI_Finalize();
	return 0;
}
