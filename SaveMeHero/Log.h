#pragma once
#include <string>

using namespace std;

class Log
{
	int arr[100];
	int index;
public:
	Log();
	void add(int x, int y);
	string get();
	void clear();
	~Log();
};

