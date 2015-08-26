/*******************************************
 * 2015-04-30
 * 121 ms
 *******************************************/

#include <iostream>
using namespace std;

int count(int n)
{
	int count = 0;
	int* map = new int[n + 1];
	for (int i = 0; i != n + 1; i++)
		map[i] = 1;
	map[0] = 0, map[1] = 0;
	for (int i = 2; i != n; i++)
	{
		if (map[i] == 0)
			continue;
		++count;
		for (int j = 2; j <= (int)(n / i); j++)
		{
			map[i * j] = 0;
		}
	}
	delete[] map;
	return count;
}

int main()
{
	cout << count(13) << endl;
	cout << "Hello World" << endl;
}