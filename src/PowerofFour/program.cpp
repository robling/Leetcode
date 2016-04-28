#include "../include/pre.h"

bool isPowerOfFour(int num)
{
    if (num <= 0) return false; //no more than 0
    if (0 != ((num - 1) & num)) return false; //not 2^k
    //4^k % 3 = (1 + 3)*4^(k-1) % 3 = 4^(k-1) % 3
    //  4^k ≡ 4(mod 3)
    //and, 2 * 4^k ≡ 8(mod 3)
    return 1 == (num % 3);
}
int main()
{
    return 0;
}