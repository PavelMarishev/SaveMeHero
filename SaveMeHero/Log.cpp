#include "Log.h"

Log::Log()
{
	arr.push_back(-1);
}

void Log::add(int x, int y) {
	int h = 6, w = 12;
	for (int i = 0; i <= h; i++) 
	{
		for (int j = 0; j <= w; j++)
		{
			if (x < 100 * (j + 1) && x >= 100 * j && y < 100 * (i + 1) && y >= 100*i && arr.back() != i * w + j)
				arr.push_back(i * w + j);
		}
	}
}

string Log::get() {
	string res = to_string(arr[1]);
	for (int i = 2; i < arr.size(); i++)
		res += ',' + to_string(arr[i]);
	return res;
}

void Log::clear() {
	arr.clear();
	arr.push_back(-1);
}

Log::~Log()
{
}
