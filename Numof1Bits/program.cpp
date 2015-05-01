/**************************************************************
 * Author	: Robin Liu
 * Date		: 2015-05-01
 * Detail 	: https://leetcode.com/submissions/detail/26697057/
 **************************************************************/
#include "..\include\pre.h"
#include <cstdint>

#include <vector>
using std::vector;

#define LENGTH_OF_INT32 sizeof(int) * 8
int hammingWeight(uint32_t n)
{
	int count = 0;
	for (int i = 0; i != LENGTH_OF_INT32; i++)
	{
		if (n % 2 == 1)
			count += 1;
		n = n >> 1;
	}
	return count;
}
#undef LENGTH_OF_INT32

void Mymain()
{
	vector<int> testData = {1, 2, 3, 23, 45, 67};
	for (int i : testData)
	{
		cout << "NUM :" << i << endl;
		cout << "BIN :";
		PrintToBinary<uint32_t>(i);
		cout << "WET :" << hammingWeight(i) << endl << "=====" << endl;
	}
	system("pause");
}