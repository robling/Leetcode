#include "../include/pre.h"

//组合逻辑，学过数字电路的应该很熟悉
/*
 * a | b | d    =>   a | b
 * 0   0   1    =>   1   0
 * 0   0   0    =>   0   0
 * 1   0   1    =>   1   1
 * 1   0   0    =>   1   0
 * 1   1   1    =>   0   0
 * 1   1   0    =>   1   1
 */

int singleNumber(vector<int>& nums)
{
    int a = 0;
    int b = 0;
    for (auto d : nums) {
        int a0 = (a | b | d) & (~(a & b & d));
        b = a & (b ^ d);
        a = a0;
    }
    return a;
}

int main()
{
    vector<int> test {1, 2, 3, 1, 2, 4, 3, 5, 5, 1, 2, 3, 5, };
    cout << singleNumber(test) << endl;
    return 0;
}
