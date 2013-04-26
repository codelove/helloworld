// problem 1.4
// Write a method to replace all spaces in a string with'%20'. You may assume that
// the string has sufficient space at the end of the string to hold the additional
// characters, and that you are given the "true" length of the string. (Note: if imple-
// menting in Java, please use a character array so that you can perform this opera-
// tion in place.)
// 
// Filename:     replace_space.cxx
// Author:       codelove@github
// Date:         2013-04-26

#include <iostream>

// return false if there isn't enough space for in place replace
bool replace_space(char* str, int n)
{
	int str_len = 0;

	int space_count = 0;

	char* str_cp = str;

	while ( str_len < n && *str_cp != '\0' ) 
	{
	  if ( *str_cp ==' ' )
		space_count++;

	  str_len++;

	  str_cp++;
	}

	int new_str_len = str_len + 2 * space_count;

	// not enough space to replace the spaces
	if ( new_str_len > n + 1 )
	  return false;
    
	str[new_str_len] = '\0';

	for ( int i = str_len - 1; i >= 0 && space_count > 0; --i )
	{
	  if ( str[i] == ' ' )
	  {
	    space_count--;

		str[--new_str_len] = '0';
		str[--new_str_len] = '2';
		str[--new_str_len] = '%';
	  }
	  else
		str[--new_str_len] = str[i];
	}

	return true;
}

using namespace std;

int main(int argc, char* argv[])
{
	char name[20] = "hello world";

	cout << name << endl;

	replace_space(name, 20);

	cout << name << endl;

	char name2[35] = "hello world, welcome my friend.";

	cout << name2 << endl;

	replace_space(name2, 35);

	cout << name2 << endl;

	char name3[50] = "hello world, welcome my friend.";

	cout << name3 << endl;

	replace_space(name3, 50);

	cout << name3 << endl;

	return 0;
}
