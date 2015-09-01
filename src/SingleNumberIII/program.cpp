#include "../include/pre.h"

vector<int> singleNumber(vector<int>& nums)
{
    int axorb = 0;
    for (auto x : nums)
        axorb ^= x;
    auto tmp = axorb;
    int i = 0;
    for (i = 0; ; i++) {
        if (tmp & 1) break;
        tmp = tmp >> 1;
    }
    tmp = 1 << i;
    int a = 0;
    for (auto x : nums)
        if (x & tmp) a ^= x;
    return {a, axorb^a};
}

int main()
{
    vector<int> test = {0, 0, 1, 2, };
    auto rst = singleNumber(test);
    for (auto x : rst) cout << x << "," << endl;
    return 0;
}
