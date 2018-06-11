#pragma once
#include <string>
#include <vector>

using namespace std;

class Log
{
	vector<int> arr;	
public:
	Log();
	void add(int x, int y);
	string get();
	void clear();
	~Log();
};

