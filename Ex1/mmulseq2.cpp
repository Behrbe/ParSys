#include <vector>
#include <cstdlib>
#include <stdio.h>
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
// Serial Optimation 2: trying to reduce number of executed loops further. Won't work for n < 10
 
// computes the product of two matrices 
Matrix operator*(const Matrix& a, const Matrix& b) {
	unsigned n = a.size();
	Matrix c = id(n);
	for(unsigned i=0; i<n; ++i) {
		unsigned k, j;
		
		double u, v, w, x, y, z, uu, vv, ww, xx ;
		for(j=0; j<n; ++j) {
			c[i][j]=0;
			
			for( k=0 ; k<n-10; k=k+10) {
				xx= a[i][k+9] * b[k+9][j];
				ww= a[i][k+8] * b[k+8][j];
				vv= a[i][k+7] * b[k+7][j];
				uu= a[i][k+6] * b[k+6][j];
				z= a[i][k+5] * b[k+5][j];
				y= a[i][k+4] * b[k+4][j];
				u= a[i][k+3] * b[k+3][j];
				v= a[i][k+2] * b[k+2][j];
				w= a[i][k+1] * b[k+1][j];
				x= a[i][k] * b[k][j];
				c[i][j]+= u+v+w+x+y+z+uu+vv+ww+xx;
				
				}
			for(; k<n; ++k) 
				
				c[i][j] += a[i][k] * b[k][j];
			
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
	

	// check that the result is correct
	return (c == a) ? 0 : 42;
}
