// problem 1.5
// Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become
// a2blc5a3. If the "compressed" string would not become smaller than the orig-
// inal string, your method should return the original string.
// 
// Filename:     compress_string.cxx
// Author:       codelove@github
// Date:         2013-04-26

#include <string>
#include <iostream>
#include <sstream>

std::string compress_string(std::string str)
{
	using namespace std;

	string new_str = "";

    char prev = '\0';

	int count = 0;

	for ( string::iterator iter = str.begin(); iter != str.end(); ++iter )
	{
		if ( *iter == prev )
			count++;
		else
		{
			if ( count > 0 )
			{
				new_str.push_back(prev);
				stringstream ss;
				ss << count;
				new_str.append(ss.str());
			}

			count = 1;
			prev = *iter;
		}
	}

	// handle the last alphabet subsequence
	if ( count > 0 )
	{
		new_str.push_back(prev);
		stringstream ss;
		ss << count;
		new_str.append(ss.str());
	}

	if ( new_str.length() < str.length() )
		return new_str;
	else
		return str;
}

int main(int argc, char* argv[])
{
	using namespace std;
	string str("aabcccccaaa");
	cout << str << endl;
	cout << compress_string(str) << endl;

	string str2("abcdefgh");
	cout << str2 << endl;
	cout << compress_string(str2) << endl;
}
