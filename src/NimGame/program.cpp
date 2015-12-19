#include "../include/pre.h"

bool canWinNim(int n) {return n & 3;}
int main()
{
    cout << canWinNim(1) << endl;
    cout << canWinNim(2) << endl;
    cout << canWinNim(3) << endl;
    cout << canWinNim(4) << endl;
    cout << canWinNim(5) << endl;
    return 0;
}