#include "../include/pre.h"

double myPow(double x, int n)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n < 0) x = 1 / x, n = -n;
    return myPow(x * x, n / 2) * ((n % 2) ? x : 1);
}

int main()
{
    cout << myPow(4, -1) << endl;
    return 0;
}
