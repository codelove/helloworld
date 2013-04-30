// problem 1.8
// Assume you have a method isSubstring which checks if one word is a
// substring of another. Given two strings, si and s2, write code to check if s2 is
// a rotation of si using only one call to isSubstring (e.g.,"waterbottle"is a rota-
// tion of "erbottlewat").
// 
// Filename:     compress_string.cxx
// Author:       codelove@github
// Date:         2013-04-26

#include <iostream>
#include <string>

// check whether str1 is a substring of str2
bool isSubString(std::string str1, std::string str2)
{
	int pos = str2.find(str1);

	if ( pos==std::string::npos ) 
		return false;
	else
		return true;
}

bool isStringRotation(std::string str1, std::string str2)
{
	if ( str1.length() != str2.length() )
		return false;

	str1 += str1;
	if ( isSubString(str2, str1) )
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{
	std::string str1("waterbottle");
	std::string str2("erbottlewat");
	std::string str3("erbottlewai");
	std::string str4("waterbottle1");

	if (isStringRotation(str1, str2))
		std::cout << str1 << " and " << str2 << " are rotated sequences.\n";
	else
		std::cout << str1 << " and " << str2 << " are not rotated sequences.\n";

	if (isStringRotation(str1, str3))
		std::cout << str1 << " and " << str3 << " are rotated sequences.\n";
	else
		std::cout << str1 << " and " << str3 << " are not rotated sequences.\n";

	if (isStringRotation(str1, str4))
		std::cout << str1 << " and " << str4 << " are rotated sequences.\n";
	else
		std::cout << str1 << " and " << str4 << " are not rotated sequences.\n";

	return 0;
}
