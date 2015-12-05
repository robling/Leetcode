#include "../include/pre.h"

int currentMinStack;

void numSquaresHelper(int n , int pastCount)
{
    if (pastCount == currentMinStack) return;
    if (n == 0) {
        currentMinStack = pastCount;
        return;
    }
    for (int i = static_cast<int>(std::sqrt(n)); i != 0; i--) {
        numSquaresHelper(n - i * i, pastCount + 1);
    }
}

int numSquares(int n)
{
    currentMinStack = n;
    numSquaresHelper(n, 0);
    return currentMinStack;
}

int main()
{
    cout << endl << numSquares(247) << endl;
    return 0;
}