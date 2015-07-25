#include "../include/prevector.h"

bool isPowerOfTwo(int n)
{
    return n <= 0 ? false : 0 == (n & (n - 1));
}

int Mymain()
{
    vector<int> nums = {0, 1, 65536, 93728, 32, 999, -3893};
    cout << std::boolalpha;
    for (int i : nums){
        cout << i << ": \t" << isPowerOfTwo(i) << endl;
    }
}
