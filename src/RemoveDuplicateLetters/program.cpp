#include "../include/pre.h"

string removeDuplicateLetters(string s)
{
    std::array<int, 26> numsOfAlpha {};
    auto end = std::unique(s.begin(), s.end());
    s = string{s.begin(), end};
    string rst;
    for (auto ch : s) numsOfAlpha[ch - 'a'] += 1;
    vector<int> alphaRemains(s.size());
    for (size_t i = 0 ; i != s.size(); i++)
        alphaRemains[i] = --numsOfAlpha[s[i] - 'a'];
    int off = -1;
    int min_off = 0;
    while (++off < s.size())
    {
        if (numsOfAlpha[s[off] - 'a'] == -1)  continue;
        min_off = s[off] < s[min_off] ? off : min_off;
        if (alphaRemains[off] == 0)
        {
            rst += s[min_off];
            numsOfAlpha[s[min_off] - 'a'] = -1;
            while (numsOfAlpha[s[min_off] - 'a'] == -1) min_off++;
            off = min_off - 1;
        }
    }
    return rst;
}

int main()
{
    cout << removeDuplicateLetters("bddbccd") << endl;
    return 0;
}