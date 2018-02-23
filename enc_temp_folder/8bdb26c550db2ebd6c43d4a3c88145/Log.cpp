#include "Log.h"

Log::Log()
{
	index = 0;
	arr[0] = 0;
}

void Log::add(int x, int y) {
	/*
	if (((x < 100) && (y < 100)) && (arr[index] != 1))
		arr[++index] = 1;
	else if (((x < 200) && (x >= 100)) && ((y < 100) && (arr[index] != 2)))
		arr[++index] = 2;
	else if (((x < 300) && (x >= 200)) && ((y < 100) && (arr[index] != 3)))
		arr[++index] = 3;
	else if (((x < 400) && (x >= 300)) && ((y < 100) && (arr[index] != 4)))
		arr[++index] = 4;
	else if (((x < 500) && (x >= 400)) && ((y < 100) && (arr[index] != 5)))
		arr[++index] = 5;
	else if (((x < 600) && (x >= 500)) && ((y < 100) && (arr[index] != 6)))
		arr[++index] = 6;
	else if (((x < 700) && (x >= 600)) && ((y < 100) && (arr[index] != 7)))
		arr[++index] = 7;
	else if (((x < 800) && (x >= 700)) && ((y < 100) && (arr[index] != 8)))
		arr[++index] = 8;

	if (((x < 100) && ((y < 200)&&(y >= 100)) ) && (arr[index] != 9))
		arr[++index] = 9;
	else if (((x < 200) && (x >= 100)) && (((y < 200) && (y >= 100)) && (arr[index] != 10)))
		arr[++index] = 10;
	else if (((x < 300) && (x >= 200)) && (((y < 200) && (y >= 100)) && (arr[index] != 11)))
		arr[++index] = 11;
	else if (((x < 400) && (x >= 300)) && (((y < 200) && (y >= 100)) && (arr[index] != 12)))
		arr[++index] = 12;
	else if (((x < 500) && (x >= 400)) && (((y < 200) && (y >= 100)) && (arr[index] != 13)))
		arr[++index] = 13;
	else if (((x < 600) && (x >= 500)) && (((y < 200) && (y >= 100)) && (arr[index] != 14)))
		arr[++index] = 14;
	else if (((x < 700) && (x >= 600)) && (((y < 200) && (y >= 100)) && (arr[index] != 15)))
		arr[++index] = 15;
	else if (((x < 800) && (x >= 700)) && (((y < 200) && (y >= 100)) && (arr[index] != 16)))
		arr[++index] = 16;

	if (((x < 100) && ((y < 300) && (y >= 200))) && (arr[index] != 17))
		arr[++index] = 17;
	else if (((x < 200) && (x >= 100)) && (((y < 300) && (y >= 200)) && (arr[index] != 18)))
		arr[++index] = 18;
	else if (((x < 300) && (x >= 200)) && (((y < 300) && (y >= 200)) && (arr[index] != 19)))
		arr[++index] = 19;
	else if (((x < 400) && (x >= 300)) && (((y < 300) && (y >= 200)) && (arr[index] != 20)))
		arr[++index] = 20;
	else if (((x < 500) && (x >= 400)) && (((y < 300) && (y >= 200)) && (arr[index] != 21)))
		arr[++index] = 21;
	else if (((x < 600) && (x >= 500)) && (((y < 300) && (y >= 200)) && (arr[index] != 22)))
		arr[++index] = 22;
	else if (((x < 700) && (x >= 600)) && (((y < 300) && (y >= 200)) && (arr[index] != 23)))
		arr[++index] = 23;
	else if (((x < 800) && (x >= 700)) && (((y < 300) && (y >= 200)) && (arr[index] != 24)))
		arr[++index] = 24;

	if (((x < 100) && ((y < 400) && (y >= 300))) && (arr[index] != 25))
		arr[++index] = 25;
	else if (((x < 200) && (x >= 100)) && (((y < 400) && (y >= 300)) && (arr[index] != 26)))
		arr[++index] = 26;
	else if (((x < 300) && (x >= 200)) && (((y < 400) && (y >= 300)) && (arr[index] != 27)))
		arr[++index] = 27;
	else if (((x < 400) && (x >= 300)) && (((y < 400) && (y >= 300)) && (arr[index] != 28)))
		arr[++index] = 28;
	else if (((x < 500) && (x >= 400)) && (((y < 400) && (y >= 300)) && (arr[index] != 29)))
		arr[++index] = 29;
	else if (((x < 600) && (x >= 500)) && (((y < 400) && (y >= 300)) && (arr[index] != 30)))
		arr[++index] = 30;
	else if (((x < 700) && (x >= 600)) && (((y < 400) && (y >= 300)) && (arr[index] != 31)))
		arr[++index] = 31;
	else if (((x < 800) && (x >= 700)) && (((y < 400) && (y >= 300)) && (arr[index] != 32)))
		arr[++index] = 32;

	if (((x < 100) && ((y < 500) && (y >= 400))) && (arr[index] != 33))
		arr[++index] = 33;
	else if (((x < 200) && (x >= 100)) && (((y < 500) && (y >= 400)) && (arr[index] != 34)))
		arr[++index] = 34;
	else if (((x < 300) && (x >= 200)) && (((y < 500) && (y >= 400)) && (arr[index] != 35)))
		arr[++index] = 35;
	else if (((x < 400) && (x >= 300)) && (((y < 500) && (y >= 400)) && (arr[index] != 36)))
		arr[++index] = 36;
	else if (((x < 500) && (x >= 400)) && (((y < 500) && (y >= 400)) && (arr[index] != 37)))
		arr[++index] = 37;
	else if (((x < 600) && (x >= 500)) && (((y < 500) && (y >= 400)) && (arr[index] != 38)))
		arr[++index] = 38;
	else if (((x < 700) && (x >= 600)) && (((y < 500) && (y >= 400)) && (arr[index] != 39)))
		arr[++index] = 39;
	else if (((x < 800) && (x >= 700)) && (((y < 500) && (y >= 400)) && (arr[index] != 40)))
		arr[++index] = 40;

	if (((x < 100) && ((y < 600) && (y >= 500))) && (arr[index] != 41))
		arr[++index] = 41;
	else if (((x < 200) && (x >= 100)) && (((y < 600) && (y >= 500)) && (arr[index] != 42)))
		arr[++index] = 42;
	else if (((x < 300) && (x >= 200)) && (((y < 600) && (y >= 500)) && (arr[index] != 43)))
		arr[++index] = 43;
	else if (((x < 400) && (x >= 300)) && (((y < 600) && (y >= 500)) && (arr[index] != 44)))
		arr[++index] = 44;
	else if (((x < 500) && (x >= 400)) && (((y < 600) && (y >= 500)) && (arr[index] != 45)))
		arr[++index] = 45;
	else if (((x < 600) && (x >= 500)) && (((y < 600) && (y >= 500)) && (arr[index] != 46)))
		arr[++index] = 46;
	else if (((x < 700) && (x >= 600)) && (((y < 600) && (y >= 500)) && (arr[index] != 47)))
		arr[++index] = 47;
	else if (((x < 800) && (x >= 700)) && (((y < 600) && (y >= 500)) && (arr[index] != 48)))
		arr[++index] = 48;
		*/
	int h = 6, w = 8;
	for (int i = 1; i <= h; i++) 
	{
		for (int j = 1; j <= w; j++)
		{
			if (((x < (100 * j)) && (x >= (100 * (j-1)))) && (((y < (100*i)) && (y >= (100*(i-1)))) && (arr[index] != ((i-1)*w)+j)))
				arr[++index] = ((i - 1)*w) + j;
		}
	}
}

string Log::get() {
	string res = to_string(arr[1]);
	for (int i = 2; i < index + 1; i++)
		res += ',' + to_string(arr[i]);
	return res;
}

void Log::clear() {
	index = 0;
	arr[0] = 0;
}

Log::~Log()
{
}
