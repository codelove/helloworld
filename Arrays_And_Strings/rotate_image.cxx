// problem 1.5
// Given an image represented by an NxN matrix, where each pixel in the image is
// 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
// place?
// 
// Filename:     rotate_image.cxx
// Author:       codelove@github
// Date:         2013-04-27

#include <iostream>
#include <cmath>

// 2d rotation ( counter clockwise theata )
// cos(theta) -sin(theta)
// sin(theta) cos(theta)
// in 2D matrix rotation (from center)
// (x,y) --> (n-1-y,x)

template<class T>
void rotate_square_matrix(T *a, int n)
{
	int half_row = n / 2;
	int half_col = n / 2;

	if ( n % 2 )
		half_row++;

	for ( int i = 0; i < half_row; ++i )
		for ( int j = 0; j < half_col; ++j )
	  {
		  int i1 = i; 
		  int j1 = j;
		  int i2 = n - 1 - j1;
		  int j2 = i1;
		  int i3 = n - 1 - j2;
		  int j3 = i2;
		  int i4 = n - 1 - j3;
		  int j4 = i3;

		  T tmp = a[i1 * n + j1];
		  a[i1 * n + j1 ] = a[i2 * n + j2];
		  a[i2 * n + j2 ] = a[i3 * n + j3];
		  a[i3 * n + j3 ] = a[i4 * n + j4];
		  a[i4 * n + j4 ] = tmp;
	  }
}

template<class T>
void print_square_matrix(T *a, int n)
{
	for ( int i = 0; i < n; ++i )
	{
		for ( int j = 0; j < n; ++j )
			std::cout << a[i * n + j] << " ";

		std::cout << std::endl;
	}
}

int main(int argc, char* argv[])
{
	using namespace std;

	int a[] = {0, 1, 2, 3};
	int n2 = sizeof(a) / sizeof(a[0]);
	int n = sqrt(n2);

	if ( n*n != n2 )
	{
		cout << "The matrix is not a square one\n";
		return -1;
	}
	
	cout << "before rotation\n";
	print_square_matrix(a, n);

	rotate_square_matrix(a, n);

	cout << "after rotation\n";
	print_square_matrix(a, n);

	double b[] = {1.0, 2.3, 3.1, 4.2, 5.4, 6.7, 7.2, 8.9, 9.1, 10.9, 11.4, 12.6, 13.5, 14.2, 15.7, 16.2};
	int m2 = sizeof(b) / sizeof(b[0]);
	int m = sqrt(m2);

	if ( m*m != m2 )
	{
		cout << "The matrix is not a square one\n";
		return -1;
	}
	
	cout << "before rotation\n";
	print_square_matrix(b, m);

	rotate_square_matrix(b, m);

	cout << "after rotation\n";
	print_square_matrix(b, m);

	int c[25];
	for (int i = 0; i < 25; ++i)
		c[i] = i;

	m = 5;
	
	cout << "before rotation\n";
	print_square_matrix(c, m);

	rotate_square_matrix(c, m);

	cout << "after rotation\n";
	print_square_matrix(c, m);
}
