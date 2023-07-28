#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <chrono>

#define N 1500
#define RUNS 1
double A[N][N], B[N][N], C[N][N], D[N][N];


int main(int argc, char* argv[])
{
	// read into matrix D
	//FILE* input;
	//errno_t OK = fopen_s(&input, "log.bin", "rb");
	//assert(OK == 0);
	//fread(D, sizeof(int), N * N, input);
	//fclose(input);

	srand(42);

	//populate A and B arrays
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			A[i][j] = rand();
			B[i][j] = rand();
		}



	for (int x = 0; x < RUNS; x++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				C[i][j] = 0;
				//double total = 0;
				for (int k = 0; k < N; k++)
					C[i][j] += A[i][k] * B[k][j];
					//total += A[i][k] * B[k][j];
				//C[i][j] = total;
			}

		auto end_time = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> duration = end_time - start_time;
		printf("%f seconds\n", duration.count());
	}
	// Check old data
	/*for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			assert(C[i][j] == D[i][j]);*/


			//FILE* output;
			//errno_t OK = fopen_s(&output, "log.bin", "wb");
			//assert(OK == 0);
			//fwrite(C, sizeof(int), N * N, output);
			//fclose(output);


	//printf("Done!\n");

	return 0;
}