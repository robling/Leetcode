#include "../include/pre.h"

string addStrNum(string s1, string s2)
{
    string rst;
    auto& shorter = s1.size() < s2.size() ? s1 : s2;
    auto postFixZeroSize = (s1.size() > s2.size()) ? (s1.size() - s2.size()) : (s2.size() - s1.size());
    char* postFixZeroStr = new char[postFixZeroSize + 1];
    std::memset(postFixZeroStr, '0', postFixZeroSize);
    postFixZeroStr[postFixZeroSize] = 0;
    shorter = postFixZeroStr + shorter;
    delete[] postFixZeroStr;
    bool carry = false;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        int sum = s1[i] + s2[i] - '0' - '0' + (carry ? 1 : 0);
        carry = (sum > 9);
        sum -= (carry ? 10 : 0);
        rst.push_back(sum + '0');
    }
    if (carry) rst.push_back('1');
    std::reverse(rst.begin(), rst.end());
    return rst;
}

bool checkAdditive(string residue, string s1, string s2)
{
    if (residue.size() == 0) return true;
    auto sum = addStrNum(s1, s2);
    if (residue.size() < sum.size()) return false;
    for (int i = 0; i != sum.size(); i++)
    {
        if (residue[i] != sum[i]) return false;
    }
    return checkAdditive(residue.substr(sum.size()), s2, sum);
    
}
bool isAdditiveNumber(string num)
{
    int numLength = num.size();
    int maxS1Length = (numLength - 1) / 2;
    
    for (auto i = maxS1Length; i != 0; i--)
    {
        for (int j = std::min(maxS1Length, numLength - i - i); j != 0; j--)
        {
            if (checkAdditive(num.substr(i + j), num.substr(0, i), num.substr(i, j))) return true;
        }
    }
    return false;
}
    
int main()
{
    //auto r = addStrNum("0", "423043283457326");
    //auto r = checkAdditive("203959098", "1", "19"); //false
    //auto r = isAdditiveNumber("11920395998"); //true
    auto r = isAdditiveNumber("119203959098"); //false
    cout << endl << r;
    return 0;
}