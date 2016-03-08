#include "../include/pre.h"

string convert(string s, int numRows)
{
    int T = numRows * 2 - 2;
    if (T == 0) return s;
    vector<string> rst_s(numRows, string());
    for (int i = 0; i != s.size(); i++)
    {
        rst_s[i % T / numRows ? numRows - 1 - (i % T - numRows + 1) : i % T].push_back(s[i]);
    }
    string rst("");
    for (auto& si : rst_s) rst += si;
    return rst;
}

int main()
{
    cout << convert(string("A"), 1) << endl;
    return 0;
}