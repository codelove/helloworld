#include <iostream>
#include <vector>
#include <string>

using namespace std;

// check whether a string only has unique characters
bool unique_characters_in_string_check(string str)
{
	vector<bool> presented_flags(256, false);

	for ( string::iterator iter = str.begin(); iter != str.end(); ++iter )
	{
		int idx = *iter;

		if ( presented_flags[idx] )
			return false;

		presented_flags[idx] = true;

	}

	return true;
}

int main(int argc, char * argv[])
{
	string str1 = "hello world";

	if ( unique_characters_in_string_check(str1) )
		cout << str1 + " is a string with only unique characters" << endl;
	else
		cout << str1 + " is a string with duplicated characters" << endl;

	string str2 = "code runs";

	if ( unique_characters_in_string_check(str2) )
		cout << str2 + " is a string with only unique characters" << endl;
	else
		cout << str2 + " is a string with duplicated characters" << endl;

	return 0;
}
