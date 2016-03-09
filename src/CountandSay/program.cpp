#include "../include/pre.h"

string countAndSayHelper(const string& s)
{
    std::stringstream ss;
    char curCh = 0;
    int curStack = 0;
    for (auto ch : s)
    {
        if (ch != curCh)
        {
            if (curStack >= 1) ss << curStack << curCh;
            curCh = ch;
            curStack = 1;
        }
        else
        {
            curStack++;
        }
    }
    if (curStack >= 1) ss << curStack << curCh;
    else if (curStack == 1) ss << curCh;
    return ss.str();
}

string countAndSay(int n)
{
    string rst("1");
    while(--n)
    {
        rst = countAndSayHelper(rst);
    }
    return rst;
}

int main()
{
    int i = 0;
    while(++i != 10)
    {
        cout << i << "\t:   " << countAndSay(i) << endl;
    }
    return 0;
}