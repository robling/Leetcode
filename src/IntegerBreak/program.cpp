#include "../include/pre.h"

int integerBreak(int n)
{
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    n++;
    return (n % 3 + 2) * std::pow(3, (n / 3 - 1));
}
int main()
{
    return 0;
}