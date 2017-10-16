#include <vector>
#include <cstdlib>
#include <cmath>

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

// computes the product of two matrices
Matrix operator*(const Matrix& a, const Matrix& b) {
	unsigned n = a.size();
	Matrix c = id(n);
	#pragma omp parallel for
	for(unsigned i=0; i<n; ++i) {
		#pragma omp parallel for
		for(unsigned j=0; j<n; ++j) {
			c[i][j] = 0;
			for(unsigned k=0; k<n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

/**
// computes the product of two matrices
Matrix operator*(const Matrix& a, const Matrix& b) {
	unsigned n = a.size();
	Matrix c = id(n);
	
	for(unsigned i=0; i<n; ++i) {
		
		for(unsigned j=0; j<n; ++j) {
			c[i][j] = 0;
			for(unsigned k=0; k<n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

*/
/**
// computes the product of two matrices
Matrix operator*(const Matrix& a, const Matrix& b) {
	unsigned n = a.size();
	Matrix c = id(n);
	
	for(unsigned i=0; i<n; ++i) {
		
		for(unsigned j=0; j<n; ++j) {
			c[i][j] = 0;
			#pragma omp parallel
			for(unsigned volatile k=0; k<n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}
* */
// Serial Optimation 1
 /**
// computes the product of two matrices
Matrix operator*(const Matrix& a, const Matrix& b) {
	unsigned n = a.size();
	Matrix c = id(n);
	for(unsigned i=0; i<n; ++i) {
		unsigned k, j =0;
		for(; j<n-4; j+=4) {
			c[i][j] = 0;
			c[i][j+1] = 0;
			c[i][j+2] = 0;
			c[i][j+3] = 0;
			for(; k<n-4; k+=4) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j+1] += a[i][k+1] * b[k+1][j];
				c[i][j+2] += a[i][k+2] * b[k+2][j];
				c[i][j+3] += a[i][k+3] * b[k+3][j];
			}
		for(; j<n; ++j) {
			c[i][j] = 0;
			for(; k<n; ++k) 
				c[i][j] += a[i][k] * b[k][j];
			
			}
		}
	}
	return c;
}
*/
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

	// check that the result is correct
	return (c == a) ? 0 : 42;
}
