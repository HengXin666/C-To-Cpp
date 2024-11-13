#include <sstream>
#include <iostream>

using namespace std;

void stringstream_01(void)
{
	/*
	ostringstream o_str_obj("hello");
	char c_str[64];
	o_str_obj >> c_str; // Ö»ÄÜÐ´Èë <<
	*/

	stringstream s_str_obj("hello");
	cout << "0: " << s_str_obj.str() <<endl;

	s_str_obj << 'a';
	cout << "1: " << s_str_obj.str() << endl;

	s_str_obj.put('b');
	cout << "2: " << s_str_obj.str() << endl;

	s_str_obj << "str";
	cout << "3: " << s_str_obj.str() << endl;

	s_str_obj.str("c");
	cout << "4: " << s_str_obj.str() << endl;

	s_str_obj << "gg";
	cout << "5: " << s_str_obj.str() << endl;
}