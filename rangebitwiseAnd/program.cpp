#include <iostream>
#include <cstdio>
using namespace std;

void DisplayBinary(int num)
{
	for (int i = (sizeof(int) * 8 - 1); i >= 0; i--)
	{
		int tmp = num & (1 << i);
		if (tmp != 0) 
			cout << 1;
		else 
			cout << 0;
	}
	cout << endl;
}

int rangeBitwiseAndStupid(int m, int n) 
{
	int result = m;
	for (; m <= n; m++)
	{
		result = result & m;
	}
	return result;
}

int rangeBitwiseAnd(int m, int n) 
{
	//int diff = n - m;
	//int result = m;
	for (int i = (sizeof(int) * 8 - 1); i >= 0; i--)
	{
		//cout << "HAHA:", DisplayBinary((m & (1 << i)));
		if ((m & (1 << i)) == 0)
			continue;
		//int tmp = m & ((1 << (i + 1)) - 1);
		//cout << " TMP:", DisplayBinary(tmp);
		//int var = (1 << (i + 1)) - tmp;
		//cout << " VAR:", DisplayBinary(var);
		if (n - m >= (1 << (i + 1)) - (m & ((1 << (i + 1)) - 1)))
		{
			return (-1 << (i + 1)) & m;
			break;
		}
	}
	//return result;
}

#define TEST_VAR 80,90
int main()
{
	cout << "TRUE:" << rangeBitwiseAndStupid(TEST_VAR) << endl;
	int tmp = rangeBitwiseAnd(TEST_VAR);
	cout << tmp << "\nBIN :";
	DisplayBinary(tmp);
	//cout << ((1 << (sizeof(int) * 8) - 1)) << endl;
	//DisplayBinary(-1 << 31);
	return 0;
}