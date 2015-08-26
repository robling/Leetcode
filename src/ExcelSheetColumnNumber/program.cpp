#include "../include/prevector.h"

const int SCALE = 26;
int titleToNumber(string s)
{
    int rst = 0;
    int mul = 1;
    std::for_each(s.rbegin(), s.rend(), [&](char ch)
    {
        rst += (ch - 'A' + 1) * mul;
        mul *= SCALE;
    });
    return rst;
}

int Mymain()
{
    string tests[] = {
        "AA",
        "AB",
        "AAA",
        "G",
        "DFSAGS",
    };
    for (const auto& s : tests)
    {
        cout << s << " :\t" << titleToNumber(s) << endl;
    }
}
