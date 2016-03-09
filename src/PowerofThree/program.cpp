#include "../include/pre.h"

template<int baseNum, int n, bool lessThan = true>
struct maxPoweredNumUnder{
    static const int value = baseNum * maxPoweredNumUnder<baseNum, n / baseNum, (n / baseNum > baseNum)>::value;
};
template<int baseNum>
struct maxPoweredNumUnder<baseNum, 1, true>{
    static const int value = 1;
};
template<int baseNum, int n>
struct maxPoweredNumUnder<baseNum, n, false>{
    static const int value = 1;
};

constexpr int M = maxPoweredNumUnder<3, std::numeric_limits<int>::max()>::value;

bool isPowerOfThree(int n)
{
    if (n <= 0) return false;
    return M % n == 0;
}
int main()
{
    cout << M << endl;
    cout << isPowerOfThree(9);
    return 0;
}