#include "../include/pre.h"

int trailingZeroes(int n)
{
    return n / 5 + ((n != 0) ? trailingZeroes(n / 5) : 0);
}

int main()
{
    vector<int> tests = {
        1, 2, 3, 4, 5, 10, 25
    };
    for (auto i : tests) {
        cout << i << ":\t" << trailingZeroes(i) << std::endl;
    }
    return 0;
}
