#include "../include/pre.h"

int addDigits(int num)
{
    if (num == 0) return 0;
    return num % 9 == 0 ? 9 : num % 9;
}
    
int main()
{
    cout << addDigits(0) << endl;
    cout << addDigits(89) << endl;
    cout << addDigits(45) << endl;
    cout << addDigits(1) << endl;
    return 0;
}