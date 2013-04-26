// problem 1.2
// Implement a function void reverse(char* str) in C or C++ which reverses a null-
// terminated string.
// Filename:     reverse_string.cxx
// Author:       codelove@github
// Date:         2013-04-25

#include <iostream>
#include <string.h>

void reverse_string(char* str)
{
	int n = strlen(str);
	for ( int i = 0; i < n/2; ++i )
	{
		char c = str[i];
		str[i] = str[n-1-i];
		str[n-1-i] = c;
	}
}

int main(int argc, char* argv[])
{
  char str[] = "apple";

  std::cout << "The original string is " << str << std::endl;

  reverse_string(str);

  std::cout << "The reversed string is " << str << std::endl;
}
