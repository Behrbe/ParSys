#include <vector>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <atomic>

using Matrix = std::vector<std::vector<double>>;

// initializes a square identity matrix of size n x n
Matrix id(unsigned n) {
	Matrix res;
	res.resize(n);
	for(unsigned i=0; i<n; i++) {
		res[i].resize(n);
		for(unsigned j=0; j<n; j++) {
			res[i][j] = (i == j) ? 1 : 0;
		}
	}
	return res;
}
/**
// computes the product of two matrices using parallel pragma
Matrix operator*(const Matrix& a, const Matrix& b) {
	unsigned n = a.size();
	Matrix c = id(n);
	unsigned volatile k;
	for(unsigned i=0; i<n; ++i) {
		
		for(unsigned j=0; j<n; ++j) {
			c[i][j] = 0;
			#pragma omp parallel
			for(k=0; k<n; k++) {
				
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}
*/
// computes the product of two matrices using parallel pragma 
// Broke Something, failed to fix it 
Matrix operator*(const Matrix& a, const Matrix& b) {
	unsigned n = a.size();
	Matrix c = id(n);
	std::atomic<uint> k;
	unsigned int z;
	for(unsigned i=0; i<n; ++i) {
		
		for(unsigned j=0; j<n; ++j) {
			c[i][j] = 0;
			k=0;
			//printf("Hello\n" );
			#pragma omp parallel
			while(k<n) {
				z= k.fetch_add(1);
				printf(" %u\n", z);
				c[i][j] += a[i][z] * b[z][j];
				
			}
		}
	}
	return c;
}

int main(int argc, char** argv) {
	
	if(argc!=2) return EXIT_FAILURE;
	unsigned n = atoi(argv[1]);
	if(n==0) return EXIT_FAILURE;

	// create two matrices
	auto a = id(n);
	a[0][0] = 42;
	auto b = id(n);

	// compute the product
	auto c = a * b;
	for(unsigned i=0; i<n; i++){
		for(unsigned j=0; j<n; j++){
			printf(" %lf", c[i][j]);
		}
		printf("\n");	
	}
	// check that the result is correct
	return (c == a) ? 0 : 42;
}
