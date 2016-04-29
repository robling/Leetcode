#include "../include/pre.h"

vector<int> countBits(int num)
{
    if (num == 0) return {0};
    vector<int> rst = {0, 1};
    int i = 1;
    int power = 1;
    cout << 0 << ", ";
    cout << 0 << ", ";
    while (i++ != num)
    {
        auto o = i - (1 << power);
        o = o == (1 << power) ? power++, 0 : o;
        cout << o << ", ";
        rst.push_back(rst[o] + 1);
    }
    cout << endl;
    return rst;
}
int main()
{
    cout << countBits(1) << endl;
    return 0;
}