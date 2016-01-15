/**************************************************************
 * Author	: Robin Liu
 * Date		: 2015-05-01
 * Detail 	: https://leetcode.com/submissions/detail/26718392/
 **************************************************************/
#include "../include/pre.h"
#include <vector>
#include <iterator>
using std::vector;

#define MAX(a, b) ((a > b)?a:b)

int * got;
int robN(vector<int>& nums, int n)
{
	if (n == 1)
		return nums[0];
	if (n == 2)
		return MAX(nums[0], nums[1]);
	if (got[n - 1] == -1)
		got[n - 1] = MAX(robN(nums, n - 2) + nums[n - 1], robN(nums, n - 1));
	return got[n - 1];
}
int rob(vector<int>& nums)
{
	got = new int[nums.size()];
	for (int i = 0; i != nums.size(); i++)
	{
		got[i] = -1;
	}
	int val = robN(nums, nums.size());
	delete[] got;
	return val;
}

int rob_(vector<int>& nums)
{
    if (nums.size() == 0) return 0;
    int Rn = nums[0];
    int Rn_ = 0;
    for (int i = 1; i != nums.size(); i++) {
        int tmp = Rn;
        Rn = std::max(Rn_ + nums[i], Rn);
        Rn_ = std::max(Rn_, tmp);
    }
    return std::max(Rn, Rn_);
}

int Mymain()
{
	TIC
	vector<int> test = {7,0,8,0,0,1};
	cout << rob_(test) << endl;
	test = {1,3,1};
	cout << rob_(test) << endl;
	test = {5,9,3,4,8,3,5,7,9,3,4,8};
	cout << rob_(test) << endl;
	test = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
	cout << rob_(test) << endl;
	TOC
	return 0;
}
