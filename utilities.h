#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using std::string;
using namespace std;

string read_string(string prompt);
int read_integer(const string &prompt = "");
int read_integer_in_range(string prompt, int min, int max);
double read_double(const char* prompt);
void show_menu();
string get_bar(int value, int max = 100, int length = 10);


#endif