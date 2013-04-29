// problem 1.7
// Write an algorithm such that if an element in an MxN matrix is 0, its entire row
// and column are set to 0.
// 
// Filename:     set_matrix_zero_row_and_column.cxx
// Author:       codelove@github
// Date:         2013-04-28

#include <iostream>
#include <vector>

template <class T>
void set_zero (T **a, int m, int n)
{
	std::vector<bool> rows(m, false);
	std::vector<bool> cols(n, false);

	for ( int i = 0; i < m; ++i )
		for ( int j = 0; j < m; ++j )
		{
			if ( a[i][j] == 0 )
			{
				if ( !rows[i] )
					rows[i] = true;

				if ( !cols[i] )
					cols[i] = true;
			}
		}
		
	for ( int i = 0; i < m; ++i )
		for ( int j = 0; j < n; ++j )
		{
			if ( rows[i] || cols[j] )
				a[i][j] = 0;
		}
}

bool test()
{
	bool passed = true;
	int m = 2;
	int n = 3;

	int p[] = {0, 1 , 2, 3, 4, 5};

	int** a = new int*[m];

	for ( int i = 0; i < m; ++i )
		a[i] = p + i * n;

    set_zero(a, m, n);

	for ( int i = 0; i < m && passed; ++i )
		for ( int j = 0; j < n && passed; ++j )
		{
			if ( i==0 || j==0 )
				passed = (a[i][j] == 0);
			else
				passed = !(a[i][j] == 0);
		}

	return passed;
}

int main(int argc, char* argv[])
{
	if ( test() )
		std::cout << "test passed\n";
	else
		std::cout << "test failed\n";

	return 0;
}

